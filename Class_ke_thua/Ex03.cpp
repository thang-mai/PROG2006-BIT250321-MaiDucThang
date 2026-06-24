#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Base {
    public: 
        string pub = "Public member";
    protected:
        string prot = "Protected member";
    private:
        string priv = "Private member";
};

class DerivedPublic : public Base {
    public:
        void test() {
            cout << pub << endl;
            cout << prot << endl;
            // cout << priv << endl; // Lỗi biên dịch
        }
};

class DerivedProtected : protected Base {
    public:
        void test() {
            cout << pub <<endl;
            cout << prot << endl;
            // cout << priv << endl; // Lỗi biên dịch
        }
};

class DerivedPrivate : private Base {
    public:
        void test() {
            cout << pub << endl;
            cout << prot << endl;
            // cout << priv << endl; // Lỗi biên dịch
        }
};

int main() {
    DerivedPublic dpub;
    DerivedProtected dprot;
    DerivedPrivate dpriv;

    cout << dpub.pub << endl; // OK
    // cout << dpub.prot << endl; // Lỗi biên dịch
    // cout << dpub.priv << endl; // Lỗi biên dịch
    // cout << dprot.pub << endl; // Lỗi biên dịch
    // cout << dprot.prot << endl; // Lỗi biên dịch
    // cout << dprot.priv << endl; // Lỗi biên dịch
    // cout << dpriv.pub << endl; // Lỗi biên dịch
    // cout << dpriv.prot << endl; // Lỗi biên dịch
    // cout << dpriv.priv << endl; // Lỗi biên dịch
    return 0;
}