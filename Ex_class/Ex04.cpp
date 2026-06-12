#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Product {
private:
    string name;
    double price;
    int quantity;
public:
    Product() {
        setName("Unknown");
        price = 0.0;
        quantity = 0;
    }
    Product(string n, double p) {
        setName(n);
        price = p;
        quantity = 1;
    }
    Product(string n, double p, int q) {
        setName(n);
        price = p;
        quantity = q;
    }
    string getName() const {
        return name;
    }
    void setName(string n) {
        if (!n.empty()) {
            name = n;
        } else {
            cout << "Loi: Ten san pham khong duoc de trong!" << endl;
        }
    }
    double totalValue() const {
        return price * quantity;
    }
    void display() const {
        cout << "San pham: " << getName() << " | Gia: " << price 
             << " | So luong: " << quantity << " | Tong gia tri: " << totalValue() << endl;
    }
};

int main() {
    Product p1;                    
    Product p2("Ghe Sofa", 150.0);  
    Product p3("Laptop", 1000.0, 5); 
    p1.display();
    p1.setName("Ban lam viec");
    p1.display();
    p2.setName(""); 
    p3.display();
    return 0;
}