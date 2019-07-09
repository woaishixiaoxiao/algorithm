/*时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
沫璃有2*n匹马，每匹马都有一个速度v。现在沫璃将马分成两个队伍，每个队伍各有n匹马，两个队之间进行n场比赛，每场比赛两队各派出一匹马参赛，每匹马都恰好出场一次。沫璃想知道是否存在一种分配队伍的方法使得无论怎么安排比赛，第一个队伍都一定能获得全胜。两匹马若速度不一样，那么速度快的获胜，若速度一样，则都有可能获胜。

输入
第一行一个数T(T<=100)，表示数据组数。

对于每组数据，第一行一个整数n , (1<=n<=100)

接下来一行，2*n个整数，第i个整数vi表示第i匹马的速度, (1 <= vi <= 1000)

输出
对于每组数据，输出一行，若存在一种分配方法使得第一个队伍全胜输出YES，否则输出NO


样例输入
2

2

1 2 3 4

1

1 1

样例输出
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
