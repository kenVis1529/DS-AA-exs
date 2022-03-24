#include <algorithm>
#include <random>
#include <string.h>
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
void Input(LIST& l)
{
    int n;
    MatHang x;
    cout << "Nhập số lượng hàng: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {   
        cin.ignore();
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
void InputRandom(LIST& l)
{
    Init(l);
    int n;
    MatHang x;
    cout << "Nhập n:\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string ten = randomTen();
        int gia = randomInt(5000, 30000);
        int soLuong = randomInt(5, 30);
        x.ten = ten;
        x.gia = gia;
        x.soLuongTonKho = soLuong;
        NODE* p = getNode(x);
        if (p != NULL)
            addTail(l, p);
        p = p->pNext;
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
int randomInt(int min, int max)
{
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}
string randomTen()
{
    string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghiklmnopqrstuvwxyz");
    random_device rd;
    mt19937 generator(rd());

    shuffle(str.begin(), str.end(), generator);

    char* s;
    string temp = str.substr(0, 10);
    s = new char[temp.length() + 1];
    strcpy_s(s, temp.length() + 1, temp.c_str());
    return s;
}
int sortGia(LIST& l)
{
    if (isEmpty(l) == 1)
        return 0;
    NODE *p, *q, *min;
    p = l.pHead;
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
        MH temp = min->info;
        min->info = p->info;
        p->info = temp;
        p = p->pNext;
    }
    return 1;
}
int soSanhTen(string a, string b)
{
    //Tìm độ dài string ngắn hơn
    //So sánh các chữ cái từ trái - phải
    int length = (a.length() > b.length()) ? b.length() : a.length();
    for (int i = 0; i < length; i++)
    {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return 0;
    }
    return (a.length() > b.length()) ? 1 : 0;
}
int sortTen(LIST& l)
{
    if (isEmpty(l) == 1)
        return 0;
    else
    {
        NODE *p, *q, *min;
        p = l.pHead;
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
            MH temp = min->info;
            min->info = p->info;
            p->info = temp;
            p = p->pNext;
        }       
        return 1;
    }
}
int sort(LIST& l)
{
    if (isEmpty(l) == 1)
        return 0;
    else
    {
        sortGia(l);
        NODE *p, *q;
        p = l.pHead;
        if (l.pHead == l.pTail) return 1;
        while (p != l.pTail)
        {
            q = p->pNext;
            while (p->info.gia == q->info.gia)
            {
                if (soSanhTen(p->info.ten, q->info.ten) == 1)
                {
                    MH temp = p->info;
                    p->info = q->info;
                    q->info = temp;
                }
                q = q->pNext;
            }
            p = p->pNext;
        }
        return 1;
    }
}
LIST filterSoLuong(LIST l, int min, int max)
{
    //Duyệt danh sách, tìm mặt hàng thõa số lượng > min và < max
    LIST l1;
    Init(l1);
    NODE* p = l.pHead;
    while (p != NULL)
    {
        if (p->info.soLuongTonKho > min && p->info.soLuongTonKho < max)
        {
            addTail(l1, p);
        }
        p = p->pNext;
    }
    return l1;
}