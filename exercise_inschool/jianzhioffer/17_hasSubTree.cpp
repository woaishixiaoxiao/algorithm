//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
//�ӽṹ��ֻҪB�е����нڵ���A�еĽڵ�һ���־��У�����ָ��B����ָ����A���е�ĳһ��ֵ��Ҳ��Ҫ��
//��A��ĳһ���ڵ㿪ʼ���������ϵ����нڵ��ֵB�ж�Ҫ�У�ֻҪһ�����Ǿ��� 
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
//������ѵ��ǵ�ǰ�����ڵ������ȣ���ô��ͬʱȥ�۲� A�����ڵ����B�����ڵ�����Լ����Ǹ��Ե��ұ�
//�����ߺ��ұ���һ������ȣ���ô��Ҫȥ�۲죬A��ǰ�ڵ����ߺ�B�����ڵ㣬����A��ǰ�ڵ���ұߺ�B�����ڵ�
//A��ÿһ���ڵ㶼Ҫ��ô�������Լ�����д��isEqual���������������Ҫ�������Կ�������̫�á�����ķ����ȽϺ�
//��isEqual�оʹ���������˵�ĵ�һ����������ں�����������������hasSubTree��ȥ���� 
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
