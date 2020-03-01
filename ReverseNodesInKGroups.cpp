struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head == nullptr) return head;
        ListNode preNode = ListNode(0);
        ListNode *preHead = &preNode;
        preHead->next = head;
        ListNode *cur, *nex,*pre=preHead;
        int n=1;
        while(head = head->next) ++n;
        while(n>=k)
        {           
            cur = pre->next;
            for(int i=1; i<k; ++i)
            {
                nex = cur->next;
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;                
            }
            n-=k;
            pre = cur;
        }
        return preHead->next;
    }
};