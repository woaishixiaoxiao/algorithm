#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void onGetValue(string &math,vector<int>&next){
	next.push_back(-1);
	next.push_back(0);
	/*for(int i=2;i<math.size();i++){
		bool flag=false;
		for(int j=i-1;j>0;){
			int len=next[j];
			if(math[len]==math[i-1]){
				next.push_back(len+1);
				flag=true;
				break;
			}else{
				j=len;
			}
		}
		if(!flag){
			next.push_back(0);
		}
	}*/
	int cn=0;
	int pos=2;
	while(pos<math.size()){
		if(math[pos-1]==math[cn])next[pos++]=++cn;
		else if(cn>0)cn=next[cn];
		else next[pos++]=0;
	}
}
//求next[i]，如果math[i-1]是和 math[cn]（cn代表next[i-1]，也就是上一个字符的前缀和后缀的最长的长度，我们要看的是math[cn-1+1]和math[i-1]大小对比）
//如果相等那么pos往后走，也要更新cn的长度，就是++cn(不是cn++)，假如不相等，就要更新cn，但是不更新pos，可以分析出来，最后一次math[i-1]应该是和math[0]
//进行对比，cn=1的时候next[cn]=0,（不一定是i=1的时候next[i]才会为0，对于其他的i！=1，一样会有,next[i]=0），之后加入还不相等，那么pos就要更新，并且当前
//next[pos]=0 ,而恰好的是当前的cn=0，正好是当前的next[pos]
//之所以要进行这个预处理，是为了在不匹配的时候，不是滑动的长度为1。当匹配的时候当前字符不相等，那么下一个起始匹配的地方i+j-next[j]，next代表的含义是
//当前字符的上一个字符的最长前缀和后缀。i+j表示当前匹配到的不相等的下标,画图可以看出来，特殊情况的时候，当j=0的时候，也为了往后移动一个所以next[0]=-1
//当如果最长前缀和后缀的长度不相等，也就是不重叠，中间有其他的数，这些数是不可能的，用反证法可以证明，如果这些数可能的话，那么最大长度和最小长度就不是之前算出的那么多了 
bool onMath(string &str,string &math,vector<int>&next,int &pos){
	if(str.size()<math.size())return false;
	int j=0;
	for(int i=0;i<str.size();){
		for(;(j<math.size())&&(str[i+j]==math[j]);j++);
		if(j==math.size()){
			pos=i;
			return true;
		}else{
			i=i+j-next[j];
			j=next[j]>0?next[j]:0;
		}
	}
	return false;
}
//匹配的时候时间复杂度为最大为O(N),N为主串的长度，这个可以画图看一下，最主要就是不回溯，(每次会更新i的位置，以及j的位置，这两个位置使得不会回溯) 
main(){
	int pos;
	string str="1ab123123ab123";
	string math="123123";
	vector<int>next;
	onGetValue(math,next);
	for_each(next.begin(),next.end(),[](int num){cout<<num<<" ";});
	cout<<endl;
	if(onMath(str,math,next,pos)){
		cout<<pos<<endl;
	}
}
