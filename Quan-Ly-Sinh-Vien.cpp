#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SinhVien {
public:
    string maSV;
    string hoTen;
    string ngaySinh;
    string gioiTinh;
    string nganh;
    string lop;
    float CPA;
    int namNhapHoc;
    int soTinChiHoanThanh;
    vector<float> GPAs;

    SinhVien() : maSV(""), hoTen(""), ngaySinh(""), gioiTinh(""), nganh(""), lop(""), CPA(0.0), namNhapHoc(0), soTinChiHoanThanh(0) {}

    void nhapThongTin() {
        cout << "Nhập mã sinh viên: ";
        cin >> maSV;
        cin.ignore();
        cout << "Nhập họ tên: ";
        getline(cin, hoTen);
        cout << "Nhập ngày sinh: ";
        getline(cin, ngaySinh);
        cout << "Nhập giới tính: ";
        getline(cin, gioiTinh);
        cout << "Nhập ngành học: ";
        getline(cin, nganh);
        cout << "Nhập lớp: ";
        getline(cin, lop);
        cout << "Nhập năm nhập học: ";
        cin >> namNhapHoc;
        cout << "Nhập số tín chỉ hoàn thành: ";
        cin >> soTinChiHoanThanh;

        if (!kiemTraTinChiHoanThanh()) {
            cout << "Số tín chỉ hoàn thành không đủ yêu cầu theo năm nhập học.\n";
        }

        nhapGPA();
        tinhCPA();
    }

    bool kiemTraTinChiHoanThanh() {
        if (namNhapHoc == 2023 && soTinChiHoanThanh < 49) {
            return true;
        } else if (namNhapHoc == 2022 && soTinChiHoanThanh < 97) {
            return true;
        } else if (namNhapHoc == 2021 && soTinChiHoanThanh < 121) {
            return true;
        } else if (namNhapHoc == 2020 && soTinChiHoanThanh < 133) {
            return true;
        }
        return false;
    }

    void nhapGPA() {
        int numSemesters = (2024 - namNhapHoc) * 2;
        GPAs.resize(numSemesters);
        for (int i = 0; i < numSemesters; ++i) {
            cout << "Nhập GPA kỳ " << (i + 1) << ": ";
            cin >> GPAs[i];
        }
    }

    void tinhCPA() {
        if (GPAs.empty()) return;
        float totalGPA = 0;
        for (const auto& gpa : GPAs) {
            totalGPA += gpa;
        }
        CPA = totalGPA / GPAs.size();
    }

    void hienThiThongTin() const {
        cout << "Mã SV: " << maSV << ", Họ tên: " << hoTen << ", Ngày sinh: " << ngaySinh << ", Giới tính: " << gioiTinh 
             << ", Ngành: " << nganh << ", Lớp: " << lop << ", CPA: " << CPA 
             << ", Năm nhập học: " << namNhapHoc << ", Số tín chỉ hoàn thành: " << soTinChiHoanThanh << endl;
    }

    string getMaSV() const {
        return maSV;
    }
};

class QuanLySinhVien {
private:
    vector<SinhVien> danhSachSinhVien;

public:
    void themSinhVien() {
        if (danhSachSinhVien.size() < 90) {
            SinhVien sv;
            sv.nhapThongTin();
            danhSachSinhVien.push_back(sv);
        } else {
            cout << "Không thể thêm sinh viên. Đã đạt tối đa 90 sinh viên." << endl;
        }
    }

    void capNhatSinhVien(string maSV) {
        for (auto& sv : danhSachSinhVien) {
            if (sv.getMaSV() == maSV) {
                sv.nhapThongTin();
                return;
            }
        }
        cout << "Không tìm thấy sinh viên có mã " << maSV << "." << endl;
    }

    void xoaSinhVien(string maSV) {
        auto it = remove_if(danhSachSinhVien.begin(), danhSachSinhVien.end(), [&](SinhVien& sv) { return sv.getMaSV() == maSV; });
        if (it != danhSachSinhVien.end()) {
            danhSachSinhVien.erase(it, danhSachSinhVien.end());
            cout << "Sinh viên có mã " << maSV << " đã bị xóa." << endl;
        } else {
            cout << "Không tìm thấy sinh viên có mã " << maSV << "." << endl;
        }
    }

