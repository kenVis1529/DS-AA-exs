#include <random>
#include "Bai08.h"
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
int checkVal(LIST l, int x)
{
    NODE* p = l.pHead;
    while (p != NULL)
    {
        if (p->info == x) 
            return 1;
        p = p->pNext;
    }
    return 0;
}
int searchInt(LIST l, int x)
{
    NODE* p = l.pHead;
    while (p != NULL)
    {
        if (p->info == x)
            return 1;
    }
    return 0;
}
LIST giaoHaiDanhSach(LIST a, LIST b)
{
    //Duyệt list a
    //   duyệt list b, thêm vào danh sách mới thành phần của list a mà có trong b và chưa có trong ds mới
    LIST l1;
    Init(l1);
    NODE *p, *q;
    p = a.pHead;
    while (p != NULL)
    {
        q = b.pHead;
        while (q != NULL)
        {
            if (p->info == q->info && searchInt(l1, p->info) == 0)
            {
                addTail(l1, getNode(p->info));
                break;
            }
            q = q->pNext;
        }
        p = p->pNext;
    }
    return l1;
}
LIST hoiHaiDanhSach(LIST a, LIST b)
{
    //Duyệt list a
    //   duyệt list b, thêm vào ds mới thành phần của a chưa có trong b hoặc thành phần b chưa có trong a và chưa được duyệt trước đó
    NODE *p, *q;
    p = a.pHead;
    while (p != NULL)
    {
        q = b.pHead;
        while (q != NULL)
        {
            if (p->info == q->info)
            {
                break;
            }
            q = q->pNext;
        }
        if (q == NULL)
        {
            addTail(b, getNode(p->info));
        }
        p = p->pNext;
    }
    return b;
}