//����С�͵Ķ������£����磬����s=[1��3��5��2��4��6]����s[0]�����С�ڻ����s[0]�����ĺ�Ϊ0��
//��s[1]�����С�ڻ����s[1]�����ĺ�Ϊ1����s[2]�����С�ڻ����s[2]�����ĺ�Ϊ1+3=4����s[3]��
//���С�ڻ����s[3]�����ĺ�Ϊ1����s[4]�����С�ڻ����s[4]�����ĺ�Ϊ1+3+2=6����s[5]�����С
//�ڻ����s[5]�����ĺ�Ϊ1+3+5+2+4=15������s��С��Ϊ0+1+4+1+6+15=27��
//�����Ҫ����O(nlogn)ʱ�临�Ӷȣ��õ��ǹ鲢�����˼�룬
//Ϊʲô�鲢����ʱ��ȼ������ʱ�临�Ӷ�Ҫ�ã���õķ����Ǵ�ʱ�临�Ӷ����������
//ֱ�����濴��Ӧ����ÿ�αȽϵ�ʱ������̫���ˣ�����
//����ⲻ�ô�ʱ�临�Ӷ��������������򵥵ķ�������O��n^2����������ù鲢�����˼�룬
//���������鶼������ģ�������merger��ʱ��һ���Ǽ������ұ����������ĸ���������Ҳ�ǿ�����������
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
			ivec[k++]=left[i];//��ôд�����⣬���磨1,3����(1,4)ȥ�͵�ʱ�򣬿϶������Ⱑ������1ͬʱû�ˣ�����������ߵ�1���ұ�С�������Ե����ұߵ�1���ұ߼Ӽӣ� 
			ivec[k]=left[i];//���Ͼ仰������һ�����һ�� 
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
 

