#include <random>
#include <cstring>
#include <algorithm>
#include "Bai10.h"
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
NODE* getNode(string hoten, string cmnd, string diachi, int ve)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->info.hoTenNguoiMua = hoten;
    p->info.cmnd = cmnd;
    p->info.diaChi = diachi;
    p->info.soVe = ve;
    // p->pPrev = NULL;
    p->pNext = NULL;
    return p;
}
// void addHead(LIST &l, NODE* p)
// {
//     if (l.pHead == NULL)
//         l.pHead = l.pTail = p;
//     else 
//     {
//         p->pNext = l.pHead;
//         // p->pPrev = NULL;
//         l.pHead = p;
//     }
// }
void addTail(LIST &l, NODE* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else 
    {
        l.pTail->pNext = p;
        // p->pPrev = l.pTail;
        l.pTail = p;
    }
}
void Output(LIST l)
{
    cout << "In danh sách người mua vé và số vé tương ứng được mua.\n";
    NODE* p = l.pHead;
    while (p != NULL)
    {
        cout << p->info.hoTenNguoiMua << "\t";
        cout << p->info.soVe << endl;
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
string randomStringLetters()
{
    string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghiklmnopqrstuvwxyz");
    random_device rd;
    mt19937 generator(rd());

    shuffle(str.begin(), str.end(), generator);

    char* s;
    string temp = str.substr(0, 12);
    s = new char[temp.length() + 1];
    strcpy_s(s, temp.length() + 1, temp.c_str());
    return s;
}
string randomStringDigits()
{
    string str("1234567890");
    random_device rd;
    mt19937 generator(rd());

    shuffle(str.begin(), str.end(), generator);

    char* s;
    string temp = str.substr(0, 10);
    s = new char[temp.length() + 1];
    strcpy_s(s, temp.length() + 1, temp.c_str());
    return s;
}
string randomString()
{
    string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghiklmnopqrstuvwxyz0123456789");
    random_device rd;
    mt19937 generator(rd());

    shuffle(str.begin(), str.end(), generator);

    char* s;
    string temp = str.substr(0, 12);
    s = new char[temp.length() + 1];
    strcpy_s(s, temp.length() + 1, temp.c_str());
    return s;
}
void initPhieuDK(LIST& l, int n)
{
    //10000 vé đăng kí
    //15000 số ghế ngồi
    Init(l);
    string hoTen, cmnd, diaChi;
    int soVe, tongVe = 0, tongNguoiDK = 0;
    for (int i = 0; i < n; i++)
    {
        hoTen = randomStringLetters();
        cmnd = randomStringDigits();
        diaChi = randomString();
        soVe = randomInt(1, 2);
        //Đảm bảo không quá số 15000 người ngồi
        if (tongNguoiDK + 1 <= 15000)
        {
            //Đảm bảo không quá 10000 vé được bán
            if (tongVe + soVe <= 10000)
            {
                tongVe += soVe;
                tongNguoiDK++;
                NODE* p = getNode(hoTen, cmnd, diaChi, soVe);
                if (p != NULL)
                {
                    addTail(l, p);
                }
            }
        }
        else break;
    }
}
