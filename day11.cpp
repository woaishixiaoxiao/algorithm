//����һ����������������е�����k����㡣
//������ָ�뼴�� 
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *p1 = pListHead, *p2;
        unsigned int i = 0;
        for( p2 = pListHead; p2 && i < k; p2 = p2->next,i++ );  //ע������i��k�Ĺ�ϵ 
		if( i < k ) return NULL; 
		while(p2) {
			p2 = p2->next;
			p1 = p1->next;
		}
		return p1;
    }
};
