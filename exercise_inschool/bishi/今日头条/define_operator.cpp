//���������ַ���������s��m���ڶ������ֲ���
//��һ�ֲ�����m=s s=s+s
//�ڶ��ֲ���:s=s+m
//����s,m��ʼ������  s="a' m=s
//����С�Ĳ������𣬿���ʹ��sƴ�ӵ����ȵ���N
//����һ������n������������Ҫ�õ�s���ַ�������
//����100%�����ݣ�0<n<1000
//���һ�����������ܹ���������
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
