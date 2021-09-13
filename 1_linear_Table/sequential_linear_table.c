#include <stdio.h>

#define MAXSIZE 30

typedef int status;
typedef int elemType;

typedef struct SqList                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
{
    elemType data[MAXSIZE]; //数组
    int len;                //线性表长度
} SqList;

status initList(SqList *L)
{ //初始化
    L->len = 0;
    return 1;
}

status insertElement(elemType e, SqList *L) //插入数据
{
    if (L->len == MAXSIZE)
    {
        printf("插入失败，表已满！！");
        return 0;
    }
    else
    {
        L->data[L->len++] = e;
        return 1;
    }
}

status deletLastElement(SqList *L) //删除最后一个元素
{
    if (L->len == 0)
    {
        return 0;
    }
    else
    {
        L->len--;
        return 1;
    }
}

status deletEleByPosition(int position, SqList *L) //删除指定下标元素
{
    if (position > L->len)
    {
        return 0;
    }
    else
    {
        for (int i = position; i < L->len - 1; i++)
        {
            L->data[i] = L->data[i + 1];
        }
        L->len--;
        return 1;
    }
}

status listTraverse(SqList L) //遍历输出
{
    printf("表内元素：");
    for (int i = 0; i < L.len; i++)
        printf("%d ", L.data[i]);
    printf("\n");
    return 1;
}

void showListDetail(SqList L)
{
    printf("表的长度：%d; ", L.len);
    listTraverse(L);
}

elemType deletMinElem(SqList *L) //删除并返回最小元素(p17_1)
{
    if (L->len == 0)
    {
        printf("表为空无法执行删除操作");
        return 0;
    }
    else
    {
        int min = 0;
        int min_count = L->data[0];
        for (int i = 1; i < L->len; i++)
        {
            if (L->data[i] < min_count)
            {
                min = i;
                min_count = L->data[min];
            }
        }
        for (int i = min; i < L->len - 1; i++)
        {
            L->data[i] = L->data[i + 1];
        }
        L->len--;
        return min_count;
    }
}

status invert_List(SqList *L) //逆置所有元素(p17_2)
{
    if (L->len == 0)
    {
        return 0;
    }
    int temp;
    for (int i = 0; i < L->len / 2 + 1; i++)
    {
        if (i >= L->len - 1 - i)
        {
            break;
        }
        else
        {
            temp = L->data[i];
            L->data[i] = L->data[L->len - i - 1];
            L->data[L->len - i - 1] = temp;
        }
    }
    return 1;
}

status deletAllX(elemType x, SqList *L) //删除所有值为x的元素(p17_3)
{ 
    for (int i = 0; i < L->len; i++)
    {
        if (L->data[i] == x)
        {
            deletEleByPosition(i, L);
        }
    }
}

status deletOpenSectionCount(float s, float t, SqList *L) //删除指定开区间元素(p17_4)
{
    if (s > t || L->len == 0)
    {
        printf("请检查s，t的值或者表为空\n");
        return 0;
    }
    else
    {
        for (int i = 0; i < L->len; i++)
        {
            if (L->data[i] > s && L->data[i] < t)
            {
                deletEleByPosition(i, L);
            }
        }
        return 1;
    }
}

status deletCloseSectionCount(float s, float t, SqList *L) //删除指定闭区间元素(p17_5)
{
    if (s > t || L->len == 0)
    {
        printf("请检查s，t的值或者表为空\n");
        return 0;
    }
    else
    {
        for (int i = 0; i < L->len; i++)
        {
            if (L->data[i] >= s && L->data[i] <= t)
            {
                deletEleByPosition(i, L);
            }
        }
        return 1;
    }
}

status deletSortedListRepetitiveElem(SqList *L) //删除所有重复元素(p17_6)
{
    if (L->len == 0)
    {
        return 0;
    }
    if (L->len == 1)
    {
        return 1;
    }
    for (int i = 1; i < L->len; i++)
    {
        if (L->data[i - 1] == L->data[i])
        {
            deletEleByPosition(i, L);
        }
    }
    return 1;
}

SqList mergeDoubleSortedList(SqList L1, SqList L2) //合并两个有序表成新的有序表(p17_7)
{
    SqList L;
    initList(&L);
    int i, j = 0;
    for (; i < L1.len && j < L2.len;)
    {
        if (L1.data[i] < L2.data[j])
        {
            insertElement(L1.data[i++], &L);
        }
        else
        {
            insertElement(L2.data[j++], &L);
        }
    }
    for (; i < L1.len; i++)
    {
        insertElement(L1.data[i], &L);
    }
    for (; j < L2.len; j++)
    {
        insertElement(L2.data[j], &L);
    }
    return L;
}

int main(int argc, char const *argv[])
{
    SqList L, L1, L2;
    initList(&L);
    initList(&L1);
    initList(&L2);
    insertElement(11, &L);
    insertElement(9, &L);
    insertElement(0, &L);
    insertElement(1, &L);
    insertElement(5, &L);
    insertElement(3, &L);
    insertElement(1, &L);
    insertElement(3, &L);
    insertElement(4, &L);
    insertElement(5, &L);
    insertElement(88, &L);
    insertElement(1, &L);
    insertElement(1, &L1);
    insertElement(1, &L1);
    insertElement(2, &L1);
    insertElement(3, &L1);
    insertElement(3, &L1);
    insertElement(4, &L1);
    insertElement(1, &L2);
    insertElement(2, &L2);
    insertElement(3, &L2);
    insertElement(4, &L2);
    insertElement(5, &L2);
    insertElement(6, &L2);
    showListDetail(L1);
    showListDetail(L2);
    // printf("最小的元素：%d\n", deletMinElem(&L));
    // invert_List(&L);
    // deletAllX(1, &L);
    // deletOpenSectionCount(1,3,&L);
    // deletSortedListRepetitiveElem(&L1);
    showListDetail(mergeDoubleSortedList(L1, L2));
    showListDetail(L1);
    return 0;
}
