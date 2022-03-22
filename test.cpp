#include <iostream>
using namespace std;
int compare(string a, string b)
{
    int length = (a.length() > b.length()) ? b.length() : a.length();
    for (int i = 0; i < length; i++)
    {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return 0;
    }
    return (a.length() > b.length()) ? 1 : 0;
}

int main()
{
    string x = "kien";
    string y = "khanh";
    cout << compare(x, y);
    return 0;
}