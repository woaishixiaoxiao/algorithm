#include<iostream>
#include<vector>
using namespace std;
main(){
	int n=8;
	vector<int>ivec={1,2,3,4};
	int count=0; 
	int dp[n+1][n+1];//dp[i][j]代表从第i个数到第j个数的和dp[i][j]=dp[i][j-1]+ivec[j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i==j){
				dp[i][j]=ivec[i-1];
			}else{
				dp[i][j]=ivec[j-1]+dp[i][j-1];
			}
			if(dp[i][j]<=n){
				count++;
			}
		}
	}
	cout<<count;
}
