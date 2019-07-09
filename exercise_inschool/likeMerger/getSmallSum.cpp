//数组小和的定义如下：例如，数组s=[1，3，5，2，4，6]，在s[0]的左边小于或等于s[0]的数的和为0，
//在s[1]的左边小于或等于s[1]的数的和为1，在s[2]的左边小于或等于s[2]的数的和为1+3=4，在s[3]的
//左边小于或等于s[3]的数的和为1，在s[4]的左边小于或等于s[4]的数的和为1+3+2=6，在s[5]的左边小
//于或等于s[5]的数的和为1+3+5+2+4=15，所以s的小和为0+1+4+1+6+15=27。
//这道题要求用O(nlogn)时间复杂度，用的是归并排序的思想，
//为什么归并排序时间比简单排序的时间复杂度要好，最好的方法是从时间复杂度上面分析，
//直观上面看，应该是每次比较的时候，数组太长了？？？
//这道题不用从时间复杂度上面分析，如果简单的方法就是O（n^2），如果利用归并排序的思想，
//左右两个组都是有序的，所以在merger的时候，一个是减少了右边数组中数的个数，二，也是可以利用有序
#include<iostream>
#include<vector>
using namespace std;
int Merge(vector<int>&ivec,int l,int p,int r){ 
	vector<int>left;
	vector<int>right; 
	for(int i=l;i<=p;i++){
		left.push_back(ivec[i]);
	}
	left.push_back(100);
	for(int j=p+1;j<=r;j++){
		right.push_back(ivec[j]);
	}
	right.push_back(100);
	int i=0;
	int j=0;
	int rightLength=right.size()-1;
	int sum=0;
	for(int k=l;k<=r;k++){
		cout<<i<<" "<<j<<'\n';
		if(left[i]<right[j]){
			int temp=left[i]*(rightLength-j);
			sum+=temp;
			ivec[k]=left[i++];
		}else if(left[i]>=right[j]){
			ivec[k]=right[j++];
		}/*else{
			ivec[k++]=left[i];//这么写有问题，比如（1,3）和(1,4)去和的时候，肯定出问题啊，两个1同时没了，但是其中左边的1比右边小啊，所以等于右边的1，右边加加， 
			ivec[k]=left[i];//接上句话，和上一种情况一样 
			i++,j++;
		} */
	}
	for(int i=l;i<=r;i++){
		cout<<ivec[i]<<" ";
	}
	cout<<endl<<sum<<endl<<endl;
	return sum;
}
int getSmallSum(vector<int>&ivec,int m,int n){
	if(m==n){
		return 0;
	}
	int i=(n+m)/2;
	int sum=0;
	sum+=getSmallSum(ivec,m,i);
	sum+=getSmallSum(ivec,i+1,n);
	sum+=Merge(ivec,m,i,n);
	return sum;
}
main(){
	vector<int>ivec={3,2,1,4};
	cout<<getSmallSum(ivec,0,3);
} 
 

