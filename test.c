/* ************************************************************************
 *        Name: test.c
 *  Programmer: ZhuJinliang
 * Description:
 *     Version: 1.0
 *     Created: 2011-11-8
 *    Function:
 * ***********************************************************************/
#include "LinkList.h"


/* ************************************************************************
 *     Name: main
 * Function:
 * Argument:
 *   Return:
 * ***********************************************************************/
void main(void)
{
    PListNode pHead = NULL;
    PListNode pNode = NULL;
    char name[20][20] = {"America","London","China","England","Canada",
                          "Japan"};
    int i = 0;

    if (!(pHead = InitList()))
    {
        printf("init list failed!");
    }
    for (i=0; i<5; i++)
    {
        if (!AddTail(pHead, &name[i]))
        {
            printf("add node failed!");
        }
    }
    pNode = pHead->next;
    while (pNode != NULL)
    {
        printf("%s\n", (char*)pNode->data);
        pNode = pNode->next;
    }
    printf("List is created successfully!\n");
    //
    printf("update a node\n");
    if (!UpdateNode(pHead, 2, "Russia"))
    {
        printf("update failed\n");
    }
    pNode = pHead->next;
    while (pNode != NULL)
    {
        printf("%s\n", (char*)pNode->data);
        pNode = pNode->next;
    }
    // 
    printf("delete a node!\n");
    if (!DeleteNode(pHead, 3))
    {
        printf("delete failed\n");
    }
    pNode = pHead->next;
    while (pNode != NULL)
    {
        printf("%s\n", (char*)pNode->data);
        pNode = pNode->next;
    }
    //
    printf("insert affter");
    if (!InsertAfter(pHead, 2, "WuHan"))
    {
        printf("insert failed");
    }
    pNode = pHead->next;
    while (pNode != NULL)
    {
        printf("%s\n", (char*)pNode->data);
        pNode = pNode->next;
    }

}
