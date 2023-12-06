#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <source_file> <destination_file>" << endl;
        exit(1);
    }

    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("Failed to open source file");
        exit(1);
    }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Failed to open destination file");
        close(source_fd);
        exit(1);
    }

    char buffer[4096];
    ssize_t bytes_read;

    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {
        if (write(dest_fd, buffer, bytes_read) != bytes_read) {
            perror("Write error");
            close(source_fd);
            close(dest_fd);
            exit(1);
        }
    }

    close(source_fd);
    close(dest_fd);

    cout << "File copied successfully from " << argv[1] << " to " << argv[2] << endl;

    return 0;
}
