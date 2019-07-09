//定义局部最小的概念。arr长度为1时，arr[0]是局部最小。arr的长度为N(N>1)时，如果arr[0]<arr[1]，那么arr[0]是局部最小；
//如果arr[N-1]<arr[N-2]，那么arr[N-1]是局部最小；如果0<i<N-1，既有arr[i]<arr[i-1]又有arr[i]<arr[i+1]，那么arr[i]是局部最小。
//给定无序数组arr，已知arr中任意两个相邻的数都不相等，写一个函数，只需返回arr中任意一个局部最小出现的位置即可。 
//解释下为什么第二个数比第一个数小，最后一个数比倒数第二个大，那么就一定会有一个局部最小值
//因为相邻的两个是不相等的，所以相邻三个数的关系，就有这么几种情况，一直降，一直升，先将后升，先升后降，
//因为最开始的两个数的趋势是下降，从最后到倒数第二个数的趋势也是下降，反正自己画画也能画出来，不要纠结
//最后结论就是只要两头的趋势都是下降，那么中间必有一个，如果两头有一个不是这样的，那答案就直接有了，所以这道题，一定有解 
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
	while(beg<end){//这个里面不用再去判断13-20的那个内容，因为你只要确定了解一定在这个区间范围内就可以了，进而把区间范围减小就行了 
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
	return beg; //这里返回什么都无所谓，因为上面是一定有解得 
}
main(){
	vector<int>ivec={};
	int pos;
	if(getLocalLessIndex(ivec,pos)){
		cout<<pos<<endl;
	}
} 
