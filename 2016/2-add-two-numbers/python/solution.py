# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = None
        flag = 0
        cur = None
        while l1:
            val1 = l1.val
            if not l2:
                flag, val = divmod(val1 + flag, 10)
            else:
                flag, val = divmod(val1 + l2.val + flag, 10)
                l2 = l2.next
            l1.val = val
            if cur:
                cur.next = l1
            else:
                head = l1
            cur = l1
            l1 = l1.next
        while l2:
            val2 = l2.val
            flag, val = divmod(val2 + flag, 10)
            l2.val = val
            if cur:
                cur.next = l2
            else:
                head = l2
            cur = l2
            l2 = l2.next
        if flag:
            newl = ListNode(flag)
            if cur:
                cur.next=newl
            else:
                head = newl
        return head