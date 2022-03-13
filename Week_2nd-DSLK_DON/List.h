#include <iostream>
using namespace std;
struct sinhvien
{
    /* data */
    char TEN[24];
    char MSSV[9];
    float DTB;
};
typedef struct sinhvien SINHVIEN;
struct node
{
    /* data */
    SINHVIEN info;
    struct node* pNext;
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
NODE* GetNode(SINHVIEN x);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
char RandomMSSV();
void Input(LIST& l);
void Output(LIST l);
int compareChar(char, char);
void Presence(LIST l);
void DelSV(LIST &l);
void List_Greater_5(LIST l);
void Classify_Grade(LIST l);