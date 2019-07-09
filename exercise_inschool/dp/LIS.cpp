//给定N个数，求这N个数的最长上升子序列的长度。2 5 3 4 1 7 6  最长子序列为2 3 4 7   输出长度为4
//子序列可以不是连续的，但是子数组和子串必须是连续的
#include<iostream>
#include<vector>
using namespace std;
//打印结果，向后打印结果条件必须是两个，记录当前的最大值，后面最近的数比当前的最大值小，并且dp[j]=dp[max_pos]-1才行，这个是O(n^2)的方法 
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
//可以O(N*logN),每次求一个i的dp[i]。给一个数组help，如果能记录下i之前的数的dp的所有情况，至于重复的情况就给出一种，给出的是当dp相等的时候arr[i]最小的那种情况 
//每次求一个dp的时候，用当前的arr[i]去替换掉help数组最小的比他大的数，如果找不到就添加到help数组最后，dp为arr[i]在help数组中当前的位置+1. 
int binSearch(vector<int>&help,int num){
	int beg=0;
	int end=help.size()-1;
	int mid;
	while(beg<end){//这里当beg==end的时候会返回，过程中只要end有动，那么返回的肯定是最小的大于Num的数，（beg因为会用Mid+1，所以此时beg代表的数不一定是<=num的） 
		mid=(beg+end)/2;//但是不知道end动了没，所以结果要判断下。 
		if(help[mid]<=num){
			beg=mid+1;
		}else{
			end=mid;
		}
	}
	return end; 
}
int Lis(vector<int>&ivec){//假如不打印结果的话，只要维持help数组就行了，help最后一个值就是结果。 
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
