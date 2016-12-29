/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    carry := 0
    root := &ListNode{Val:0}
    curNode := root
    for l1 != nil || l2 != nil || carry > 0 {
        val1 := 0
        val2 := 0
        if l1 != nil{
            val1 = l1.Val
            l1 = l1.Next
        }
        if l2 != nil{
            val2 = l2.Val
            l2 = l2.Next
        }
        s := val1 + val2 + carry
        newNode := &ListNode{Val:(s % 10)}
        carry = s / 10
        curNode.Next = newNode
        curNode = newNode
    }
    return root.Next
}