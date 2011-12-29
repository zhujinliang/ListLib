/* ************************************************************************
 *    Filename:  LinkList.c
 *  Programmer: ZhuJinliang
 * Description:  
 *     Version:  1.0
 *     Created:  2011/11/03
 *    Function: 
 *    Modified by ZhuJinliang 2011-11-8
 * ************************************************************************/
#include "LinkList.h"


/* *************************************************************************
 *     Name: InitList
 * Function: Initial the list, the head doesn't have data
 * Argument: 
 *   Return: PListNode pHead
 * ************************************************************************/
PListNode InitList(void)
{
    PListNode pHead = CreateNode();
    if (pHead == NULL)
    {
        return FAIL;
    }
    else
    {
        pHead->data = pHead;
        pHead->next = NULL;
    }
    return pHead;
}

/* *************************************************************************
 *     Name: CreateNode
 * Function: request a room to creat a blank node
 * Argument: void
 *   Return: PListNode
 * ************************************************************************/
PListNode CreateNode(void)
{
    PListNode pNode = (PListNode)malloc(sizeof(ListNode));    
    return pNode;
}

/* ************************************************************************
 *     Name: DeleteNode
 * Function: Delete a node
 * Argument: PListNode pHead, int position
 *   Return: int
 * ************************************************************************/
int DeleteNode(PListNode pHead, int position)
{
    PListNode newHead;
    PListNode preNode,delNode;
    
    if (pHead == NULL)
    {
        return FAIL;
    }
    else
    {
        if (position == 1)
        {
            if (pHead->next != NULL)
            {
                newHead = pHead->next;
                free(pHead);
                pHead = newHead;
            }
            else
            {
                free(pHead);
            }
        }
        else
        {
            preNode = FindNode(pHead, (position - 1));
            delNode = preNode->next;
            if (delNode->next == NULL)
            {
                preNode->next = NULL;
                free(delNode);
            }
            else                        // not the first or last node
            {
                preNode->next = delNode->next;
                free(delNode);
            }

        }
    }
    return TRUE;
}

/* ************************************************************************
 *     Name: DeleteList
 * Function: Delete a List
 * Argument: PListNode pHead
 *   Return: int
 * ************************************************************************/
int DeleteList(PListNode pHead)
{
    PListNode bufNode = NULL;
    PListNode curNode = NULL;
    bufNode = pHead;

    if (pHead == NULL)
    {
        return FAIL;
    }
    else
    {
        while (bufNode->next != NULL)
        {
            curNode = bufNode->next;
            free(bufNode);
            bufNode = curNode;
        }
        free(bufNode);
        pHead = NULL;
    
    }
    return TRUE;
}


/* ************************************************************************
 *     Name: AddTail
 * Function: add a node to the tail of the list
 * Argument: PListNode pHead, void *data
 *   Return: int
 * ***********************************************************************/
int AddTail(PListNode pHead, void *data)
{
    PListNode node = NULL;
    PListNode newNode;
    
    node = pHead;
    if (node == NULL)
    {
        return FAIL;
    }
    else
    {
        while ((node->next) != NULL)   // find the tail
        {
            node = node->next;
        }
    }

    newNode = CreateNode();
    if (newNode == NULL)
    {
        return FAIL;
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        node->next = newNode;
    }
    return TRUE;
}


/* ************************************************************************
 *     Name: InsertAfter
 * Function: insert a node after the node(position) in the list
 * Argument: PListNode pHead, int position, void *data
 *   Return: int
 * ***********************************************************************/
int InsertAfter(PListNode pHead, int position, void *data)
{
    PListNode preNode = NULL;
    PListNode curNode = NULL;
    
    if (pHead == NULL)
    {
        return FAIL;
    }
    else
    {
        preNode = FindNode(pHead, position);   // get the position of the node
        curNode = CreateNode();
        curNode->data = data;
        curNode->next = preNode->next;
        preNode->next = curNode;
    }
    return TRUE;
}


/* ************************************************************************
 *     Name: UpdateNode
 * Function: Update the data of a node in the list
 * Argument: PListNode pHead, int position, void *data
 *   Return: int
 * ***********************************************************************/
int UpdateNode(PListNode pHead, int position, void *data)
{
    PListNode curNode = NULL;

    if (pHead == NULL)
    {
        return FAIL;
    }
    else
    {
        curNode = FindNode(pHead, position);
        curNode->data = data;
    }
    return TRUE;
}

/* ************************************************************************
 *     Name: GetListCount
 * Function: Get the count of list
 * Argument: PListNode pHead
 *   Return: int  the count of List
 * ************************************************************************/
int GetListCount(PListNode pHead)
{
    int count = 1;
    PListNode node = pHead;

    if (node == NULL)
    {
        return 0;
    }
    else
    {
        while ((node->next) != NULL)
        {
            count ++;
            node = node->next;
        }
    }
    return count;  
}

/* ************************************************************************
 *     Name: FindNode
 * Function: Find the node in list
 * Argument: PListNode pHead
 *   Return: PListNode 
 * ************************************************************************/
PListNode FindNode(PListNode pHead, int position)
{
    int listCount = 1;
    PListNode node = pHead;
    if (pHead == NULL)
    {
        return FAIL;
    }
    else
    {
       while (node->next != NULL )
       {
           if (position == listCount)
           {
               break;
           }
           listCount ++;
           node = node->next;
       }
       return node;
    }
}


/* ************************************************************************
 *     Name: TraverseList
 * Function: traverse all the node in the list
 * Argument: PListNode pHead, void (*print)(void *)
 *   Return: PListNode
 * ************************************************************************/
PListNode TraverseList(PListNode pHead, void (*print)(void *))
{
    PListNode node = NULL;

    node = pHead;
    if (node == NULL)
    {
        return FAIL;
    }
    else
    {
        node = pHead->next;
        while (node != NULL)
        {
            (*print)(node->data);         // 通过函数指针来调用函数
            node = node->next;
        }
    }
    
}

/* ************************************************************************
 *     Name: SortList
 * Function: sort the data from big to small
 * Argument: PListNode pHead, int (*compare)(void *, void *)
 *   Return: int
 * ************************************************************************/
int SortList(PListNode pHead, int (*compare)(void *, void *))
{
    void *temp = NULL;
    PListNode pre = NULL;
    PListNode cur = NULL;

    for (pre=pHead->next; pre->next!=NULL; pre=pre->next)
    {
        for (cur=pre->next; cur!=NULL; cur=cur->next)
        {
            if ((*compare)(pre->data, cur->data) < 0)
            {
                temp = pre->data;
                pre->data = cur->data;
                cur->data = temp;
            }
        }
    }

}

/* ************************************************************************
 *     Name: SearchNode
 * Function: 
 * Argument: PListNode pHead, void *data, int (*compare)(void *, void *)
 *   Return: int
 * ************************************************************************/
PListNode SearchNode(PListNode pHead, void *data, int (*compare)(void *, void *))
{
    PListNode node = pHead;

    while (node) 
    {
        if (!(*compare)(node->data, data))
        {
            return node;
        }
        node = node->next;
    }
    return FAIL;
}



