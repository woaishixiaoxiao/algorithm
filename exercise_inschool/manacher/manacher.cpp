//manacher�㷨�ǽ��������Ĵ����ȵ����⣬Ҳ���Ǹ���һ���ַ��������ַ����������Ĵ��ĳ��� 
//����������Ż��Ļ���ʱ�临�ӶȾ���n2 
//�������Ż���ʱ��ǰ��ļ�������Ժ�������������Ż��ĴӶ��ﵽO��N����ʱ�临�Ӷ�
//�Ż���һ������ÿ���ַ��м������һ�������ַ����������'#'������������Ŀ���ǽ������ַ���������Ϊ�������ȣ�
//��Ϊ���ַ���Ϊż����ʱ�򣬽�������ʱ����ν������������ַ�Ϊ���ģ������ַ�Ϊ���ĵ��������Ӵ����ȣ�
//�������ģ����Զ��ֻ�����֪���� ����ʵ��ֵΪ�ó��Ľ��/2 
//�ڶ�������Ҫ����������һ����pArr���飬��������iΪ���ĵĻ��İ뾶�������м��Ǹ�������pr����ÿ�ν�������ʱ�����ұߵ�
//��һ���ַ�����֮���Ӧ����һ������Index���±꣬�������ǰ�������ĵ�λ�ã�pr��index�����Ӧ�ģ�
//�����������
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
	/*for(int i=0;i<str.size();i++){//�������д�����������ΪstrĿǰΪ�� 
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
	pArr.resize(str.size());//���֪����С���һ��ʼ�ͷ���ô�С 
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
		if(pr==str.size()){//ֻҪpr�ܵ�������ˣ���ô˵����Ӧ������ȥ�ˣ�����Ĳ����ܱ������ 
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
