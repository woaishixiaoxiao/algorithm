#include<iostream>
using namespace std;
int jumpFloor(int number) {
    if(number==0){
        return 0;
    }
    int dp[3];
    dp[0]=1;
    dp[1]=1;
    dp[2]=1;
    for(int i=2;i<=number;i++){
        dp[0]=dp[1];
        dp[1]=dp[2];
        dp[2]=dp[1]+dp[0];
    }
    return dp[2];
}
main(){
	for(int i=0;i<45;i++){
		cout<<jumpFloor(i)<<endl;
	}
	
}
