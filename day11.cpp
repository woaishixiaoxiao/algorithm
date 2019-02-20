//输入一个链表，输出该链表中倒数第k个结点。
//用两个指针即可 
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
        for( p2 = pListHead; p2 && i < k; p2 = p2->next,i++ );  //注意这里i和k的关系 
		if( i < k ) return NULL; 
		while(p2) {
			p2 = p2->next;
			p1 = p1->next;
		}
		return p1;
    }
};
