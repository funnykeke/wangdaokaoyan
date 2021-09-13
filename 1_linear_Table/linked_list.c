#include <stdio.h>
#include <stdlib.h>

typedef int status;
typedef int elemType;

typedef struct Lnode
{
    elemType data;
    struct Lnode *next;
} Lnode, *linkList;

typedef struct douNode
{
    struct douNode *next, *prior;
    elemType data;
} douNode, *douLinkList;

linkList initLinkListWithHead()
{
    Lnode *L = (linkList)malloc(sizeof(Lnode));
    L->next = NULL;
    L->data = 9999999;
    return L;
}

status headInsertCreatList(linkList L)
{
    int data;
    while (1)
    {
        printf("请输入插入节点值：");
        scanf("%d", &data);
        if (data == 999)
        {
            return 1;
        }
        Lnode *node = (Lnode *)malloc(sizeof(Lnode));
        node->data = data;
        node->next = L->next;
        L->next = node;
    }
    return 1;
}

status tailInsertCreatList(linkList L) //尾插法建表
{
    Lnode *r = L;
    int data;
    while (1)
    {
        printf("请输入插入节点值：");
        scanf("%d", &data);
        if (data == 999)
        {
            break;
        }
        Lnode *node = (Lnode *)malloc(sizeof(elemType));
        r->next = node;
        node->data = data;
        r = node;
        r->next = NULL;
    }
    return 1;
}

linkList creatLinkListWithoutHeadNode() //用来写题目的😁
{
    linkList L = initLinkListWithHead();
    tailInsertCreatList(L);
    *&L = *&L->next;
}

status linkListTraverse(linkList L) //遍历输出
{
    printf("链表数据:");
    if (L->data != 9999999) //处理不带头节点
    {
        printf("%d ", L->data);
    }
    while (L->next)
    {
        L = L->next;
        printf("%d ", L->data);
    }
    printf("\n");
    return 1;
}

Lnode *getElemByPosition(int position, linkList L) //按位置查找
{
    for (int i = 0; i < position; i++)
    {
        L = L->next;
        if (L == NULL)
        {
            return NULL;
        }
    }
    return L;
}

int getElemByData(elemType data, linkList L) //按值查找
{
    int count = 0;
    while (L->next != NULL)
    {
        count++;
        L = L->next;
        if (L->data == data)
        {
            return count;
        }
    }
    return 0;
}

status insertLnode(Lnode *node, int position, linkList L)
{
    if (position < 1)
    {
        printf("插入位置需大于0!!\n");
        return 0;
    }

    L = getElemByPosition(position - 1, L);
    if (!L)
    {
        printf("插入位置过大！！！\n");
    }
    node->next = L->next;
    L->next = node;
}

status deleteLnodeByPosition(int count, linkList L)
{
    if (L->next == NULL)
    {
        return 0;
    }

    if (count < 1)
    {
        printf("删除位置有误\n");
        return 0;
    }
    else
    {
        while (count - 1 > 0)
        {
            L = L->next;
            count--;
            if (L->next == NULL)
            {
                printf("删除位置大于链表现有长度\n");
                return 0;
            }
        }
        L->next = L->next->next;
        return 1;
    }
}

int len(linkList L)
{
    int count = 0;
    if (L->data != 9999999) //处理不带头节点
    {
        count++;
    }

    while (L->next)
    {
        L = L->next;
        count++;
    }
    return count;
}

status deletAllXWithoutHead(elemType x, linkList L) //递归删除带头节点所有值为x的节点(p37_1)
{
    if (L->next == NULL)
    {
        return 1;
    }
    if (L->data == x)
    {
        Lnode *p = L;
        L = L->next;
        free(p);
    }
    else
    {
        deletAllXWithoutHead(x, L->next);
    }
}

status deletAllX(elemType x, linkList L) //递归删除所有值为x的节点(p37_2)
{

    deletAllXWithoutHead(x, L); //不是一样吗
}

void reverseTraverse(linkList L) //反向输出(p38_3)
{
    linkList L_temp = initLinkListWithHead();
    while (L->next != NULL)
    {
        L = L->next;
        Lnode *node_temp = (Lnode *)malloc(sizeof(elemType));
        node_temp->data = L->data;
        node_temp->next = NULL;
        insertLnode(node_temp, 1, L_temp);
    }
    linkListTraverse(L_temp);
}

status deletMin(linkList L) //删除最小节点(p38_4)
{
    if (L->next == NULL)
    {
        return 0;
    }
    Lnode *node = L;
    Lnode *node_min_pre = L;
    Lnode *node_min = L->next;
    L = L->next;
    while (L->next)
    {
        node = L;
        L = L->next;
        if (L->data < node_min->data)
        {
            node_min_pre = node;
            node_min = L;
        }
    }
    node_min_pre->next = node_min->next;
    free(node_min);
}

int main(int argc, char const *argv[])
{
    linkList L = initLinkListWithHead();
    // linkList L1 = creatLinkListWithoutHeadNode();
    headInsertCreatList(L);
    // tailInsertCreatList(L);
    // linkListTraverse(L);
    Lnode *node = (Lnode *)malloc(sizeof(elemType));
    node->data = 999;
    node->next == NULL;
    insertLnode(node, 4, L);
    // printf("%d",getElemByPosition(4,L)->data);
    // printf("%d", getElemByData(4, L));
    deleteLnodeByPosition(3, L);
    // deletAllX(1, L);
    // printf("长度：%d\n", len(L));
    linkListTraverse(L);
    reverseTraverse(L);
    deletMin(L);
    linkListTraverse(L);
    return 0;
}