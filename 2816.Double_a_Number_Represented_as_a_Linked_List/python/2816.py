from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def doubleIt(head: Optional[ListNode]) -> Optional[ListNode]:
    
    temp = head
    temp_val = temp.val * 2
    
    if temp_val >= 10:
        head.val = temp_val - 10
        head = ListNode(val=1, next=head)
    else:
        head.val = temp_val
    
    while temp and temp.next:
        temp.next.val *= 2
        if temp.next.val >= 10:
            temp.val += 1
            temp.next.val -= 10
        temp = temp.next
    
    return head    
