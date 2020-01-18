#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *result = head;
        stack<ListNode*> s;
        while(head)
        {
            s.push(head);
            head = head->next;
        }
        for(int i = 0; i < n-1; ++i) s.pop();
        ListNode * temp = s.top()->next;
        s.pop();
        if(!s.empty())(*s.top()).next = temp;
        else result = temp;
        return result;
    }
};