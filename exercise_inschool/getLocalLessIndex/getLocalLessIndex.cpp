//����ֲ���С�ĸ��arr����Ϊ1ʱ��arr[0]�Ǿֲ���С��arr�ĳ���ΪN(N>1)ʱ�����arr[0]<arr[1]����ôarr[0]�Ǿֲ���С��
//���arr[N-1]<arr[N-2]����ôarr[N-1]�Ǿֲ���С�����0<i<N-1������arr[i]<arr[i-1]����arr[i]<arr[i+1]����ôarr[i]�Ǿֲ���С��
//������������arr����֪arr�������������ڵ���������ȣ�дһ��������ֻ�践��arr������һ���ֲ���С���ֵ�λ�ü��ɡ� 
//������Ϊʲô�ڶ������ȵ�һ����С�����һ�����ȵ����ڶ�������ô��һ������һ���ֲ���Сֵ
//��Ϊ���ڵ������ǲ���ȵģ����������������Ĺ�ϵ��������ô���������һֱ����һֱ�����Ƚ������������󽵣�
//��Ϊ�ʼ�����������������½�������󵽵����ڶ�����������Ҳ���½��������Լ�����Ҳ�ܻ���������Ҫ����
//�����۾���ֻҪ��ͷ�����ƶ����½�����ô�м����һ���������ͷ��һ�����������ģ��Ǵ𰸾�ֱ�����ˣ���������⣬һ���н� 
#include<iostream>
#include<vector>
using namespace std;
bool getLocalLessIndex(vector<int>&ivec,int &pos){
	if(ivec.empty())return false;
	int beg=0;
	int end=ivec.size()-1;
	int mid;
	if(ivec.size()==1||ivec[beg]<ivec[beg+1]){
		pos=beg;
		return true;
	}else{
		if(ivec[end]<ivec[end-1]){
			pos=end;
			return true;
		}
	}
	while(beg<end){//������治����ȥ�ж�13-20���Ǹ����ݣ���Ϊ��ֻҪȷ���˽�һ����������䷶Χ�ھͿ����ˣ����������䷶Χ��С������ 
		mid=(beg+end)/2;
		if(ivec[mid]>ivec[mid-1]){
			end=mid-1;
		}else{
			if(ivec[mid]>ivec[mid+1]){
				beg=mid+1;
			}else{
				pos=mid;
				return true;
			}
		}
	}
	return beg; //���ﷵ��ʲô������ν����Ϊ������һ���н�� 
}
main(){
	vector<int>ivec={};
	int pos;
	if(getLocalLessIndex(ivec,pos)){
		cout<<pos<<endl;
	}
} 
