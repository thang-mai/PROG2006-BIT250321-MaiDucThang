#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Counter {
private:
    static int totalCount;
    int id;
public:
    Counter() {
        totalCount++;
        id = totalCount;
    }
    ~Counter() {
        totalCount--;
    }
    int getId() const {
        return id;
    }
    static int getTotalCount() {
        return totalCount;
    }
};

int Counter::totalCount = 0;

int main() {
    Counter s1;
    Counter s2;
    Counter* h1 = new Counter();
    Counter* h2 = new Counter();
    cout << "Tong so doi tuong ban dau: " << Counter::getTotalCount() << endl;
    cout << "Chuan bi delete 1 doi tuong tren heap..." << endl;
    delete h1;
    cout << "Tong so doi tuong sau khi delete: " << Counter::getTotalCount() << endl;
    cout << "=== Vao khoi block {} ===" << endl;
    {
        Counter s3;
        cout << "ID cua s3 trong block: " << s3.getId() << endl;
        cout << "Tong so doi tuong ben trong block: " << Counter::getTotalCount() << endl;
    }
    cout << "=== Thoat khoi block {} ===" << endl;
    cout << "Tong so doi tuong cuoi cung: " << Counter::getTotalCount() << endl;
    delete h2;
    return 0;
}