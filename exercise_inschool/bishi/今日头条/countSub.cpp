//��n��Ԫ�ص������У��ҵ���ֵΪK�����ֶ�ȥ�غ�ĸ���
//��һ�У�n��k����n��ʾ���ָ���  k��ʾ��ֵ
//���ڶ���  n��������
//�����������ֵΪk�����ֶ�ȥ�غ�ĸ���
//���ݷ�Χ������100%�����ݣ�0<=k<100  
//����100%��������������ֵ��Χ��[0-10^8]
//����100%������  n<0<10^6
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
