/*ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
ĭ����2*nƥ��ÿƥ����һ���ٶ�v������ĭ������ֳ��������飬ÿ���������nƥ��������֮�����n��������ÿ���������Ӹ��ɳ�һƥ�������ÿƥ��ǡ�ó���һ�Ρ�ĭ����֪���Ƿ����һ�ַ������ķ���ʹ��������ô���ű�������һ�����鶼һ���ܻ��ȫʤ����ƥ�����ٶȲ�һ������ô�ٶȿ�Ļ�ʤ�����ٶ�һ�������п��ܻ�ʤ��

����
��һ��һ����T(T<=100)����ʾ����������

����ÿ�����ݣ���һ��һ������n , (1<=n<=100)

������һ�У�2*n����������i������vi��ʾ��iƥ����ٶ�, (1 <= vi <= 1000)

���
����ÿ�����ݣ����һ�У�������һ�ַ��䷽��ʹ�õ�һ������ȫʤ���YES���������NO


��������
2

2

1 2 3 4

1

1 1

�������
YES
NO*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool mycompare(const int &num1,const int &num2){
    return num1<num2;
}
bool fun(vector<int>&speed){
    int ntime=0;
    int result;
    for(int i=0;i<speed.size();i++){
        if(ntime==0){
            result=speed[i];
            ntime=1;
        }else{
            if(result == speed[i]){
                ntime++;
            }else{
                ntime--;
            }
        }
    }
    ntime=0;
    for(int i=0;i<speed.size();i++){
        if(result==speed[i])ntime++;
    }
    if(ntime>(speed.size()/2))return false;
    return true;
}
int main(){
    int T;
    cin>>T;
    vector<string>res;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        int num;
        vector<int>speed;
        for(int j=0;j<2*n;j++){
            cin>>num;
            speed.push_back(num);
        }
        if(fun(speed)){
            res.push_back("YES");
        }else{
            res.push_back("NO");
        }
    }
    for(int i=0;i<T-1;i++){
        cout<<res[i]<<endl;
    }
    cout<<res[T-1];
}
