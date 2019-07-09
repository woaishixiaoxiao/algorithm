//在n个元素的数组中，找到差值为K的数字对去重后的个数
//第一行，n和k，，n表示数字个数  k表示差值
//，第二行  n个正整数
//输出描述：差值为k的数字对去重后的个数
//数据范围：对于100%的数据，0<=k<100  
//对于100%的数据数组内数值范围在[0-10^8]
//对于100%的数据  n<0<10^6
#include<iostream>
#include<algorithm>
using namespace std;
bool mycompare(const int a,const int b){
    return a<b;
}
int fun(vector<int>&ivec,int k){
    int res=0;
    int sz=ivec.size();
    int num;
    bool flag=false;
    for(int i=0;i<sz;i++){
        for(int j=sz-1;j>=i;j--){
            if(flag && ivec[j]==num){
                continue;
            }else{
                if((ivec[j]-ivec[i])==k){
                    flag=true;
                    num=ivec[j];
                    res++;
                }else{
                    if(ivec[j]-ivec[i]<k){
                        break;
                    }
                }
            }
        }
    }
    return res;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>ivec;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        ivec.push_back(temp);
    }
    sort(ivec.begin(),ivec.end(),mycompare);
    int res=fun(ivec,k);
    cout<<res;
} 
