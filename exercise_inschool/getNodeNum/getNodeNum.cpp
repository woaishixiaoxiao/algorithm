//����һ����ȫ��������ͷ���head������������Ľڵ������ʱ�临�Ӷȵ���O(N) 
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef struct Node{
	char n;
	Node *left;
	Node *right;
	Node(char _n,Node *_left,Node *_right){
		n=_n;
		left=_left;
		right=_right;
	}
}BiTree;
void preOrderInsert(BiTree *&head){
	char temp;
	cin>>temp;
	if(temp!='#'){
		head=new BiTree(temp,NULL,NULL);
		preOrderInsert(head->left);
		preOrderInsert(head->right);
	}
}
int getNumRecu(BiTree *node,int L,int h){
	if(!node)return 0;
	int curr_level=L;
	int res;
	auto right=node->right;
	if(right){
		curr_level=L+1;
		auto left=right->left;
		while(left){
			curr_level++;
			left=left->left;
		}
	}
	if(curr_level==h-1){
		res=pow(2,h-L-1)+getNumRecu(node->right,L+1,h);
	}else{
		res=pow(2,h-1-L-1)+getNumRecu(node->left,L+1,h);
	}
	return res;
}
int getNodeNum(BiTree *head){
	if(!head)return 0;
	int h=0;
	auto temp=head;
	while(temp){
		h++;
		temp=temp->left;
	}
	int res=getNumRecu(head,0,h);
	return res;
}
main(){
	BiTree *head=NULL;
	preOrderInsert(head);
	int res=getNodeNum(head);
	cout<<res;
}
//�ݹ麯��������������ʵ��ȡ������ݹ麯���У��Ժ�������������Щ����
//�ݹ��ʱ�򣬲�����Ҫ������ʼ�������������Ӧ����������������е�����һ�������
//�Ӻ�����֪����ÿ�ζ�Ҫ����ұߵĽڵ㣬�ǵݹ������ʱ�򣬿϶��ǵ�ǰ�ڵ�Ϊ�գ���ôֻҪ����0���Ͳ���
//Ӱ������ĸ����� 
//ÿ�εݹ��ʱ�򣬶����ȿ����νڵ���ұ������ȣ���������Ⱥ�hһ������ô˵����߾�������������
//�����һ������ô�ұ߼�ȥ���εݹ��ͷ����ʣ�µľ��������������������У���Ҫע���һ�����
//��û�нڵ��ʱ��Ҳ������2^k-1����
//����ӶȺͲ����й� ,��֪ÿ�ζ������ұߵ����ĸ߶����Ծ���h+h-1+...+1Ϊh^2 
