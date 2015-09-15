/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool cmpListNode(ListNode *l, ListNode *r)
{
    if(l->val > r->val) return true;
    else return false;
}

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int K = lists.size();   // K-merge
        if(K==0) return NULL;
        if(K==1) return lists[0];
        vector<ListNode *> heap;
        for(int i=0; i<K; i++)
        {
            if(lists[i]) heap.push_back(lists[i]);
        }
            
        make_heap(heap.begin(), heap.end(), cmpListNode);
        
        ListNode *ret = NULL, *cur = NULL;
        while(heap.size() > 0)
        {
            
            pop_heap(heap.begin(), heap.end(), cmpListNode);
            ListNode *temp = heap.back();
            if(ret == NULL) ret = heap.back();
            if(cur)
            {
                cur->next = heap.back();
                cur = cur->next;
            }
            else cur = heap.back();
            
            heap.pop_back();
            temp = temp->next;
            if(temp)
            {
                heap.push_back(temp);
                push_heap(heap.begin(), heap.end(), cmpListNode);
            }
        }
        return ret;
    }
};