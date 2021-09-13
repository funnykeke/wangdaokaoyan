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
    return L;
}

status headInsertCreatList(linkList *L)
{
    int data;
    while (1)
    {
        printf("请输入插入节点值：");
        scanf("%d", &data);
        if (data == 999)
        {
            break;
        }
        Lnode *L1 = (Lnode *)malloc(sizeof(Lnode));
        L1->data = data;
        L1->next = (*L)->next;
        (*L)->next = L1;
        return 1;
    }
}

status tailInsertCreatList(linkList *L) //尾插法建表
{
    Lnode *r = *L;
    int data;
    while (1)
    {
        printf("请输入插入节点值：");
        scanf("%d", &data);
        if (data == 999)
        {
            break;
        }
        Lnode *temp = (Lnode *)malloc(sizeof(elemType));
        r->next = temp;
        temp->data = data;
        r = temp;
        r->next = NULL;
    }
    return 1;
}

status linkListTraverse(linkList L) //遍历输出
{
    printf("链表数据:");
    if (L->data) //处理不带头节点
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
    Lnode *p = L;
    for (int i = 0; i < position; i++)
    {
        p = p->next;
        if (p == NULL)
        {
            return NULL;
        }
    }
    return p;
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

status insertLnode(Lnode *L1, int position, linkList *L)
{
    Lnode *s = *L;
    if (position < 1)
    {
        printf("插入位置需大于0!!\n");
        return 0;
    }
    else
    {
        Lnode *temp = getElemByPosition(position - 1, *L);
        if (temp)
        {
            s = temp;
        }
        else
        {
            printf("插入位置过大！！！\n");
        }
    }
    L1->next = s->next;
    s->next = L1;
}

status deleteLnodeByPosition(int count, linkList *L)
{
    if ((*L)->next == NULL)
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
        Lnode *temp = *L;
        while (count - 1 > 0)
        {
            temp = temp->next;
            count--;
            if (temp->next == NULL)
            {
                printf("删除位置大于链表现有长度\n");
                return 0;
            }
        }
        temp->next = temp->next->next;
        return 1;
    }
}

int len(linkList L)
{
    int count = 0;
    while (L->next)
    {
        L = L->next;
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    linkList L = initLinkListWithHead();
    // headInsertCreatList(&L);
    tailInsertCreatList(&L);
    linkListTraverse(L);
    // Lnode *node = (Lnode *)malloc(sizeof(elemType));
    // node->data = 999;
    // node->next == NULL;
    // insertLnode(node, 4, &L);
    // printf("%d",getElemByPosition(4,L)->data);
    // printf("%d", getElemByData(4, L));
    deleteLnodeByPosition(6, &L);
    printf("长度：%d\n", len(L));
    linkListTraverse(L);
    return 0;
}