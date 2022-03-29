#include <random>
#include "Bai09.h"
void Init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}
int isEmpty(LIST l)
{
    if (l.pHead == NULL)
        return 1;
    return 0;
}
NODE* getNode(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pPrev = NULL;
    p->pNext = NULL;
    return p;
}
void addHead(LIST &l, NODE* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else 
    {
        p->pNext = l.pHead;
        p->pPrev = NULL;
        l.pHead = p;
    }
}
void addTail(LIST &l, NODE* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else 
    {
        l.pTail->pNext = p;
        p->pPrev = l.pTail;
        l.pTail = p;
    }
}
void Output(LIST l)
{
    NODE* p = l.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}
int randomInt(int min, int max)
{
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}
void initList(LIST& l, int n)
{
    Init(l);
    int x;
    for (int i = 0; i < n; i++)
    {
        x = randomInt(0, 30);
        NODE* p = getNode(x);
        if (p != NULL)
            addTail(l, p);
    }
}
int lengthList(LIST l)
{
    int len = 0;
    NODE* p = l.pHead;
    while (p != NULL)
    {
        len++;
        p = p->pNext;
    }
    return len;
}
void daoNguocDuLieu(LIST& l)
{
    int len = lengthList(l);
    int mid = len / 2;
    int index = 1, temp;
    NODE* p = l.pHead;
    NODE* q = l.pTail;
    while (index <= mid)
    {
        temp = p->info;
        p->info = q->info;
        q->info = temp;
        p = p->pNext;
        q = q->pPrev;
        index++;
    }
}
void thayDoiLienKet(LIST& l)
{
    NODE* temp;
    NODE* p = l.pHead;
    while (p != NULL)
    {
        temp = p->pNext;
        p->pNext = p->pPrev;
        p->pPrev = temp;
        p = p->pPrev;
    }
    temp = l.pHead;
    l.pHead = l.pTail;
    l.pTail = temp;
}