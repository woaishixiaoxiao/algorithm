//bfprt算法是求解第k个小（大）的值 ，如果求top k小的话，就遍历找到比他小的数（如果要是找top k就在partition那里改变就好了）
//快排对pivot两边都递归那么时间复杂度就是O(nlogn)，如果只对一边递归的话就是O(n),(找第k个小的数，只需要判断通过Partition确定位置的这个数的下标去和第k个数对比， 
//如果下标不一样，只需对左边或者右边递归就好了）但是两者的最糟糕情况都是O(n^2)，所以为了避免这种情况，并且尽量让两边均衡一点，就有了对数组的求中位数的中位数算法 
//首先把数组按5个数为一组进行分组，最后不足5个的忽略。对每组数进行排序（如插入排序）求取其中位数。
//把上一步的所有中位数移到数组的前面，对这些中位数递归调用BFPRT算法求得他们的中位数。（bfpt算法就是求第k个数的，所以求中位数的中位数就也可以用这个算法啊） 
//将上一步得到的中位数作为划分的主元进行整个数组的划分。
//判断第k个数在划分结果的左边、右边还是恰好是划分结果本身，前两者递归处理，后者直接返回答案。 
#include<iostream>
#include<vector>
#include<string>
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
pair<int,int> partition(int *array,int l,int p,int pivot){//三路Partition其实就是和两路一样，两路是将小于和等于放到Pivot的左边，大于放到右边，而三路就是 
	int rightPivot=p+1;//对小于和等于进行两路快排，而大于的就放到右边去，此时j不加一，如果t是从初始位置开始加或者减，那么t的当前值代表没处理，如果从上一个（下一个） 
	int leftPivot=l-1;//位置递增（递减）,那么当前值代表已经处理过了的 
	int j=l;
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
int bfprt(int *array,int l,int p,int k){
	if(p-l+1<5){
		insertSort(array,l,p);
		return array[l+k-1];
	}
	int sz=(p-l+1)/5;
	int t=l-1;
	int beg=l;
	int end=l+4;
	for(int i=0;i<sz;i++){
		insertSort(array,beg,end);
		swap(array,++t,beg+2);
		beg+=5;
		end=beg+4;
	}
	//int pivotId=(t-l+1)/2;//这样算不好啊，找中位数的数无论是偶数还是奇数都可以用(t+l)/2来处理，对于奇数就是中位数坐标，对于偶数来说就是上中位数坐标 
	int pivotId=(t+l)/2; 
	int pivot=bfprt(array,l,t,pivotId-l+1);//中位数坐标转化为个数， 
	auto e=partition(array,l,p,pivot);
	int leftPos=e.first;
	int rightPos=e.second;
	int pos=l+k-1;
	if((pos<=rightPos)&&(k>=leftPos)){
		return array[pos];
	}else if(pos>rightPos){
		return bfprt(array,rightPos+1,p,pos-rightPos);
	}else{
		return bfprt(array,l,leftPos-1,k);
	}
}
main(){
	int array[]={2,3,3,3,3,33,3};
	cout<<bfprt(array,0,7,4);
}
