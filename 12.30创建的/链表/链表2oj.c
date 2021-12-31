#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

//移除指定元素

struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (head == NULL)
    {
        return head;
    }

    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = head->next;
    struct ListNode* returnlist = prev;

    int whether = 0;

    while (cur)
    {
        //找到与未找到两种不同处理方法
        if (cur->val == val)
        {
            //找到时，检查删除的是否为头结点
            if (prev == NULL)
            {
                //删头结点时，返回值需要改动，返回此时的next值
                whether = 1;
                returnlist = next;
            }
            if (prev)
            {
                prev->next = next;
            }
            free(cur);
            cur = next;
            if (next)
            {
                next = next->next;
            }
            continue;

        }
        //未找到时，正常迭代
        prev = cur;
        cur = next;
        if (next)
        {
            next = next->next;
        }
    }
    if (whether == 1)
    {
        return returnlist;
    }
    return head;
}

//剑指 Offer 22. 链表中倒数第k个节点

//struct ListNode* getKthFromEnd(struct ListNode* head, int k)
//{
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    int kcopy = k;
//    while(kcopy)
//    {
//        if(fast)
//        {
//            fast = fast->next;
//        }
//        kcopy--;
//    }
//    while(fast)
//    {
//        slow = slow->next;
//        fast = fast->next;
//    }
//    return slow;
//}