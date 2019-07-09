//bfprt�㷨������k��С���󣩵�ֵ �������top kС�Ļ����ͱ����ҵ�����С���������Ҫ����top k����partition����ı�ͺ��ˣ�
//���Ŷ�pivot���߶��ݹ���ôʱ�临�ӶȾ���O(nlogn)�����ֻ��һ�ߵݹ�Ļ�����O(n),(�ҵ�k��С������ֻ��Ҫ�ж�ͨ��Partitionȷ��λ�õ���������±�ȥ�͵�k�����Աȣ� 
//����±겻һ����ֻ�����߻����ұߵݹ�ͺ��ˣ��������ߵ�������������O(n^2)������Ϊ�˱���������������Ҿ��������߾���һ�㣬�����˶����������λ������λ���㷨 
//���Ȱ����鰴5����Ϊһ����з��飬�����5���ĺ��ԡ���ÿ�����������������������ȡ����λ����
//����һ����������λ���Ƶ������ǰ�棬����Щ��λ���ݹ����BFPRT�㷨������ǵ���λ������bfpt�㷨�������k�����ģ���������λ������λ����Ҳ����������㷨���� 
//����һ���õ�����λ����Ϊ���ֵ���Ԫ������������Ļ��֡�
//�жϵ�k�����ڻ��ֽ������ߡ��ұ߻���ǡ���ǻ��ֽ������ǰ���ߵݹ鴦������ֱ�ӷ��ش𰸡� 
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
pair<int,int> partition(int *array,int l,int p,int pivot){//��·Partition��ʵ���Ǻ���·һ������·�ǽ�С�ں͵��ڷŵ�Pivot����ߣ����ڷŵ��ұߣ�����·���� 
	int rightPivot=p+1;//��С�ں͵��ڽ�����·���ţ������ڵľͷŵ��ұ�ȥ����ʱj����һ�����t�Ǵӳ�ʼλ�ÿ�ʼ�ӻ��߼�����ôt�ĵ�ǰֵ����û�����������һ������һ���� 
	int leftPivot=l-1;//λ�õ������ݼ���,��ô��ǰֵ�����Ѿ�������˵� 
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
	//int pivotId=(t-l+1)/2;//�����㲻�ð�������λ������������ż������������������(t+l)/2��������������������λ�����꣬����ż����˵��������λ������ 
	int pivotId=(t+l)/2; 
	int pivot=bfprt(array,l,t,pivotId-l+1);//��λ������ת��Ϊ������ 
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
