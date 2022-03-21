#include "Bai06.h"
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
NODE* getNode(MH x)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    else 
    {
        p->info = x;
        p->pNext = NULL;
    }
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
        l.pHead = p;
    }
}
void Input(LIST& l)
{
    int n;
    MatHang x;
    cout << "Nhập số lượng hàng: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {   
        cout << "Tên: \n";
        getline(cin, x.ten);
        cout << "Giá hàng:\n";
        cin >> x.gia;
        cout << "Số lượng còn lại trong kho:\n";
        cin >> x.soLuongTonKho;
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
        cout << "Tên: " << p->info.ten << endl;
        cout << "Giá: " << p->info.gia << endl;
        cout << "Số lượng còn trong kho: " << p->info.soLuongTonKho << endl;
        cout << endl;
        p = p->pNext;
    }
}
void sortGia(LIST& l)
{
    NODE* p = l.pHead;
    NODE* q = NULL;
    NODE* min = NULL;
    while (p != l.pTail)
    {
        min = p;
        q = p->pNext;
        while (q != NULL)
        {
            if (min->info.gia > q->info.gia)
                min = q;
            q = q->pNext;
        }
        NODE* temp = min;
        min->pNext = p->pNext;
        p->pNext = temp->pNext;
        p = p->pNext;
    }
}
int soSanhChuCai(string a, string b)
{

}
void sortTen(LIST& l)
{
    NODE* p = l.pHead;
    NODE* q = NULL;
    NODE* min = NULL;
    while (p != l.pTail)
    {
        min = p;
        q = p->pNext;
        while (q != NULL)
        {
            if (min->info.gia > q->info.gia)
                min = q;
            q = q->pNext;
        }
        NODE* temp = min;
        min->pNext = p->pNext;
        p->pNext = temp->pNext;
        p = p->pNext;
    }       
}
void sort(LIST& l)
{

}