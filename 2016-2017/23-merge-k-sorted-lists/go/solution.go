/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 
import "container/heap"
type PriorityQueue []*ListNode

func (pq PriorityQueue) IsEmpty() bool {
    return len(pq) == 0
}

func (pq *PriorityQueue) Push(x interface{}) {
    *pq = append(*pq, x.(*ListNode)) 
}

func (pq *PriorityQueue) Pop() interface{} {
    old := *pq
    n := len(old) 
    if n == 0 {
        return nil
    }
    x := old[n-1]  
    *pq = old[0 : n-1]  
    return x 
}

func (pq PriorityQueue) Len() int {
    return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
    I := pq[i]
    J := pq[j]
    return I.Val < J.Val
}

func (pq PriorityQueue) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
}

func mergeKLists(lists []*ListNode) *ListNode {
    h := &PriorityQueue{}  
    heap.Init(h)
    for _, listHead := range lists {
        if listHead != nil {
            heap.Push(h, listHead)
        }
    }
    dumpNode := &ListNode{}
    cur := dumpNode
    for !h.IsEmpty(){
        next := heap.Pop(h).(*ListNode)
        if next != nil {
            cur.Next = next
            cur = cur.Next
            if next.Next != nil {
                heap.Push(h, next.Next)
            }
        }
    }
    return dumpNode.Next
}