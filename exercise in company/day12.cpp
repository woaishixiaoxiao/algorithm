//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

//注意子树和子结构的区别。子树要求 B 的结尾处 必须是A的叶子节点。而子结构不要求 
#include<iostream>
using namespace std;
struct TreeNode {
	char val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(char x) :
			val(x), left(NULL), right(NULL) {
	}
};
bool binTree_create( TreeNode *&node ) {
	char x;
	cin>>x;
	if( x != '#' ) {
		node = new TreeNode(x);
		binTree_create(node->left);
		binTree_create(node->right);
	}
}

bool is_subTree(TreeNode *p1, TreeNode *p2) {
	    if(!p2)return true;                   //如果是if(!p2 && !p1) return true 则判断的是子树 
        if(!p1)return false;
        if(p1->val==p2->val){
            bool flag=is_subTree(p1->left,p2->left);
            if(flag&&is_subTree(p1->right,p2->right)){
                return true;
            }
        }
        return false;
}

/*
void inOrder(TreeNode *pRoot1, TreeNode *pRoot2, bool &flag) {
	if( !pRoot1 ) return;
	//cout<<pRoot1->val<<" ";
	if( pRoot1->val == pRoot2->val ) {
	    if( is_subTree(pRoot1, pRoot2) ) {
	    	flag = true;
	    	return;
		}
	}
	inOrder(pRoot1->left, pRoot2, flag);
	inOrder(pRoot1->right, pRoot2, flag);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool flag = false;
	if( !pRoot2 || !pRoot1 ) return false;
	inOrder(pRoot1, pRoot2, flag);
	return flag;
}*/
//上述两个函数起始可以合并起来：
bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
	if(!pRoot1 || !pRoot2) return false;
	return is_subTree(pRoot1, pRoot2) || HasSubTree(pRoot1->left， pRoot2) || HasSubTree(pRoot1->right, pRoot2);
} 
//8 8 9 # # 2 # # #          8 9 # # 2 # #
int main(){
	TreeNode *head1,*head2;
	cout<<"head1 input:\n";
	binTree_create(head1);
	cout<<"head2 input:\n";
	binTree_create(head2);
	cout<<HasSubtree(head1, head2)<<endl;
}
