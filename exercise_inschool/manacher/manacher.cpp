//manacher算法是解决求最长回文串长度的问题，也就是给定一个字符串，求字符串的最大回文串的长度 
//如果不进行优化的话，时间复杂度就是n2 
//当进行优化的时候，前面的计算结果会对后面计算结果进行优化的从而达到O（N）的时间复杂度
//优化第一步是在每个字符中间添加上一个任意字符（我们添加'#'），这样做的目的是将所有字符串都处理为奇数长度，
//因为当字符串为偶数的时候，进行扩的时候（所谓扩就是以这个字符为中心，求解此字符为中心的最大回文子串长度）
//会出问题的，可以动手画画就知道了 ，真实的值为得出的结果/2 
//第二部：需要三个变量，一个是pArr数组，代表是以i为中心的回文半径（算上中间那个数），pr代表每次进行扩的时候最右边的
//下一个字符，与之相对应的是一个叫做Index的下标，这个代表当前回文中心的位置（pr与index是相对应的）
//分四种情况，
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void enLarge(int i,int j,int &index,int &pr,vector<int>&pArr,int &max_len,int &max_pos,string &str,int pos){
	while((i<str.size())&&(j>=0)){
		if(str[i]==str[j]){
			i++;
			j--;
		}else{
			break;
		}
	}
	index=pos;
	pr=i;
	pArr[pos]=pr-index;
	if(max_len<pArr[pos]){
		max_len=pArr[pos];
		max_pos=pos;
	}
}
void preDeal(string &str){
	string temp=str;
	str.clear();
	/*for(int i=0;i<str.size();i++){//这个样子写是有问题的因为str目前为空 
		str+='#';
		str+=temp[i];
	}*/
	for(int i=0;i<temp.size();i++){
		str+='#';
		str+=temp[i];
	}
	str+='#'; 
}
int Manacher(string &str){
	preDeal(str);
	vector<int>pArr;
	pArr.resize(str.size());//如果知道大小最好一开始就分配好大小 
	pArr[0]=1; 
	int pr=1;
	int index=0;
	int pos=1;
	int max_pos=0;
	int max_len=0;
	while(pos<str.size()){
		if(pos>pr-1){
			int i=pos+1;
			int j=pos-1;
			enLarge(i,j,index,pr,pArr,max_len,max_pos,str,pos);
		}else{
			int mirror_pos=2*index-pos;
			int mirrorPos_left=mirror_pos-pArr[mirror_pos]+1;
			int mirrorIndex_left=index-pArr[index]+1;
			if(mirrorPos_left!=mirrorIndex_left){
				pArr[pos]=pArr[mirrorPos_left];
			}else{
				int pos_left=pos-(pr-1-pos);
				int i=pr;
				int j=pos_left-1;
				enLarge(i,j,index,pr,pArr,max_len,max_pos,str,pos);
			}
		}
		if(pr==str.size()){//只要pr能到最外边了，那么说明就应该跳出去了，后面的不可能比这个大 
			break;
		}
		pos++;		
	}
	return (max_len*2-1)/2;
} 
main(){
	string str="121ab1";
	cout<<Manacher(str);
}
