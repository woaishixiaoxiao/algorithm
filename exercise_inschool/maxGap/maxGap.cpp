#include<iostream>
#include<vector>
#include<set>
using namespace std;
bool  maxGap(vector<int>&ivec,int &gap){
	int N=ivec.size();
	if(N==0)return false;
	int maxNum=ivec[0];
	int minNum=ivec[0];
	for(int i=1;i<ivec.size();i++){
		if(ivec[i]>maxNum){
			maxNum=ivec[i];
		}
		if(ivec[i]<minNum){
			minNum=ivec[i];
		}
	}
	if(maxNum==minNum){
		gap=0;
		return true;
	}
	int minRightest=maxNum;
	vector<int>bucketMin(N+1,maxNum);
	vector<int>bucketMax(N+1,minNum);
	set<int>bucketNum;
	int divNum=maxNum-minNum;
	for(int i=0;i<N;i++){
		int bucketPos=(ivec[i]-minNum)*N/divNum;//��Ȼivec[i]�Լ�minNum���ܲ�����������ǳ���n֮��Ϳ����ˣ����ԣ�������㣨N/divNum�� 
		bucketNum.insert(bucketPos);//����һ����Ҫע�����,���һ��������bucketPos=N,Ҳ���ǵ�N+1��Ͱ�����������Ŀ϶��������Ͱǰ�� 
		if(bucketMin[bucketPos]>ivec[i]){
			bucketMin[bucketPos]=ivec[i];
		}
		if(bucketMax[bucketPos]<ivec[i]){
			bucketMax[bucketPos]=ivec[i];
		}
	}
	int L=-1;
	vector<int>notAppearance;
	gap=0;
	for(auto ite=bucketNum.begin();ite!=bucketNum.end();ite++){
		if(*ite!=L+1){
			int temp=L;
			for(int i=L+1;L<*ite;L++){
				notAppearance.push_back(i);
			}
			int gapTemp=bucketMin[*ite]-bucketMax[temp];
			gap=gapTemp>gap?gapTemp:gap;
		}else{
			L++;
		}
	}
}
main(){
	vector<int>ivec={10,2};
	int res;
	if(maxGap(ivec,res)){
		cout<<res<<endl;
	}
}
