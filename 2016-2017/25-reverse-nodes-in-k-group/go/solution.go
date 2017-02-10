/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
    dumpNode := &ListNode{}
    dumpNode.Next = head
    pre := dumpNode
    cur := pre.Next
    for cur != nil {
        var p *ListNode
        c := cur
        for i:=0;i<k;i++ {
            if c == nil{
                return dumpNode.Next
            }
            c = c.Next
        }
        c = cur
        for i:=0;i<k && c != nil;i++{
            tmp := c.Next
            c.Next = p 
            p = c
            c = tmp
        }
        pre.Next = p
        cur.Next = c
        pre = cur
        cur = c
    }
    return dumpNode.Next
}