    void hienThiSinhVienTheoMa(string maSV) const {
        for (const auto& sv : danhSachSinhVien) {
            if (sv.getMaSV() == maSV) {
                sv.hienThiThongTin();
                return;
            }
        }
        cout << "Không tìm thấy sinh viên có mã " << maSV << "." << endl;
    }

    void hienThiTatCaSinhVien() const {
        for (const auto& sv : danhSachSinhVien) {
            sv.hienThiThongTin();
        }
    }

    void sapXepTheoTen() {
        sort(danhSachSinhVien.begin(), danhSachSinhVien.end(), [](const SinhVien& a, const SinhVien& b) {
            return a.hoTen < b.hoTen;
        });
        hienThiTatCaSinhVien();
    }

    void sapXepTheoLop() {
        sort(danhSachSinhVien.begin(), danhSachSinhVien.end(), [](const SinhVien& a, const SinhVien& b) {
            return a.lop < b.lop;
        });
        hienThiTatCaSinhVien();
    }

    void sapXepTheoCPA() {
        sort(danhSachSinhVien.begin(), danhSachSinhVien.end(), [](const SinhVien& a, const SinhVien& b) {
            return a.CPA > b.CPA;
        });
        hienThiTatCaSinhVien();
    }
};

bool xacThuc(const string& tenDangNhap, const string& matKhau, string& vaiTro) {
    if (tenDangNhap == "sv" && matKhau == "sv6969") {
        vaiTro = "sinhvien";
        return true;
    } else if (tenDangNhap == "gv" && matKhau == "gvET2031") {
        vaiTro = "giangvien";
        return true;
    } else if (tenDangNhap == "phuhuynh" && matKhau == "phABC") {
        vaiTro = "phuhuynh";
        return true;
    } else if (tenDangNhap == "admin" && matKhau == "ad1234") {
        vaiTro = "phongdaotao";
        return true;
    }
    return false;
}

void menuSinhVien(QuanLySinhVien& qlsv) {
    int luaChon;
    while (true) {
          cout <<"_______________________________________\n";
          cout <<"|            MENU SINH VIÊN           |\n";
          cout <<"|   1. Nhập thông tin sinh viên       |\n";
          cout <<"|   2. Sửa/Xóa thông tin sinh viên    |\n";
          cout <<"|   3. Hiển thị thông tin sinh viên   |\n";
          cout <<"|   4. Sắp xếp danh sách SV theo lớp  |\n";
          cout <<"|   5. Sắp xếp danh sách SV theo tên  |\n";
          cout <<"|   6. Sắp xếp danh sách SV theo CPA  |\n"; 
          cout <<"|   7. Đăng xuất                      |\n";
          cout <<"|_____________________________________|\n";
        cout <<"Nhập lựa chọn của bạn: ";  
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            qlsv.themSinhVien();
            break;
        case 2: {
            string maSV;
            cout << "Nhập mã sinh viên để cập nhật hoặc xoá: ";
            cin >> maSV;
            cout << "Nhấn 1 để cập nhật hoặc 2 để xóa: ";
            int luaChonPhu;
            cin >> luaChonPhu;
            if (luaChonPhu == 1) {
                qlsv.capNhatSinhVien(maSV);
            } else if (luaChonPhu == 2) {
                qlsv.xoaSinhVien(maSV);
            } else {
                cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
            }
            break;
        }
        case 3:
            qlsv.hienThiTatCaSinhVien();
            break;
        case 4:
            qlsv.sapXepTheoLop();
            break;
        case 5:
            qlsv.sapXepTheoTen();
            break;
        case 6:
            qlsv.sapXepTheoCPA();
            break;
        case 7:
            return;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
        }
    }
}

