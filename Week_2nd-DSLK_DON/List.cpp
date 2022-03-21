#include "List.h"
#include <iostream>
#include <time.h> //time()
#include <stdlib.h> //srand(), rand()
#include <charconv> //to_chars()
using namespace std;
//KHỞI TẠO
void Init(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
//-------------------------------
//KIỂM TRA DANH SÁCH RỖNG
int IsEmpty(LIST l)
{
    if (l.pHead == NULL)
        return 1;
    return 0;
}
//-------------------------------
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
//-------------------------------
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
//-------------------------------
//THÊM NODE VÀO ĐUÔI DANH SÁCH
void AddTail(LIST& l, NODE* p)
{
    if (l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
//-------------------------------
//NHẬP
void Input(LIST& l)
{
    int n;
    cout << "Nhap n = ";
    cin >> n;
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
//-------------------------------
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
//-------------------------------
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
//-------------------------------
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
//-------------------------------
//XÓA MỘT SINH VIÊN CÓ MSSV BẰNG X ( X NHẬP TỪ BÀN PHÍM)
int DelHead(LIST &l)//Sinh viên đầu danh sách
{
    if (l.pHead != NULL)
    {
        NODE* p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        return 1;
    }
    return 0;
}
void DelSV(LIST &l)
{
    char x[9];
    int check = 0;
    cout << "Xóa sinh viên có mã số: \n";
    cin.getline(x, 9, '\n');
    NODE* p = l.pHead;
    if (IsEmpty(l) == 1)
    {    
        //Danh sách rỗng
        cout << "Danh sách rỗng!\n";
    }
    else if (x == "")
    {
        cout << "Không xóa sinh viên nào.\n";
    }
    else if (compareChar(x, p->info.MSSV) == 1)
    {
        //Đầu danh sách
        check = DelHead(l);   
        cout << "Đã xóa sinh viên có mã số " <<  p->info.MSSV << endl;  
    }
    else
    {    
        //Còn lại
        while (p->pNext != NULL)
        {
            if (compareChar(p->pNext->info.MSSV, x) == 1)
            {
                NODE* p1 = p->pNext;
                p->pNext = p->pNext->pNext;
                delete p1;
                check = 1;
                cout << "Đã xóa sinh viên có mã số " <<  p->info.MSSV << endl;
                break;
            }
            p = p->pNext;
        }
    }
    if (check == 0) 
        cout << "Không có sinh viên trong danh sách\n";
    cout << endl;
}
//-------------------------------
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
//-------------------------------
//XẾP LOẠI VÀ IN RA THÔNG TIN CỦA TỪNG SINH VIÊN

//Xếp loại 1 sinh viên
string Classification(float grade)
{
    string cl;
    if (grade <= 3.6)
        cl = "Loại yếu";
    else if (grade < 5.0)
        cl = "Không có xếp loại";// Không có xếp loại
    else if (grade < 6.5)
        cl = "Loại trung bình";
    else if (grade < 7.0)
        cl = "Loại trung bình khá";
    else if (grade < 8.0)
        cl = "Loại khá";
    else if (grade < 9.0)
        cl = "Loại giỏi";
    else if (grade <= 10.0)
        cl = "Loại xuất sắc";
    return cl;
}
//Xép loại và in thông tin sinh viên
void Classify_Grade(LIST l)
{
    NODE* p = l.pHead;
    cout << "Thông tin sinh viên và xếp loại: \n";
    cout << "Tên\t|MSSV\t\t|Điểm\t|Xếp loại\n";
    while (p != NULL)
    {

        cout << p->info.TEN << "\t|" << p->info.MSSV << "\t|" << p->info.DTB << "\t|" << Classification(p->info.DTB) << endl;
        p = p->pNext;
    }
    cout << endl;
}
//-------------------------------
//SẮP XẾP VÀ IN RA DANH SÁCH SINH VIÊN TĂNG THEO ĐIỂM TRUNG BÌNH.
//Sắp xếp 
void Sort(LIST& l)
{
    NODE* p, *p1, *min;
    p = l.pHead;
    while (p != l.pTail)
    {
        p1 = p->pNext;
        while (p1 != NULL)
        {
            if (p->info.DTB > p1->info.DTB)
                min = p1;
            p1 = p1->pNext;
        }
        SINHVIEN temp = p->info;
        p->info = min->info;
        min->info = temp;
        p = p->pNext;
    }
}
//In danh sách
void Sort_DTB(LIST& l)
{
    Sort(l);
    cout << "Thông tin sinh viên theo thứ tự DTB tăng dần: \n";
    cout << "Tên\t|MSSV\t\t|Điểm\n";
    NODE* p = l.pHead;
    while (p != NULL)
    {
        cout << p->info.TEN << "\t|" << p->info.MSSV << "\t|" << p->info.DTB << endl;
        p = p->pNext;
    }
    cout << endl;
}
//CHÈN 1 SV VÀO DANH SÁCH SV TĂNG THEO ĐIỂM TB NÓI TRÊN
void Insert(LIST&l, NODE* p1)
{
    //Tìm vị trí chèn trong danh sách
    NODE* p, *q;
    p = l.pHead;
    if (p == NULL)
    {
        AddHead(l, p1);
    }
    else
    {
        while (p != l.pTail)
        {
            q = p->pNext;
            if (p->info.DTB <= p1->info.DTB && p1->info.DTB <= q->info.DTB)
                break;
            p = p->pNext;
        }
        p1->pNext = p->pNext;
        p->pNext = p1;
        if (p == l.pTail) 
            l.pTail = p1;
    }
}
void InsertSV(LIST&l)
{
    //Nhập info 
    //Chèn SV mới 
    //  Tìm vị trí để chèn (prev.dtb < x.dtb < next.dtb)
    //  Thêm SV mới ngay sau prev
    ////////////////////////

    //Nhập thông tin SV mới
    SINHVIEN x;
    cin.ignore();
    cout << "Nhập thông tin sinh viên mới: \n";
    cout << "Nhập tên: ";
    cin.getline(x.TEN, 24);
    cout << "Nhập mssv: ";
    cin.getline(x.MSSV, 9);
    cout << "Nhập điểm trung bình: ";
    cin >> x.DTB;
    NODE* p1 = GetNode(x);
    //Chèn SV mới
    Insert(l, p1);
    cout << endl;
}