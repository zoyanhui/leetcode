/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    deleted := head
    end := deleted
    for n > 0 && end != nil {
        end = end.Next
        n--
    }
    var pre *ListNode
    for end != nil {
        end = end.Next
        pre = deleted
        deleted = deleted.Next
    }
    if pre == nil {
        return head.Next
    }
    pre.Next = deleted.Next
    deleted.Next = nil
    return head
    
}