void menuGiangVien(QuanLySinhVien& qlsv) {
    int luaChon;
    while (true) {
         cout <<"__________________________________\n";
        cout <<"|          MENU GIẢNG VIÊN         |\n";
        cout <<"| 1. Cập nhật thông tin sinh viên  |\n";
        cout <<"| 2. Sắp xếp danh sách SV theo lớp |\n";
        cout <<"| 3. Đăng xuất                     |\n";
        cout <<"|__________________________________|\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: {
            string maSV;
            cout << "Nhập mã sinh viên cần cập nhật thông tin: ";
            cin >> maSV;
            qlsv.capNhatSinhVien(maSV);
            break;
        }
        case 2:
            qlsv.sapXepTheoLop();
            break;
        case 3:
            return;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
        }
    }
}

void menuPhuHuynh(QuanLySinhVien& qlsv) {
    int luaChon;
    while (true) {
        cout <<"_______________________________________\n";
        cout <<"|          MENU PHỤ HUYNH             |\n";
        cout <<"| 1. Xem thông tin của sinh viên      |\n";
        cout <<"| 2. Xem danh sách sinh viên theo lớp |\n";
        cout <<"| 3. Xem danh sách sinh viên theo CPA |\n";
        cout <<"| 4. Đăng xuất                        |\n";
        cout <<"|_____________________________________|\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: {
            string maSV;
            cout << "Nhập mã sinh viên: ";
            cin >> maSV;
            qlsv.hienThiSinhVienTheoMa(maSV);
            break;
        }
        case 2:
            qlsv.sapXepTheoLop();
            break;
        case 3:
            qlsv.sapXepTheoCPA();
            break;
        case 4:
            return;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
        }
    }
}

void menuPhongDaoTao(QuanLySinhVien& qlsv) {
    int luaChon;
    while (true) {
        cout <<"______________________________________\n";
        cout <<"|         MENU PHÒNG ĐÀO TẠO         |\n";
        cout <<"|  1. Thêm tài khoản sinh viên       |\n";
        cout <<"|  2. Thêm thông tin sinh viên       |\n";
        cout <<"|  3. Xóa tài khoản sinh viên        |\n";
        cout <<"|  4. Đăng xuất                      |\n";
        cout <<"|____________________________________|\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: {
            // Chức năng thêm tài khoản sinh viên
            cout << "Chức năng này chưa được triển khai.\n";
            break;
        }
        case 2:
            qlsv.themSinhVien();
            break;
        case 3: {
            string maSV;
            cout << "Nhập mã sinh viên để xóa tài khoản: ";
            cin >> maSV;
            qlsv.xoaSinhVien(maSV);
            break;
        }
        case 4:
            return;
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
        }
    }
}

int main() {
    QuanLySinhVien qlsv;
    string tenDangNhap, matKhau, vaiTro;

    while (true) {
        
        cout <<"****************************************\n";
        cout <<"*****CHƯƠNG TRÌNH QUẢN LÝ SINH VIÊN*****\n";
        cout <<"****************************************\n";
        cout <<" ______________________________________\n";
        cout <<" |                MENU                 |\n";
        cout <<" |   1. Đăng Nhập                      |\n";
        cout <<" |   2. Thoát Chương Trình             |\n";
        cout <<" |_____________________________________|\n";
        
        cout <<"Nhập lựa chọn của bạn: ";
        int luaChon;
        cin >> luaChon;
        if (luaChon == 2) {
            break;
        }

        cout << "Nhập tài khoản: ";
        cin >> tenDangNhap;
        cout << "Nhập mật khẩu: ";
        cin >> matKhau;

        if (xacThuc(tenDangNhap, matKhau, vaiTro)) {
            if (vaiTro == "sinhvien") {
                menuSinhVien(qlsv);
            } else if (vaiTro == "giangvien") {
                menuGiangVien(qlsv);
            } else if (vaiTro == "phuhuynh") {
                menuPhuHuynh(qlsv);
            } else if (vaiTro == "phongdaotao") {
                menuPhongDaoTao(qlsv);
            }
        } else {
            cout << "Tài khoản hoặc mật khẩu không đúng.\n";
        }
    }

    return 0;
}
