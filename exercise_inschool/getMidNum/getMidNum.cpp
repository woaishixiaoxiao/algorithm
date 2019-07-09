#include<iostream>
#include<vector>
using namespace std;
bool getMidNum(vector<int>&ivec1,vector<int>&ivec2,int &res){
	if(ivec1.empty())return false;
	int beg[2],end[2],mid[2];
	beg[0]=beg[1]=0;
	end[0]=end[1]=ivec1.size()-1;
	while(beg[0]<end[0]&&beg[1]<end[1]){
		mid[0]=(beg[0]+end[0])/2;
		mid[1]=(beg[1]+end[1])/2;
		if(ivec1[mid[0]]==ivec2[mid[1]]){
			res=ivec1[mid[0]];
			return true;
		}else{
			int offset= (end[1]-beg[1]+1)%2==0?1:0;
			int pos=ivec1[mid[0]]>ivec2[mid[1]]?0:1;
			end[pos]=mid[pos];
			beg[1-pos]=mid[1-pos]+offset;
		}
	}
	res=ivec1[beg[0]]>ivec2[beg[1]]?ivec2[beg[1]]:ivec1[beg[0]];
	return true;
}
main(){
	vector<int>ivec1={2,6,9};
	vector<int>ivec2={1,2,7};
	int res;
	if(getMidNum(ivec1,ivec2,res)){
		cout<<res;
	}
}
