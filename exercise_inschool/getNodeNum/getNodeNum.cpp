//给定一颗完全二叉树的头结点head，返回这棵树的节点个数，时间复杂度低于O(N) 
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
//递归函数结束的条件其实是取决于你递归函数中，对函数参数做了哪些内容
//递归的时候，参数不要想的是最开始的那种情况，而应该想的是在求解过程中的任意一种情况，
//从函数可知道，每次都要求个右边的节点，那递归结束的时候，肯定是当前节点为空，那么只要返回0，就不会
//影响整体的个数了 
//每次递归的时候，都是先看本次节点的右边最大深度，如果最大深度和h一样，那么说明左边就是满二叉树，
//如果不一样，那么右边减去本次递归的头结点后，剩下的就是满二叉树，求解过程中，还要注意的一点就是
//当没有节点的时候，也可以用2^k-1来求
//最后复杂度和层数有关 ,可知每次都是求右边的数的高度所以就是h+h-1+...+1为h^2 
