using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr )return nullptr;
        ListNode *newHead = (head->next == nullptr)? head : head->next;
        ListNode *oldHead = nullptr, *preOldHead = nullptr;
        while(head != nullptr && head->next != nullptr)
        {
            oldHead = head;
            head = head->next;
            (*oldHead).next = oldHead->next->next;
            (*head).next = oldHead;
            if(preOldHead != nullptr)(*preOldHead).next = head;
             head = oldHead->next;
            preOldHead = oldHead;
        }
        return newHead;
    }
};