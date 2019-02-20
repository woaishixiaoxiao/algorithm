#输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		vector<int>i_res;
        if( !head ) return i_res;
		stack<int>s;
		ListNode *p = head;
		while( p ) {
			s.push( p->val );
			p = p->next;
		}
		while( !s.empty() ) {
			i_res.push_back( s.top() );
			s.pop();
		}
		return i_res;
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		vector<int>i_res;
        if( !head ) return i_res;
		ListNode *next = head->next;
		ListNode *pre = head;
		ListNode *current;
		while( next ) {
			pre->next = next->next;
			next->next = head;
			head =  next;
			next = pre->next;
		}
		current = head;
		while( current ) {
			i_res.push_back( current->val );
			current = current->next;
		}
		return i_res;
    }
};
