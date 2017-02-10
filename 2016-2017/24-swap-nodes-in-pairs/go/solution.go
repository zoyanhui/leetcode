/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    dumpNode := &ListNode{}
    dumpNode.Next = head
    pre := dumpNode
    cur := pre.Next
    for cur != nil && cur.Next != nil {
        pre.Next = cur.Next
        tmp := cur.Next.Next
        cur.Next.Next = cur
        cur.Next = tmp
        pre = cur
        cur = cur.Next
    }
    return dumpNode.Next
}