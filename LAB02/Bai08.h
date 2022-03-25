#include <iostream>
using namespace std;

struct Bai08
{
    /* data */
};
struct node
{
    int info;
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
void addTail(LIST &l, NODE* p);
int randomInt(int min, int max);
void initList(LIST& l, int n);
void Output(LIST l);
int checkVal(LIST l, int x);
int searchInt(LIST l, int x);
LIST giaoHaiDanhSach(LIST a, LIST b);
LIST hoiHaiDanhSach(LIST a, LIST b);