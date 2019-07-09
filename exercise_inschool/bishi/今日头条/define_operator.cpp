//定义两个字符串变量：s和m，在定义两种操作
//第一种操作：m=s s=s+s
//第二种操作:s=s+m
//假设s,m初始化如下  s="a' m=s
//求最小的操作部署，可以使得s拼接到长度等于N
//输入一个整数n，表明我们需要得到s的字符串长度
//对于100%的数据，0<n<1000
//输出一个整数表明总共操作次数
#include<iostream>
#include<queue>
using namespace std;
struct Node{
	string m;
	string s;
	int floor;
	Node(string _m,string _s,int _f):m(_m),s(_s),floor(_f){
	}
};
int bfs(queue<Node>&q,int len){
	while(!q.empty()){
		Node temp=q.front();
		q.pop();
		if(temp.s.size()==len)return temp.floor;
		string s=temp.s;
		string m=temp.m;
		q.emplace(s,s+s,temp.floor+1);
		q.emplace(m,s+m,temp.floor+1);
	}
}
main(){
	int res;
	int length;
	cin>>length;
	queue<Node>q;
	Node n("a","a",1);
	q.push(n);
	res=bfs(q,length);
	cout<<res<<endl;
}
