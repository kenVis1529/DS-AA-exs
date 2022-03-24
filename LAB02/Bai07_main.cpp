#include "Bai07.cpp"

int main()
{    
    LIST l;
    Init(l);
    int n, x;
    char resume;
    //Chọn chức năng
    cout << "////////////////////////////////////////////////////////////////\n";
    cout << "//       MENU\n";
    cout << "// 1. Tạo danh sách 50.000 số nguyên ngẫu nhiên\n";
    cout << "// 2. Tính giá trị trung bình của các số nguyên trong danh sách\n";
    cout << "// 3. Kiểm tra các số nguyên có tăng hay giảm dần\n";
    cout << "////////////////////////////////////////////////////////////////\n\n";
    while (1)
    {
        cout << "Chọn một chức năng: \n"; 
        cin >> n;
        while (n < 1 || n > 4)
        {    
            cout << "Chọn lại chức năng: \n"; 
            cin >> n;
        }
        cout << endl;
        //Thực thi chức năng
        switch (n)
        {
        case 1:
            cout << "Tạo danh sách 50.000 số nguyên ngẫu nhiên\n";
            initInt(l);
            cout << endl;
            break;
        case 2:
            cout << "Tính giá trị trung bình của các số nguyên trong danh sách\n";
            cout << "- Trung bình = " << averageInt(l);
            cout << endl;
            break;
        case 3:
            cout << "Kiểm tra các số nguyên có tăng hay giảm dần\n";
            cout << "- Dãy các số nguyên ";
            x = ascendingOrDescending(l);
            switch (x)
            {
            case 1:
                cout << "tăng dần.\n";
                break;
            case 0:
                cout << "giảm dần.\n";
                break;
            case -1:
                cout << "không tăng cũng không giảm dần.\n";
                break;
            default:
                break;
            }
            cout << endl;
            break;
        default:
            break;
        }
        //Tiếp tục thực hiện các chức năng
        cout << "Bạn có muốn tiếp tục? ( y / n )\n";
        cin >> resume;
        while (resume != 'y' && resume != 'n')
        {
            cout << "Bạn có muốn tiếp tục? ( y / n )\n";
            cin >> resume;
        }
        if (resume == 'n') break; 
        cout << endl;
    }
}