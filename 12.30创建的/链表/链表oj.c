#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};


//三指针迭代法反转单链表

//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL || head->next == NULL)
//    {
//        return head;
//    }
//    //三结点循环法（迭代）第三个指针是为了存放第三结点地址，不然二指一时，无法寻找下一个
//    struct ListNode* pnewhead = NULL;//新的头，起始作为尾，为空
//    struct ListNode* pafter = head;
//    struct ListNode* pafterafter = pafter->next;
//    while (pafter)
//    {
//        pafter->next = pnewhead;//依次反转相邻两结点
//        pnewhead = pafter;//后移一位
//        pafter = pafterafter;
//        if (pafterafter)//此处若不判定，最后一步会对空指针解引用，导致运行错误
//        {
//            pafterafter = pafterafter->next;
//        }
//    }
//    return pnewhead;
//}



//头插迭代法反转单链表

//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* cur = head;
//    struct ListNode* NewHead = NULL;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//        cur->next = NewHead;
//        NewHead = cur;
//        cur = next;
//    }
//}




//83. 删除排序链表中的重复元素（一遍过！）

//struct ListNode* deleteDuplicates(struct ListNode* head)
//{
//    if (head == NULL)
//    {
//        return head;
//    }
//    struct ListNode* prev = head;
//    struct ListNode* cur = head->next;
//    struct ListNode* pprev = prev;
//    while (cur)
//    {
//        if (cur->val == prev->val)
//        {
//            pprev = prev;
//            while (cur && cur->val == prev->val)
//            {
//                prev = cur;
//                cur = cur->next;
//            }
//            pprev->next = cur;
//            prev = head;
//            cur = head->next;
//            continue;
//        }
//        prev = cur;
//        cur = cur->next;
//    }
//    return head;
//}

//21. 合并两个有序链表

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    if (list1 == NULL || list2 == NULL)
//    {
//        if (list2 != NULL)
//        {
//            return list2;
//        }
//        else if (list1 != NULL)
//        {
//            return list1;
//        }
//        else
//            return NULL;
//    }
//    int lenlist1 = 0;
//    struct ListNode* cur1 = list1;
//    while (cur1)
//    {
//        cur1 = cur1->next;
//        lenlist1++;
//    }
//
//    int lenlist2 = 0;
//    struct ListNode* cur2 = list2;
//    while (cur2)
//    {
//        cur2 = cur2->next;
//        lenlist2++;
//    }
//
//    int minlen = lenlist1 < lenlist2 ? lenlist2 : lenlist2;
//    int whether = 0;
//    
//
//        if (minlen == lenlist1)
//        {
//            struct ListNode* prev_maxlen = NULL;
//            struct ListNode* curminlen = list1;
//            struct ListNode* curmaxlen = list2;
//
//            struct ListNode* minlen_next = list1->next;
//           
//            struct ListNode* returnlist = curminlen;
//
//            while (minlen)
//            {
//                while (curmaxlen && curminlen->val >= curmaxlen->val)
//                {
//                    prev_maxlen = curmaxlen;
//                    curmaxlen = curmaxlen->next;
//                    
//                }
//                if (prev_maxlen == NULL)
//                {
//                    whether = 1;
//                    returnlist = curminlen;
//                }
//                if (prev_maxlen)
//                {
//                    prev_maxlen->next = curminlen;
//                    
//                }
//                curminlen->next = curmaxlen;
//                curmaxlen = curminlen;
//                
//                curminlen = minlen_next;
//                if (curminlen)
//                {
//                    minlen_next = curminlen->next;
//                }
//                minlen--;
//            }
//            if (whether == 1)
//            {
//                return returnlist;
//            }
//            return list2;
//        }
//        else
//        {
//            struct ListNode* prev_maxlen = NULL;
//            struct ListNode* curminlen = list2;
//            struct ListNode* curmaxlen = list1;
//            struct ListNode* minlen_next = list2->next;
//            struct ListNode* maxlen_next = list1->next;
//            struct ListNode* returnlist = curminlen;
//            while (minlen)
//            {
//                while (curmaxlen && curminlen->val >= curmaxlen->val)
//                {
//                    prev_maxlen = curmaxlen;
//                    curmaxlen = curmaxlen->next;
//
//                }
//                if (prev_maxlen == NULL)
//                {
//                    whether = 1;
//                    returnlist = curminlen;
//                }
//                if (prev_maxlen)
//                {
//                    prev_maxlen->next = curminlen;
//                    
//                }
//                
//                curminlen->next = curmaxlen;
//                curmaxlen = curminlen;
//
//                curminlen = minlen_next;
//                if (curminlen)
//                {
//                    minlen_next = curminlen->next;
//                }
//                minlen--;
//            }
//            if (whether == 1)
//            {
//                return returnlist;
//            }
//            return list1;
//        }
//}


