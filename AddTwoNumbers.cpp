  
  
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = l1;
        ListNode* temp;
        while(l1 && l2)
        {
            int a = (l1->val + l2->val) % 10;
            int b = (l1->val + l2->val) / 10;
            l1->val = a;
            if(l1->next) l1->next->val += b;
            else if(l2->next || b > 0)
            {
                temp = new ListNode(b);
                l1->next = temp;
            };
            l1 = l1->next;
            l2 = l2->next;
            if(!l2) 
            {
                temp = new ListNode(0);
                l2 = temp;
            }            
        }
        return result;
    }
};