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
void initList(LIST& l, int n);
int lengthList(LIST l);
void daoNguocDuLieu(LIST& l);
void thayDoiLienKet(LIST& l);