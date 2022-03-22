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
void InputRandom(LIST& l);
void Output(LIST l);
//Random int
int randomInt(int min, int max);
//Random string
string randomTen();
//Xắp sếp
int sortGia(LIST& l);//Xếp theo giá
int soSanhTen(string, string);//So sánh tên
int sortTen(LIST& l);//Xếp theo tên
int sort(LIST& l);//Sắp xếp tăng dần theo giá, cùng giá thì xếp theo tên
//Lọc hàng theo giá
LIST filterSoLuong(LIST l, int min, int max);//In ra mặt hàng có số lượng > min and < max.