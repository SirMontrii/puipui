#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // Get the Linux kernel version using the 'uname' command
    string kernel_version;
    FILE* pipe = popen("uname -r", "r");
    if (!pipe) {
        cerr << "Failed to run 'uname' command." << endl;
        return 1;
    }
    char buffer[128];
    if (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        kernel_version = buffer;
    }
    pclose(pipe);

    // Get CPU information from /proc/cpuinfo
    string cpu_info;
    ifstream cpu_info_file("/proc/cpuinfo");
    if (cpu_info_file.is_open()) {
        string line;
        while (getline(cpu_info_file, line)) {
            cpu_info += line + "\n";
        }
        cpu_info_file.close();
    } else {
        cerr << "Failed to open /proc/cpuinfo file." << endl;
        return 1;
    }

    // printing all that shit
    cout << "Linux Kernel Version: " << kernel_version;
    cout << "\n\nCPU Information:\n" << cpu_info;

    return 0;
}
