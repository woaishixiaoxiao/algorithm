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
		int bucketPos=(ivec[i]-minNum)*N/divNum;//虽然ivec[i]以及minNum可能不会溢出，但是乘以n之后就可能了，所以，最好先算（N/divNum） 
		bucketNum.insert(bucketPos);//还有一个需要注意的是,最后一个数正好bucketPos=N,也就是第N+1个桶，所以其他的肯定都在这个桶前面 
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
