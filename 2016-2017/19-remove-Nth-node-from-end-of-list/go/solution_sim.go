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
    if end == nil {
        return head.Next
    }
    end = end.Next
    for end != nil {
        end = end.Next
        deleted = deleted.Next
    }
    deleted.Next = deleted.Next.Next
    return head
    
}