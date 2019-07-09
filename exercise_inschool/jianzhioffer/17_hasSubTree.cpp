//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//子结构是只要B中的所有节点是A中的节点一部分就行，不是指向B树的指针是A树中的某一个值。也不要求
//从A的某一个节点开始往下子树上的所有节点的值B中都要有，只要一部分是就行 
class Solution {
    bool isEqual(TreeNode *p1,TreeNode *p2,TreeNode *p3){
        if(!p2){
            return true;
        }
        else{
            if((p1)&&(p1->val==p2->val)){
                bool res1=isEqual(p1->left,p2->left,p3);
                if(res1&&isEqual(p1->right,p2->right,p3)){
                    return true;
                }
                else{
                    if(isEqual(p1->left,p3,p3))return true;
                    if(isEqual(p1->right,p3,p3))return true;
                }
            }
            return false;
        }
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1||!pRoot2){
            return false;
        }
        return isEqual(pRoot1,pRoot2,pRoot2);
    }
};
//这道题难点是当前两个节点如果相等，那么就同时去观察 A子树节点左边B子树节点左边以及他们各自的右边
//如果左边和右边有一个不相等，那么就要去观察，A当前节点的左边和B树根节点，或者A当前节点的右边和B树根节点
//A中每一个节点都要这么处理。我自己上面写的isEqual里面这三种情况都要处理，所以看起来不太好。下面的方法比较好
//在isEqual中就处理我上面说的第一种情况，至于后面的两种情况，放在hasSubTree中去处理。 
class Solution {
    bool isEqual(TreeNode *p1,TreeNode *p2){
        if(!p2)return true;
        if(!p1)return false;
        if(p1->val==p2->val){
            bool flag=isEqual(p1->left,p2->left);
            if(flag&&isEqual(p1->right,p2->right)){
                return true;
            }
        }
        return false;
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1||!pRoot2){
            return false;
        }
        return isEqual(pRoot1,pRoot2)||HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
    }
}; 
