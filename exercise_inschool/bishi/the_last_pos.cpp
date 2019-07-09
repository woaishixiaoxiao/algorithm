#include<iostream>
using namespace std;
long long getNum(long long sum){
	long long res=0;
	while(sum){
		res+=sum;
		sum/=(long long)10;
	}
	return res;
}
int main(){
	long long sum;
	cin>>sum;
	long long beg=1,end=sum,mid;
	while(beg<=end){
		mid=(beg+end)/2;
		long long temp=getNum(mid);
		if(temp==sum){
			cout<<mid;
			break;
		}
		else if(temp<sum){
			beg=mid+1;
		}else{
			end=mid-1;
		}
	}
	if(beg>end){
		cout<<-1;
	}
	return 0;
}
