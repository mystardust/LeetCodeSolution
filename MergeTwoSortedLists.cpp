struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *temp = nullptr, *tail = nullptr, *comp = nullptr;
        int tl = 0;
        if(l1 && !l2) 
        {
            head = tail = l1;
            comp = l2;;
        }
        else if(l2 && !l1) 
        {
            head = tail = l2;
            comp = l1;
        }
        else if(l1 && l2)
        {
            head = tail = (l1->val <= l2->val)? l1 : l2;
            comp = (l1->val <= l2->val)? l2 : l1;
        }
        if(!tail) return head;
        while(tail->next && comp)
        {
            if(tail->next->val > comp->val)
            {
                temp = comp;
                comp = tail->next;
                (*tail).next = temp;
            }
            else 
            {
                tail = tail->next;
            }
        }
        if(comp) (*tail).next = comp;
        return head;
    }
};