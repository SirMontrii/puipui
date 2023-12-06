#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getMemoryInfo() {
    ifstream memInfoFile("/proc/meminfo");
    if (!memInfoFile.is_open()) {
        cerr << "Failed to open /proc/meminfo file." << endl;
        return;
    }

    string line;
    while (getline(memInfoFile, line)) {
        cout << line << endl;
    }

    memInfoFile.close();
}

int main() {
    cout << "Memory Information:" << endl;
    getMemoryInfo();
    return 0;
}
