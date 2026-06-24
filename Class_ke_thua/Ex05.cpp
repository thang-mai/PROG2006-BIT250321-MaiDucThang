#include <iostream>
using std::string;
using std::cout;
using std::endl;

class BankAccount {
    protected:
    double balance;
    public:
        BankAccount(double b) : balance(b) {}
        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
            } else {
                cout << "Số tiền gửi không hợp lệ!" << endl;
            }
        }
        virtual void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
            } else {
                cout << "Số tiền rút không hợp lệ hoặc số dư không đủ!" << endl;
            }
        }
        double getBalance() const {
            return balance;
        }
};

class SavingsAccount : public BankAccount {
    private:
        double minimumBalance;
    public:
        SavingsAccount(double b, double min) : BankAccount(b), minimumBalance(min) {}
        void withdraw(double amount) override {
            if (amount > 0 && (balance - amount) >= minimumBalance) {
                balance -= amount;
            } else {
                cout << "Số tiền rút không hợp lệ hoặc số dư không đủ!" << endl;
            }
        }
};

int main() {
    SavingsAccount s(1000, 500);
    cout << "So du ban dau: " << s.getBalance() << endl;
    s.withdraw(99.0);   // thành công
    cout << "Sau khi rut 99: " << s.getBalance() << endl;
    s.withdraw(1000.0);    // bị từ chối
    cout << "Sau khi thu rut 2: " << s.getBalance() << endl;
    return 0;
}