#include "Bai08.cpp"

int main()
{
    LIST l1, l2, giao, hoi;
    Init(l1);
    Init(l2);
    Init(giao);
    Init(hoi);
    int n, x;
    char resume;
    //Chọn chức năng
    cout << "///////////////////////////////////////////////\n";
    cout << "//              MENU\n";
    cout << "// 1. Khởi tạo ngẫu nhiên 2 danh sách.\n";
    cout << "// 2. Phần giao của hai danh sách liên kết.\n";
    cout << "// 3. Phần hợp của hai danh sách liên kết.\n";
    cout << "// 4. In hai danh sách đã khởi tạo.\n";
    cout << "///////////////////////////////////////////////\n\n";
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
            cout << "Khởi tạo ngẫu nhiên 2 danh sách\n";
            initList(l1, 5);
            initList(l2, 5);
            cout << "- Đã khởi tạo 2 danh sách gồm 5 số nguyên từ 0 đến 30.\n";
            cout << endl;
            break;
        case 2:
            cout << "Phần giao của hai danh sách liên kết\n";
            giao = giaoHaiDanhSach(l1, l2);
            Output(giao);
            cout << endl;
            break;
        case 3:
            cout << "Phần hợp của hai danh sách liên kết\n";
            hoi = hoiHaiDanhSach(l1, l2);
            Output(hoi);
            cout << endl;
            break;
        case 4:
            cout << "In hai danh sách đã khởi tạo\n";
            cout << "- Danh sách 1:\n";
            Output(l1);
            cout << "- Danh sách 2:\n";
            Output(l2);
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