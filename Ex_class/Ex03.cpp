#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Logger {
private:
    string name;
public:
    Logger() {
        name = "Default";
        cout << "Logger [" << name << "] created (Default)" << endl;
    }
    Logger(string n) {
        name = n;
        cout << "Logger [" << name << "] created" << endl;
    }
    ~Logger() {
        cout << "Logger [" << name << "] destroyed" << endl;
    }
};

int main() {
    cout << "=== BIEU DIEN STACK ===" << endl;
    {
        Logger stackLogger("Stack_Object"); 
    } 
    cout << "Da thoat khoi block Stack." << endl << endl;
    cout << "=== BIEU DIEN HEAP ===" << endl;
    Logger* heapLogger = new Logger("Heap_Object"); 
    cout << "Chuan bi goi delete cho Heap Object..." << endl;
    delete heapLogger; 
    cout << "Da delete Heap Object." << endl;
    return 0;
}