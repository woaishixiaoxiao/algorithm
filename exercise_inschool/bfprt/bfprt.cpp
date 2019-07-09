#include<iostream>
#include<vector>
#include<utility>
using namespace std;
void swap(int *array,int i,int j){
	int temp=array[i];
	array[i]=array[j];
	array[j]=temp;
}
void insertSort(int *array,int begPos,int endPos){
	for(int i=begPos+1;i<=endPos;i++){
		int temp=array[i];
		int j;
		for(j=i-1;j>=begPos;j--){
			if(array[j]>=temp){
				array[j+1]=array[j];
			}else{
				break;
			}
		}
		array[j+1]=temp;
	}
}
void mediaOfmidias(int *array,int beg,int end){
	if(beg==end)return;
	int offset=(end-beg+1)%5?1:0;//注意这里，条件中省略为0的话，那么也就是不为0的时候等于1，为0的时候等于0 
	int sz=(end-beg+1)/5+offset;
	int begPos=beg-5;;
	int endPos;
	for(int i=0;i<sz-1;i++){
		begPos+=5;
		endPos=begPos+4;
		insertSort(array,begPos,endPos);
		int temp=array[begPos+2];
		array[begPos+2]=array[beg+i];
		array[beg+i]=temp;
		
	}
	begPos+=5;
	endPos=begPos+4;
	endPos=endPos>end?end:endPos;
	insertSort(array,begPos,endPos);
	int offset_=(endPos-begPos+1)%2?0:-1;
	int midPos=(endPos-begPos+1)/2+offset_+begPos;
	int temp=array[midPos];
	array[midPos]=array[beg+sz-1];//这里的sz-1不可以替换为i（加入i是局部变量的），因为假设初始条件不成立的时候，没有自加这个操作 
	array[beg+sz-1]=temp;
	mediaOfmidias(array,beg,beg+sz-1);
}
pair<int,int> partition(int *array,int p,int r){
	if(p==r)return make_pair(p,r);
	swap(array,p,r);
	int pivot=array[r];
	int rightPivot=r+1;
	int leftPivot=p-1;
	int j=p;
	while(j<rightPivot){
		if(array[j]<pivot){
			swap(array,++leftPivot,j++);
		}else if(array[j]>pivot){
			swap(array,j,--rightPivot);
		}else{
			j++;
		}
	}
	return make_pair(leftPivot+1,rightPivot-1);
}
int bfprt(int *array,int beg,int end,int k){
	mediaOfmidias(array,beg,end);
	auto pos=partition(array,beg,end);
	if((k-1<=pos.second)&&(k-1>=pos.first)){
		return array[k-1];
	}else if(k-1<pos.first){
		bfprt(array,beg,pos.first-1,k);
	}else if(k-1>pos.second){
		bfprt(array,pos.second+1,end,k);
	}
}
main(){
	int array[]={3};
	int temp=bfprt(array,0,0,1);
	cout<<temp;
}
