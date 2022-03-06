#include <iostream>
using namespace std;

struct sinhvien
{
    /* data */
    char TEN[20];
    char MSSV[8];
    float DTB;
};
typedef struct sinhvien SINHVIEN;
struct node
{
    /* data */
    SINHVIEN info;
    NODE* pNext;
};
typedef struct node NODE;
struct list
{
    /* data */
    NODE* pHead;
    NODE* pTail;
};
typedef struct list LIST;
void Init(LIST& l);
int IsEmpty(LIST& l, NODE* p);
NODE* GetNode(int x);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
void Input(LIST& l);
void Ouput(LIST l);
int Presence(char ten[20], char mssv[8]);

