#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Product {
    private:
        string id;
        string name;
        float price;
        int quantity;

    public:
        // Nhập thông tin sản phẩm
        void input() {
            cout << "Nhap ma san pham: ";
            cin >> id;

            cin.ignore();

            cout << "Nhap ten san pham: ";
            getline(cin, name);

            cout << "Nhap gia san pham: ";
            cin >> price;

            cout << "Nhap so luong: ";
            cin >> quantity;
        }

        // Hiển thị thông tin sản phẩm
        void output() const {
            cout << "Ma SP: " << id << endl;
            cout << "Ten SP: " << name << endl;
            cout << "Gia: " << price << endl;
            cout << "So luong: " << quantity << endl;
            cout << "-------------------------" << endl;
        }

        // Getter
        string getId() const {
            return id;
        }
        
        string getName() const {
            return name;
        }
        
        float getPrice() const {
            return price;
        }

        int getQuantity() const {
            return quantity;
        }

        // Sửa thông tin
        void update() {
            cin.ignore();

            cout << "Nhap ten moi: ";
            getline(cin, name);

            cout << "Nhap gia moi: ";
            cin >> price;

            cout << "Nhap so luong moi: ";
            cin >> quantity;
        }
};

class ProductManager {
    private:
        vector<Product> products;

    public:
        // Thêm sản phẩm
        void addProduct() {
            Product p;
            p.input();
            products.push_back(p);

            cout << "Them san pham thanh cong!\n";
        }

        // Hiển thị danh sách
        void showProducts() {
            if (products.empty()) {
                cout << "Danh sach rong!\n";
                return;
            }

            for (const Product& p : products) {
                p.output();
            }
        }

        // Tìm kiếm
        void searchProduct() {
            string id;

            cout << "Nhap ma san pham can tim: ";
            cin >> id;

            for (const Product& p : products) {
                if (p.getId() == id) {
                    cout << "\nTim thay san pham:\n";
                    p.output();
                    return;
                }
            }

            cout << "Khong tim thay san pham!\n";
        }

        // Xóa sản phẩm
        void deleteProduct() {
            string id;

            cout << "Nhap ma san pham can xoa: ";
            cin >> id;

            for (int i = 0; i < products.size(); i++) {
                if (products[i].getId() == id) {
                    products.erase(products.begin() + i);

                    cout << "Xoa thanh cong!\n";
                    return;
                }
            }

            cout << "Khong tim thay san pham!\n";
        }

        // Sửa sản phẩm
        void editProduct() {
            string id;

            cout << "Nhap ma san pham can sua: ";
            cin >> id;

            for (Product& p : products) {
                if (p.getId() == id) {
                    p.update();

                    cout << "Cap nhat thanh cong!\n";
                    return;
                }
            }

            cout << "Khong tim thay san pham!\n";
        }
        
        // Sắp xếp theo giá
        void sortByPrice() {
            sort(products.begin(), products.end(),
                [](const Product& a, const Product& b) {
                    return a.getPrice() < b.getPrice();
                });

            cout << "Da sap xep theo gia tang dan!\n";
            }

        // Sản phẩm sắp hết hàng
        void lowStockProducts() {
            bool found = false;

            cout << "\n===== SAN PHAM SAP HET HANG =====\n";

            for (const Product& p : products) {
                if (p.getQuantity() <= 5) {
                    p.output();
                    found = true;
                }
            }

            if (!found) {
                cout << "Khong co san pham nao sap het hang.\n";
            }
        }

        // Thống kê
        void statistics() {
            int totalQuantity = 0;

            for (const Product& p : products) {
                totalQuantity += p.getQuantity();
            }

            cout << "\n===== THONG KE =====\n";
            cout << "Tong so loai san pham: "
                << products.size() << endl;

            cout << "Tong so luong trong kho: "
                << totalQuantity << endl;
        }
};

int main() {
    ProductManager manager;
    int choice;

    do {
        cout << "\n===== QUAN LY SAN PHAM =====\n";
        cout << "1. Them san pham\n";
        cout << "2. Hien thi danh sach san pham\n";
        cout << "3. Tim kiem san pham\n";
        cout << "4. Xoa san pham\n";
        cout << "5. Sua san pham\n";
        cout << "6. Sap xep theo gia tang dan\n";
        cout << "7. Hien thi san pham sap het hang\n";
        cout << "8. Thong ke\n";
        cout << "9. Thoat\n";
        cout << "Lua chon: ";

        cin >> choice;

        switch (choice) {
            case 1:
                manager.addProduct();
                break;

            case 2:
                manager.showProducts();
                break;

            case 3:
                manager.searchProduct();
                break;

            case 4:
                manager.deleteProduct();
                break;

            case 5:
                manager.editProduct();
                break;

            case 6:
                manager.sortByPrice();
                break;

            case 7:
                manager.lowStockProducts();
                break;

            case 8:
                manager.statistics();
                break;

            case 9:
                cout << "Cam on ban da su dung chuong trinh!\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 9);

    return 0;
}