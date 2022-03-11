#include "List.h"
#include <iostream>
using namespace std;
void Init(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
int IsEmpty(LIST l)
{
    if (l.pHead != NULL)
        return 1;
    return 0;
}
NODE* GetNode(SINHVIEN x)
{
    NODE* p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}
void AddHead(LIST& l, NODE* p)
{
    if (l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void AddTail(LIST& l, NODE* p)
{
    if (l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = NULL;
        l.pTail = p;
    }
}
void Input(LIST& l)
{
    int n;
    cout << "Nhap n = ";
    cin >> n;
    Init(l);
    for (int i = 0; i < n; i++){
        SINHVIEN x;
        cin.ignore();
        cout << "Nhập tên: ";
        cin.getline(x.TEN, 24);
        cout << "Nhập mssv: ";
        cin.getline(x.MSSV, 10);
        cout << "Nhập điểm trung bình: ";
        cin >> x.DTB;
        NODE* p = GetNode(x);
        if (p != NULL)
            AddHead(l, p);
    }
}   
void Ouput(LIST l)
{
    cout << "Tên\t|Mssv\t|Điểm Trung Bình\n";
    NODE* p = l.pHead;
    while (p != NULL){
        cout << p->info.TEN << "\t|" << p->info.MSSV << "\t|" << p->info.DTB << "\n";
        p = p->pNext;
    }
}
void Presence(LIST l){
    cout << "Nhập danh sách điểm danh\n";
    LIST l1;
    Input(l1);
    NODE* p1 = l1.pHead;
    NODE* p =l.pHead;
    cout << "Tên\t|Mssv\t|Hiện diện\n";
    while (p1 != NULL){
        cout << p1->info.TEN << "\t|" << p1->info.MSSV;
        while (p != NULL){
            if ((p1->info.TEN == p->info.TEN) or (p1->info.MSSV == p->info.MSSV)){
                cout << "\t|Có mặt\n";
                break;  
            }
            p = p->pNext;
        }
        cout << "\t|Vắng mặt\n";
        p1 = p1->pNext;
    }
}