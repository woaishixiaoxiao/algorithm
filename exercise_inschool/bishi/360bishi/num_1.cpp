#include<iostream>
#include<vector>
using namespace std;
int main(){
    int T;
    vector<int>res;
    cin>>T;
    for(int i=0;i<T;i++){
        int sum=0;
        int num;
        for(int i=0;i<5;i++){
            cin>>num;
            sum+=num;
        }
        int mod=sum%5;
        if(mod){
            res.push_back(-1);
        }else{
            res.push_back(sum/5);
        }
    }
    for(int i=0;i<T-1;i++){
        cout<<res[i]<<endl;
    }
    cout<<res[T-1];
    return 0;
}
