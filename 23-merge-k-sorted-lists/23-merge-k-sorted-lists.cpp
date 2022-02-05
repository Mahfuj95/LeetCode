/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
public:
    struct CompareVal {
        bool operator()(ListNode *p1, ListNode *p2)
        {
            return p1->val > p2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareVal> q;
        
        for(int i = 0; i<lists.size(); i++){
            if(lists[i] != nullptr){
                q.push(lists[i]);
            } 
        }
        
        ListNode *temp = new ListNode();
        ListNode *ans = temp;
        
        while(!q.empty()){
            temp->next = new ListNode(q.top()->val);
            temp = temp->next;
            if(q.top()->next != nullptr){
                q.push(q.top()->next);
            }
            q.pop();
        }

        return ans->next;
        
    }
};