//����һ������m�������Ͻǿ�ʼÿ��ֻ�����»������ұ��ߣ����ﵽ���½�λ��
//·�������������ۼ���������·���ͣ�����·����Сֵ
//��ͨ�Ķ�̬�滮���������������漰��ѹ���ռ�
#include<iostream> 
#include<vector>
using namespace std;
/*void printResRecu(vector<vector<int> >&ivec,vector<vector<int> >&dp,int i,int j){
	if(i==0&&j==0){
		return;
	}
	if(i==0){
		printResRecu(ivec,dp,i,j-1);
		cout<<"->";
	}else if(j==0){
		printResRecu(ivec,dp,i-1,j);
		cout<<"|";
	}
	else{
		int temp=dp[i][j]-ivec[i][j];
		if(temp==dp[i-1][j]){
			printResRecu(ivec,dp,i-1,j); 
			cout<<"|";
		} else{
			printResRecu(ivec,dp,i,j-1);
			cout<<"->";
		}	
	}
}
int minPathDp(vector<vector<int> >&ivec){
	int row=ivec.size();
	int col=ivec[0].size();
	vector<vector<int> >dp;
	dp.resize(row);
	for(int i=0;i<row;i++){
		dp[i].resize(col);
	} 
	dp[0][0]=ivec[0][0];
	for(int j=1;j<col;j++){
		dp[0][j]=dp[0][j-1]+ivec[0][j];
	}
	for(int i=1;i<row;i++){
		for(int j=0;j<col;j++){
			if(j==0){
				dp[i][j]=ivec[i][j]+dp[i-1][j];
			}else{
				dp[i][j]=dp[i-1][j]<dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
				dp[i][j]+=ivec[i][j];
			}
		} 
	}
	printResRecu(ivec,dp,row-1,col-1);
	return dp[row-1][col-1];
}*/
//�������ֶ�̬�滮���Դ�ӡ��������ǿռ�Ϊm*n�������Ż�Ϊ0(min{m,n}) ,���Ǵ�ӡ���˽�� 
int minPathDp(vector<vector<int> >&ivec){
	int row=ivec.size();
	int col=ivec[0].size();
	vector<int>dp;
	dp.resize(col);
	dp[0]=ivec[0][0];
	for(int i=1;i<col;i++){
		dp[i]=ivec[0][i]+dp[i-1];
	}
	for(int i=1;i<row;i++){
		for(int j=0;j<col;j++){
			if(j==0){
				dp[j]+=ivec[i][j];
			}else{
				dp[j]=dp[j]<dp[j-1]?dp[j]:dp[j-1];
				dp[j]+=ivec[i][j];
			}
		}
	}
	return dp[col-1];
}
main(){
	vector<vector<int> >ivec={{1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};
	cout<<minPathDp(ivec);
}
