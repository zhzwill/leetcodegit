class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode *p,*q;
        p = headA;
        while(p->next != NULL)
            p = p->next;
        p->next = headB;
        int countA,countB;
        countB = yuanhuan(headA);
        if(countB == -1)
        {
            p->next = NULL;
            return NULL;
        }
        p->next = headA;
        countA = yuanhuan(headB);
        int count;
        count = abs(countA-countB);
        p->next = NULL;
        p = headA;
        q = headB;
        int i;
        i = 0;
        if(countA>countB)
        {
            while(i != count)
            {
                p = p->next;
                i++;
            }
        }
        else
        {
            while(i != count)
            {
                q = q->next;
                i++;
            }
        }
        while(p != q)
        {
            p = p->next;
            q = q->next;
        }
        return q;
    }
    int yuanhuan(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
            return -1;
        ListNode *q,*p;
        p = head->next;
        q = head->next->next;
        int count;
        while(q != NULL)
        {
            if(p == q)
                break;
            if(q->next == NULL)
                return -1;
            p = p->next;
            q = q->next->next;
        }
        if(q == NULL)
            return -1;
        p = p->next;
        q = q->next->next;
        count = 1;
        while(p != q)
        {
            p = p->next;
            q = q->next->next;
            count++;
        }
        return count;
    }
};