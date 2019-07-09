//给定一个无序整形数组arr，找到数组中未出现的最小正整数，要求时间复杂度为0（N），额外空间复杂度O（1）
//假定数组长度为N，那么未出现的最小正整数只能是1~N，现在设置两个变量，一个是l（代表含义是在1~N中已经出现的数）,一个是r（代表含义是
//出现的可能的最小正整数范围内的最大值)，l和r也恰能代表整形数组中的下标 ，l代表左边遍历，r代表右边遍历 
//初始的时候满足l=0,r=N,之后对数组中一个任意数进行分析，最后分析特殊情况，
//如果这个数恰好是<=l，或者说>r那么这个数其实已经废掉了，所以现在能出现的最大正整数只能是r-1了，因为r还代表着右边遍历的下标，所以将右边r-1下标代表的
//数值赋予给arr[L]就好了，这个数被覆盖掉也无所谓 
//如果这个数arr[l]==l+1，那么也就意味着l++（最后数组被重新排序了，从最小的下标一直到l，是1-L，需要的最小结果就是l+1） 
//如果这个数arr[L]>l+1<=r  两种情况，arr[l]==arr[arr[l]-1]那么这两个数就是相等也就是其中一个废了，也就是和上面的处理是一样的了 ，当不相等的时候就好说了，
//把它放到它应该放的地方去 
#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int>&ivec,int i,int j){
	int temp=ivec[i];
	ivec[i]=ivec[j];
	ivec[j]=temp;
}
int missNum(vector<int>&ivec){
	int N=ivec.size();
	int l=0;
	int r=N;
	while(l<r){
		if(ivec[l]==l+1){
			l++;			
		}else if(ivec[l]<=l || ivec[l]>r || ivec[ivec[l]-1]==ivec[l]){
			ivec[l]=ivec[--r];
		}
		else{
			swap(ivec,l,ivec[l]-1);
		}
	}
	return l+1;
}
main(){
	vector<int>ivec={2,3,2,3,21,6,34};
	cout<<missNum(ivec)<<endl;
	for(auto e:ivec){
		cout<<e<<" ";
	}
	cout<<endl;
}
