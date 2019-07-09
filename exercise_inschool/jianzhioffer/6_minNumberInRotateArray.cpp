//用半分查找解决问题，因为半分过程中arr[beg]是大于等于arr[end]的（初始化也能满足这个），
//所以在中间只要遇到一个数是>arr[beg]，那么左边范围就可以缩小到beg=mid(不能加1，因为beg是要保证在左边
//加一就不一定了）,右边只要小于arr[end]，就能缩小到 
//end=mid（因为这个可能是最小的数）， 当arr[mid]如果等于右边的数，有两种情况，等于左边的数，不等于左边的数，
//后者也是一样的分析，但是相等了那范围可能在左边也可能在右边，所以只好从这里开始顺序查找了 ,如果等于左边不等于右边
//那么也是和上面一样的分析 
#include<iostream>
#include<vector>
using namespace std;
int InorderSearch(vector<int>&rotateArray,int beg,int end){
	int res=rotateArray[beg];
	for(int i=beg+1;i<=end;i++){
		if(rotateArray[i]<rotateArray[i-1]){
			res=rotateArray[i];
			break;
		}
	}
	return res;
}
int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.empty()){
        return 0;
    }
    int end=rotateArray.size()-1;
    int beg=0;
    int mid;
    while((end-beg)>=2){
    	cout<<beg<<" "<<end<<endl;
        mid=(beg+end)/2;
        if((rotateArray[mid]==rotateArray[beg])&&(rotateArray[mid]==rotateArray[end])){
            return InorderSearch(rotateArray,beg,end);
        }else{
            if(rotateArray[mid]>=rotateArray[beg]){
                beg=mid;
            }else if(rotateArray[mid]<=rotateArray[end]){
                end=mid;
            }
        }
    }
    cout<<beg<<" "<<end<<endl; 
    int res;
    if((end-beg)==1){
        res=rotateArray[beg]<rotateArray[end]?rotateArray[beg]:rotateArray[end];//当移到前面的数量为0（顺序） 
    }else{
        res=rotateArray[beg];
    }
    return res;
} 
main(){
	vector<int>ivec={3,4,5,1,2,3};
	cout<<minNumberInRotateArray(ivec);
}
