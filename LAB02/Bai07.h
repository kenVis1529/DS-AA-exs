#include <iostream>
using namespace std;

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
void addHead(LIST &l, NODE* p);
void addTail(LIST &l, NODE* p);
//Tạo danh sách 50.000 số nguyên ngẫu nhiên
int randomInt(int min, int max);
void initInt(LIST& l);
//Tính giá trị trung bình của các số nguyên trong danh sách
float averageInt(LIST l);
//Kiểm tra các số nguyên có tăng hay giảm dần
int ascendingOrDescending(LIST l);


