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
//Approach-2 - (Using Priority Queue)
//T.C : O(N * log(K)), N =  total nodes, K = total K lists
//S.C : O(K),heap size never exceeds K
class Solution {
public:
    //T.C : O(N), N =. total nodes in all lists
    //S,C : O(N)
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto lambda = [](ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(lambda)> pq(lambda); 

        for(ListNode* node : lists) {
            if(node != NULL) {
                pq.push(node);
            }
        }

        if(pq.empty()) {
            return NULL;
        }

        ListNode* head = pq.top(); //head of final merged list
        pq.pop();

        if(head->next != NULL) {
            pq.push(head->next);
        }

        ListNode* tail = head;

        while(!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if(curr->next != NULL)
                pq.push(curr->next);
        }

        return head;

    }
};

