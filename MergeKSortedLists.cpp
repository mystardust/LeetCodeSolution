#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        if(n == 1) return lists[0];
        while(n > 1)
        {
            for(int i=0; i<n/2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[n-1-i]);
            }
            n = (n+1)/2;
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};