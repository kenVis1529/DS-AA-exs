#include <iostream>

using namespace std;
//Phiếu đăng kí, không đăng kí nhiều hơn 1 lần
struct phieudk
{
    //Họ tên người mua
    string hoTenNguoiMua;
    //Số chứng minh nhân dân
    string cmnd;
    //Địa chỉ
    string diaChi;
    /*Số lượng vé đăng kí mua, mỗi người chỉ mua tối đa được 2 vé,
    chỉ bán vé khi còn ghế trống.*/
    int soVe;
};
typedef struct phieudk PHIEUDK;
struct node
{
    phieudk info;
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
NODE* getNode(string, string, string, int);
// void addHead(LIST &l, NODE* p);
void addTail(LIST &l, NODE* p);
void Output(LIST l);
//Random số vé đăng kí mua
int randomInt(int min, int max);
//Random tên
string randomStringLetters();
//Random cmnd
string randomStringDigits();
//Random địa chỉ
string randomString();
void initPhieuDK(LIST& l, int n);


