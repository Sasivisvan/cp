/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptrptr) {}
 *     ListNode(int x) : val(x), next(nullptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr)return ;
        stack<struct ListNode*>stk;
        struct ListNode *temp = head;
        struct ListNode *ft = head;
        struct ListNode *prev;

        while(temp!=nullptr && ft!=nullptr&&ft->next!=nullptr){
            prev = temp;
            temp = temp->next;
            ft = ft->next->next;
        }
        prev = temp;
        temp = temp->next;
        prev->next = nullptr;
        
        while(temp!=nullptr){
            stk.push(temp);
            temp = temp->next;
        }
        
        temp = head;
        struct ListNode *t;
        struct ListNode *ne=temp;
        while(temp!=nullptr&& temp->next !=nullptr && stk.size()!=0){
            t = stk.top();
            stk.pop();
            // ne = temp->next;
            t->next = temp->next;
            temp->next = t;
            temp = t->next;
        }
    }
};