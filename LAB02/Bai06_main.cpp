#include "Bai06.cpp"

int main()
{
    LIST l;
    Init(l);
    int n;
    char resume;
    //Chọn chức năng
    cout << "////////////////////////////////////////////////////////////////\n";
    cout << "//       MENU\n";
    cout << "// 1. Khai báo danh sách các mặt hàng\n";
    cout << "// 2. Sắp xếp danh sách mặt hàng theo giá tăng dần, nếu cùng giá thì sắp xếp theo tên\n";
    cout << "// 3. Các mặt hàng có số lượng trong kho lớn hơn x và nhỏ hơn y\n";
    cout << "// 4. Xuất danh sách\n";
    cout << "////////////////////////////////////////////////////////////////\n\n";
    while (1)
    {
        cout << "Chọn một chức năng: "; 
        cin >> n;
        while (n < 1 || n > 4)
        {    
            cout << "Chọn lại chức năng: "; 
            cin >> n;
        }
        
        //Thực thi chức năng
        switch (n)
        {
        case 1:
            // Input(l);
            InputRandom(l);
            cout << endl;
            break;
        case 2:
            if (isEmpty(l) == 1)
               cout << "Chưa khởi tạo danh sách.";
            else    
            {
                cout << "Sắp xếp danh sách mặt hàng";
                sort(l);
                Output(l);
                cout << endl;
            }
            break;
        case 3:
            if (isEmpty(l) == 1)
                cout << "Chưa khởi tạo danh sách.";
            else 
            {
                LIST l1;
                int x, y;
                cout << "Trích xuất mặt hàng có số lượng từ x đến y\n";
                cout << "Nhập x, y: \n";
                cin >> x >> y;
                l1 = filterSoLuong(l, x, y);
                Output(l1);
                cout << endl;
            }
            break;
        default:
            Output(l);
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