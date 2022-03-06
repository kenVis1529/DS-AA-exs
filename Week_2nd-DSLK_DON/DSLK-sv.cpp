//#include "List.h"
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
    node* pNext;
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


int main(){
    LIST l;
    Input(l);
    Ouput(l);
    return 0;
}


void Init(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
int IsEmpty(LIST l)
{
    if (l.pHead != NULL)
        return 1;
    return 0;
}
NODE* GetNode(SINHVIEN x)
{
    NODE* p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    return p;
}
void AddHead(LIST& l, NODE* p)
{
    if (l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void AddTail(LIST& l, NODE* p)
{
    if (l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = NULL;
        l.pTail = p;

    }
}
void Input(LIST& l)
{
    int n;
    cout << "Nhap n = ";
    cin >> n;
    Init(l);
    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        NODE* p = GetNode(x);
        if (p != NULL)
            AddHead(l, p);
    }
}   
void Ouput(LIST l)
{
    NODE* p = l.pHead;
    while (p != NULL){
        cout << p->info.TEN << "\t" << p->info.MSSV << "\t" << p->info.DTB << "\n";
        p = p->pNext;
    }
}
