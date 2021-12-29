#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    //三结点循环法（迭代）第三个指针是为了存放第三结点地址，不然二指一时，无法寻找下一个
    struct ListNode* pnewhead = NULL;//新的头，起始作为尾，为空
    struct ListNode* pafter = head;
    struct ListNode* pafterafter = pafter->next;
    while (pafter)
    {
        pafter->next = pnewhead;//依次反转相邻两结点
        pnewhead = pafter;//后移一位
        pafter = pafterafter;
        if (pafterafter)//此处若不判定，最后一步会对空指针解引用，导致运行错误
        {
            pafterafter = pafterafter->next;
        }
    }
    return pnewhead;
}