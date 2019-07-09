//����N����������N����������������еĳ��ȡ�2 5 3 4 1 7 6  �������Ϊ2 3 4 7   �������Ϊ4
//�����п��Բ��������ģ�������������Ӵ�������������
#include<iostream>
#include<vector>
using namespace std;
//��ӡ���������ӡ���������������������¼��ǰ�����ֵ��������������ȵ�ǰ�����ֵС������dp[j]=dp[max_pos]-1���У������O(n^2)�ķ��� 
void printRes(vector<int>&ivec,vector<int>&dp,int max_pos){
	int pos=max_pos-1;
	while(pos>=0){
		if((ivec[pos]<ivec[max_pos])&&(dp[pos]==dp[max_pos]-1)){
			cout<<max_pos<<" ";
			max_pos=pos;
		}
		pos--;
	}
	cout<<max_pos<<endl;
}
/*int Lis(vector<int>&ivec){
	vector<int>dp;
	int sz=ivec.size();
	dp.resize(sz);
	dp[0]=1;
	int max_pos=0;
	for(int i=1;i<sz;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(ivec[j]<ivec[i]){
				if(dp[i]<(dp[j]+1)){
					dp[i]=dp[j]+1;
				}
			}
		}
		if(dp[max_pos]<dp[i]){
			max_pos=i;
		}
	}
	printRes(ivec,dp,max_pos);
	return dp[max_pos];
}*/
//����O(N*logN),ÿ����һ��i��dp[i]����һ������help������ܼ�¼��i֮ǰ������dp����������������ظ�������͸���һ�֣��������ǵ�dp��ȵ�ʱ��arr[i]��С��������� 
//ÿ����һ��dp��ʱ���õ�ǰ��arr[i]ȥ�滻��help������С�ı��������������Ҳ�������ӵ�help�������dpΪarr[i]��help�����е�ǰ��λ��+1. 
int binSearch(vector<int>&help,int num){
	int beg=0;
	int end=help.size()-1;
	int mid;
	while(beg<end){//���ﵱbeg==end��ʱ��᷵�أ�������ֻҪend�ж�����ô���صĿ϶�����С�Ĵ���Num��������beg��Ϊ����Mid+1�����Դ�ʱbeg���������һ����<=num�ģ� 
		mid=(beg+end)/2;//���ǲ�֪��end����û�����Խ��Ҫ�ж��¡� 
		if(help[mid]<=num){
			beg=mid+1;
		}else{
			end=mid;
		}
	}
	return end; 
}
int Lis(vector<int>&ivec){//���粻��ӡ����Ļ���ֻҪά��help��������ˣ�help���һ��ֵ���ǽ���� 
	vector<int>dp;
	int sz=ivec.size();
	dp.resize(sz);
	dp[0]=1;
	vector<int>help;
	int max_pos=0; 
	help.push_back(ivec[0]);
	for(int i=1;i<sz;i++){
		int pos=binSearch(help,ivec[i]);
		if(ivec[pos]<ivec[i]){
			help.push_back(ivec[i]);
			dp[i]=help.size();
		}else{
			ivec[pos]=ivec[i];
			dp[i]=pos+1;
		}
		if(dp[i]>dp[max_pos]){
			max_pos=i;
		}
	}
	printRes(ivec,dp,max_pos);
	return dp[max_pos];
}
main(){
	vector<int>ivec={4,-1,0,2};
	cout<<Lis(ivec);
}
