//����������������arr1,��arr2���ڸ���һ������K����������������������е�KС����
//���������������һ�ǵ�K<=min_len��ʱ�򣬶��ǵ�K>min_len&&k<=max_len,���k>max_len
//��һ��������Ǻ�������λ����һ���ģ�������������ǣ�Ҫ�ж����������������������������������Ϊ������ж���������
//��������жϵĻ���������λ������������Ҫ���Kλ�õ����������������һ������ʱ��Ҳ����ȷ��
//�ڶ���������ж�һ��������Ϊ����������� 
#include<iostream>
#include<vector>
using namespace std;
int onGetKNum(vector<vector<int> >&ivec,int min_pos,int beg1,int end1,int max_pos,int beg2,int end2){
	int beg[2]={beg1,beg2};
	int end[2]={end1,end2};
	int mid[2];
	mid[0]=(beg[0]+end[0])/2;
	mid[1]=(beg[1]+end[1])/2;
	int res;
	while((beg[0]<end[0])&&(beg[1]<end[1])){
		if(ivec[min_pos][mid[0]]==ivec[max_pos][mid[1]]){
			return ivec[min_pos][mid[0]];
		}else{
			int offset=(end[0]-beg[0]+1)%2==0?1:0;
			int pos;
			if(ivec[min_pos][mid[0]]>ivec[max_pos][mid[1]]){
				pos=min_pos;
			}else{
				pos=max_pos;
			}
			end[pos]=mid[pos];
			beg[1-pos]=mid[1-pos]+offset;
		}
	}
	return ivec[0][beg[0]]>ivec[1][beg[1]]?ivec[1][beg[1]]:ivec[0][beg[0]];
}
bool getKNum(vector<vector<int> >&ivec,int k,int &res){
	int len1=ivec[0].size();
	int len2=ivec[1].size();
	int min_pos=len1>len2?1:0;
	int max_pos=len1>len2?0:1;
	if(k<1||k>(len1+len2))return false;
	if((len1+len2)==1){
		if(len1==1)res=ivec[0][0];
		else{
			ivec[1][0];
		}
		return true;
	}
	int min_sz=ivec[min_pos].size();
	int max_sz=ivec[max_pos].size();
	if(k<=min_sz){
		res=onGetKNum(ivec,min_pos,0,k-1,max_pos,0,k-1);
	}else{
		if(k>min_sz&&k<=max_sz){
			int sz=ivec[min_pos].size();
			int pos=k-sz;
			if(ivec[max_pos][pos-1]>=ivec[min_pos][sz-1]){
				res=ivec[max_pos][pos-1];
				return true;
			}
			res=onGetKNum(ivec,min_pos,0,sz-1,max_pos,pos,k-1);
		}else{
			int sz_min=ivec[min_pos].size();
			int sz_max=ivec[max_pos].size();
			int beg_min=k-sz_max;
			int beg_max=k-sz_min;
			if(ivec[min_pos][beg_min-1]>=ivec[max_pos][sz_max-1]){
				res=ivec[min_pos][beg_min-1];
				return true;
			}
			if(ivec[max_pos][beg_max-1]>=ivec[min_pos][sz_min-1]){
				res=ivec[max_pos][beg_max-1];
				return true;
			}
			res=onGetKNum(ivec,min_pos,beg_min,sz_min-1,max_pos,beg_max,sz_max-1);
		}
	}
	return true;
}
main(){
	vector<int>ivec1={5,8,10};
	vector<int>ivec2={19,30,32,33};
	vector<vector<int> >vec;
	vec.push_back(ivec1);
	vec.push_back(ivec2);
	int res;
	if(getKNum(vec,7,res)){
		cout<<res<<endl;
	}
}
