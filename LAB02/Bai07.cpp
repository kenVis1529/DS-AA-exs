#include <random>
#include "Bai07.h"
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
        l.pTail = p;
    }
}
int randomInt(int min, int max)
{
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}
void initInt(LIST& l)
{
    Init(l);
    int n = 50000, x;
    for (int i = 0; i < n; i++)
    {
        x = randomInt(0, 50000);
        NODE* p = getNode(x);
        if (p != NULL)
            addTail(l, p);
    }
}
float averageInt(LIST l)
{
    NODE* p = l.pHead;
    double sum = 0;
    while (p != NULL)
    {
        sum += p->info;
    }
    return sum * 1.0 / 50000;
}
int ascendingOrDescending(LIST l)
{
    //ascending
    //   p->info < p->pNext->info
    //descending
    //   p->info > p->pNext->info

    NODE* p = l.pHead;
    int count1 = 0, count2 = 0;
    while (p != l.pTail)
    {
        if (p->info <= p->pNext->info)
            count1++;
        if (p->info >= p->pNext->info)
            count2++;
        p = p->pNext;
    }
    if (count1 == 49999)
        return 1;
    else if (count2 == 49999)
        return 0;
    else 
        return -1;

}