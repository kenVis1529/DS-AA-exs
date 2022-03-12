#include "List.h"
#include <iostream>
using namespace std;
//KHỞI TẠO
void Init(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
//KIỂM TRA DANH SÁCH RỖNG
int IsEmpty(LIST l)
{
    if (l.pHead != NULL)
        return 1;
    return 0;
}
//THÊM NODE VÀO DANH SÁCH
NODE* GetNode(SINHVIEN x)
{
    NODE* p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}
//THÊM NODE VÀO ĐẦU DANH SÁCH
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
//THÊM NODE VÀO ĐUÔI DANH SÁCH
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
//NHẬP
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
//XUẤT
void Ouput(LIST l)
{
    cout << "Tên\t|Mssv\t|Điểm Trung Bình\n";
    NODE* p = l.pHead;
    while (p != NULL){
        cout << p->info.TEN << "\t|" << p->info.MSSV << "\t|" << p->info.DTB << "\n";
        p = p->pNext;
    }
}
//TÌM 1 SINH VIÊN CÓ TRONG LỚP HAY KHÔNG?
void Presence(LIST l){
    cout << "Sinh viên cần điểm danh\n";
    NODE* p1 = new NODE;
    NODE* p = l.pHead;
    //Nhập
    cin.ignore();
    cout << "Mssv: \n";
    cin >> p1->info.MSSV;
    //Tiến hành kiểm tra
    while (p != NULL){
        if (p1->info.MSSV == p->info.MSSV){
            cout <<"Sinh viên " <<  p->info.TEN << " (" << p->info.MSSV << ") có mặt\n";
            break;    
        }
        p = p->pNext;
    }
    cout << "Sinh viên có mã số " << p1->info.MSSV << " vắng mặt\n";
}