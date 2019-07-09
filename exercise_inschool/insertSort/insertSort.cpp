#include<iostream>
using namespace std; 
//写个有尖兵的插入排序
//可以看出和没有尖兵的区别很大
/*void insertSort(int *array,int begPos,int endPos){
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
}*/ 
void InsertSort(int *array,int n){
	for(int i=2;i<=n;i++){
		array[0]=array[i];
		int j;
		for(j=i-1;array[j]>array[0];j--){
			array[j+1]=array[j];
		}
		array[j+1]=array[0];
	}
} 
main(){
	int array[]={0,3,4,2};
	InsertSort(array,3);
	for(int i=1;i<=3;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
