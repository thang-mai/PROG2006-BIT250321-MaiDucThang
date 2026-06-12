#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class BankAccount {
	private:
		string ownerName;
		double balance;
		int accountId;
	public:
		BankAccount(string name, int id, double money) {
			ownerName = name;
			accountId = id;
			balance = (money >= 0) ? money : 0;
		}
		double getBalance() const {
			return balance;
		}
		void deposit(double amount) {
			if (amount > 0) {
				balance += amount;
				cout << "Nap thanh cong: +" << amount << " VND. So du moi: " << balance << " VND" << endl;
			} else {
				cout << "Loi: So tien nap vao phai lon hon 0.\n";
			}
		}
		void withdraw(double amount) {
			if (amount > 0 && balance >= amount) {
				balance -= amount;
				cout << "Rut thanh cong " << amount << " VND. So du moi " << balance << " VND" << endl;
			} else if (amount > balance) {
				cout << "Loi: So du tai khoan khong du" << endl;
			} else {
				cout << "Loi: So tien rut phai lon hon 0.\n" << endl;
			}
			}
};

int main() {
	BankAccount ac1("Pham Cong Thoang", 2025123, 500000);
	ac1.deposit(200000);
	ac1.withdraw(900000);
	ac1.withdraw(-39990);
	cout << "So du con lai: 0" << ac1.getBalance() << " VND.\n";
	return 0;
}