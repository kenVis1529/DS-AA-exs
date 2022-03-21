#include <iostream>
#include <string>
using namespace std;

struct MatHang
{
    string ten;
    float gia;
    int soLuongTonKho;
};
typedef struct MatHang MH;
struct node
{
    MatHang info;
    node* pNext;
};
typedef struct node NODE;
struct list
{
    NODE* pHead;
    NODE* pTail;
};
typedef struct list LIST;

void Init(LIST &l);
int isEmpty(LIST l);
NODE* getNode(MH x);
void addHead(LIST &l, NODE* p);
void addTail(LIST &l, NODE* p);
void Input(LIST& l);
void Output(LIST l);
void sortGia(LIST& l);//Xếp theo giá
int soSanhChuCai(string, string);//So sánh tên
void sortTen(LIST& l);//Xếp theo tên
void sort(LIST& l);//Sắp xếp tăng dần theo giá, cùng giá thì xếp theo tên
