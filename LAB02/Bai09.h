#include <iostream>
using namespace std;

struct node
{
    int info;
    node* pPrev;
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
NODE* getNode(int x);
void addHead(LIST &l, NODE* p);
void addTail(LIST &l, NODE* p);
void Output(LIST l);
int randomInt(int min, int max);
//Khởi tạo ngẫu nhiên n số nguyên
void initList(LIST& l, int n);
//Tính độ dài danh sách
int lengthList(LIST l);
//Đảo ngược dữ liệu
void daoNguocDuLieu(LIST& l);
//Đảo ngược bằng cách thay đổi liên kết
void thayDoiLienKet(LIST& l);