#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a,int b){
	return a<b;
}
int CountNotRepeat(vector<int>&ivec){
	if(ivec.empty())return 0;
	bool repeat=true;
	int num=ivec[0];
	int count=1;
	for(int i=1;i<ivec.size();i++){
		if(ivec[i]==num && repeat){
			count--;
			repeat=false;
		}else{
			count++;
			num=ivec[i];
			repeat=true;
		}
	}
	return count;
}
int main(){
	vector<int>ivec;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		ivec.push_back(temp);
	}
	sort(ivec.begin(),ivec.end(),compare);
	int res=CountNotRepeat(ivec);
	cout<<res;
}
