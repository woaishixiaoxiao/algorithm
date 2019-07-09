#include<iostream>
#include<vector>
#include<string> 
using namespace std;
void getDp(string &str,vector<vector<int> >&dp){
	int len=str.size();
	if(!len)return ;
	dp.resize(len);
	for(int i=0;i<len;i++){
		dp[i].resize(len);
	}
	dp[0][0]=0;
	for(int j=1;j<len;j++){
		dp[j][j]=0;
		dp[j-1][j]=str[j]==str[j-1]?0:1;
		for(int i=j-2;i>=0;i--){
			if(str[i]==str[j]){
				dp[i][j]=dp[i+1][j-1];
			}else{
				int temp1=dp[i+1][j];
				int temp2=dp[i][j-1];
				dp[i][j]=temp1<temp2?temp1:temp2;
				dp[i][j]+=1;
			}
		}
	}
} 
void RecuOnValue(string &res,string &s,vector<vector<int> >&dp,int i,int j,int m,int n){
	if(i>j)return;
	if(s[i]==s[j]){
		res[m]=res[n]=s[i];
		RecuOnValue(res,s,dp,i+1,j-1,m+1,n-1);
	}else{
		if(s[i]!=s[j]){
			if(dp[i+1][j]>dp[i][j-1]){
				res[m]=res[n]=s[j];
				RecuOnValue(res,s,dp,i,j-1,m+1,n-1);
			}else{
				res[m]=res[n]=s[i];
				RecuOnValue(res,s,dp,i+1,j,m+1,n-1);
			}
		}
	}
}
string GetValue(string &s,vector<vector<int> >&dp){
	if(s.size()==1||s.empty())return s;
	int len=dp.size();
	string res;
	int strLen=dp[0][len-1]+s.size();
	res.resize(strLen);
	RecuOnValue(res,s,dp,0,len-1,0,strLen-1);
	return res;	
}
main(){
	string str="ADEFC";
	vector<vector<int> >dp;
	getDp(str,dp);
	cout<<GetValue(str,dp);
}
//分析当i,j距离<=1的时候两个值都是可以求出来的，当位置i,j差的距离大于2的时候，dp[i][j]=min{dp[i+1][j],dp[i][j-1]}+1, 
//最后希望求的值是dp[0][len]，因为dp[j][j]和dp[j-1][j]可以求的出来，所以从J=1开始求，那么dp[i][j-1]是可以求的出来的，
//从j-2开始往后求，dp[i+1][j]也是可以求的出来的。 
