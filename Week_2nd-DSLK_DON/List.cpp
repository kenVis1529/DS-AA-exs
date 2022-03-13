#include "List.h"
#include <iostream>
#include <time.h> //time()
#include <stdlib.h> //srand(), rand()
#include <charconv>
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
    if (l.pHead == NULL)
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
//CHỌN NGẪU NHIÊN MSSV
// char RandomMSSV()
// {
//     int min = 20000000, max = 30000000;
//     char mssv[9];
//     srand(time(NULL));
//     to_chars(mssv, 9, rand() % (max - min + 1) + min);
//     return mssv;
// }
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
        cin.getline(x.MSSV, 9);
        //x.MSSV = RandomMSSV();
        cout << "Nhập điểm trung bình: ";
        cin >> x.DTB;
        NODE* p = GetNode(x);
        if (p != NULL)
            AddHead(l, p);
        cout << endl;
    }
}   
//XUẤT
void Output(LIST l)
{
    cout << "Danh sách sinh viên: \n";
    cout << "Tên\t|Mssv\t\t|Điểm Trung Bình\n";
    NODE* p = l.pHead;
    while (p != NULL){
        cout << p->info.TEN << "\t|" << p->info.MSSV << "\t|" << p->info.DTB << "\n";
        p = p->pNext;
    }
    cout << endl;
}
//SO SÁNH 2 CHUỖI KÍ TỰ
int compareChar(char a[9], char b[9])
{
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return 1;
}
//TÌM 1 SINH VIÊN CÓ TRONG LỚP HAY KHÔNG?
void Presence(LIST l){
    cout << "Sinh viên cần điểm danh\n";
    int check = 0;
    char maSSV[9];
    NODE* p = l.pHead;
    //Nhập
    cin.ignore();
    cout << "Mssv: \n";
    cin.getline(maSSV, 9);
    //Tiến hành kiểm tra
    while (p != NULL){
        if (compareChar(maSSV, p->info.MSSV) == 1){
            cout <<"Sinh viên " <<  p->info.TEN << " (" << p->info.MSSV << ") có mặt\n\n";
            check = 1;
            break;
        }
        p = p->pNext;
    }
    if (check == 0) 
        cout << "Sinh viên có mã số " << maSSV << " vắng mặt\n\n";
}
//XÓA MỘT SINH VIÊN CÓ MSSV BẰNG X ( X NHẬP TỪ BÀN PHÍM)
void DelHead(LIST &l)//Sinh viên đầu danh sách
{
    l.pHead = l.pHead->pNext;
}
void DelSV(LIST &l)
{
    char x[9];
    cout << "Xóa sinh viên có mã số: \n";
    cin.getline(x, 9, '\n');
    NODE* p = l.pHead;
    if (IsEmpty(l) == 1)
    {    
        //Danh sách rỗng
        cout << "Không thể xóa, danh sách rỗng!\n";
    }
    else if (compareChar(x, p->info.MSSV) == 1)
    {
        //Đầu danh sách
        DelHead(l);   
        cout << "Đã xóa sinh viên có mã số " <<  p->info.MSSV << endl;  
    }
    else
    {    
        //Còn lại
        while (p->pNext != NULL)
        {
            if (compareChar(p->pNext->info.MSSV, x) == 1)
            {
                p->pNext = p->pNext->pNext;
                break;
            }
            p = p->pNext;
        }
        cout << "Đã xóa sinh viên có mã số " <<  p->info.MSSV << endl;
    }
    cout << endl;
}
//LIỆT KÊ THÔNG TIN CÁC SINH VIÊN CÓ DTB >= 5
void List_Greater_5(LIST l)
{
    cout << "Danh sách sinh viên có DTB >= 5: \n";
    cout << "Tên\t|MSSV\t\t|Điểm\n";
    NODE* p = l.pHead;
    while (p != NULL)
    {
        if (p->info.DTB >= 5.0)
            cout << p->info.TEN << "\t|" << p->info.MSSV << "\t|" << p->info.DTB << endl;
        p = p->pNext;
    }
    cout << endl;
}
