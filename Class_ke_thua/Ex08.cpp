#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Account {
    protected:
        string accountNo;
        double balance;
    public:
        Account(string accNo, double bal) : accountNo(accNo), balance(bal) {}
        void deposit(double amount) {
            if (amount > 0) {
                balance += amount;
            } else {
                cout << "Số tiền gửi không hợp lệ!" << endl;
            }
        }
        void withdraw(double amount) {
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

class SavingsAccount : public Account {
    protected:
    double interestRate;

public:
    SavingsAccount(string accNo, double bal, double rate)
        : Account(accNo, bal), interestRate(rate) {}

    virtual void addInterest() {
        balance += balance * interestRate;
    }
};

class VIPSaving : public SavingsAccount {
    public:
        VIPSaving(string accNo, double bal, double rate) : SavingsAccount(accNo, bal, rate) {}
        void addInterest() override {
            balance += balance * (interestRate * 2);
        }
};

int main() {
    SavingsAccount savingAcc("SAV123", 500, 0.03);
    cout << "So du ban dau: " << savingAcc.getBalance() << endl;
    savingAcc.addInterest();
    cout << "Sau khi cong lai suat: " << savingAcc.getBalance() << endl;
    VIPSaving vipAcc("SAV123", 500, 0.03);
    cout << "So du ban dau: " << vipAcc.getBalance() << endl;
    vipAcc.addInterest();
    cout << "Sau khi cong lai suat: " << vipAcc.getBalance() << endl;
    return 0;
}