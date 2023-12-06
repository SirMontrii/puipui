#include <iostream>
using namespace std;

void firstFit(int bsize[], int psize[], int bno, int pno);
void bestFit(int bsize[], int psize[], int bno, int pno);
void worstFit(int bsize[], int psize[], int bno, int pno);

int main() {
    int bsize[10], psize[10], bno, pno;

    // Initialization
    for (int i = 0; i < 10; i++) {
        bsize[i] = 0;
        psize[i] = 0;
    }

    cout << "Enter no. of blocks: ";
    cin >> bno;
    cout << "\nEnter size of each block: ";
    for (int i = 0; i < bno; i++)
        cin >> bsize[i];

    cout << "\nEnter no. of processes: ";
    cin >> pno;
    cout << "\nEnter size of each process: ";
    for (int i = 0; i < pno; i++)
        cin >> psize[i];

    int choice;
    cout << "\nChoose Memory Allocation Algorithm:\n";
    cout << "1. First Fit\n";
    cout << "2. Best Fit\n";
    cout << "3. Worst Fit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            firstFit(bsize, psize, bno, pno);
            break;

        case 2:
            bestFit(bsize, psize, bno, pno);
            break;

        case 3:
            worstFit(bsize, psize, bno, pno);
            break;

        default:
            cout << "Invalid choice";
            break;
    }

    return 0;
}

void firstFit(int bsize[], int psize[], int bno, int pno) {
    int flags[10] = {0};
    int allocation[10] = {-1};

    for (int i = 0; i < pno; i++)
        for (int j = 0; j < bno; j++)
            if (flags[j] == 0 && bsize[j] >= psize[i]) {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }

    // Display allocation details for First Fit
    cout << "\nFirst Fit Allocation:";
    cout << "\nBlock no.\tsize\t\tprocess no.\t\tsize";
    for (int i = 0; i < bno; i++) {
        cout << "\n" << i + 1 << "\t\t" << bsize[i] << "\t\t";
        if (flags[i] == 1)
            cout << allocation[i] + 1 << "\t\t\t" << psize[allocation[i]];
        else
            cout << "Not allocated";
    }
}

void bestFit(int bsize[], int psize[], int bno, int pno) {
    int flags[10] = {0};
    int allocation[10] = {-1};

    for (int i = 0; i < pno; i++) {
        int bestFitBlock = -1;
        for (int j = 0; j < bno; j++) {
            if (flags[j] == 0 && bsize[j] >= psize[i]) {
                if (bestFitBlock == -1 || bsize[j] < bsize[bestFitBlock]) {
                    bestFitBlock = j;
                }
            }
        }
        if (bestFitBlock != -1) {
            allocation[bestFitBlock] = i;
            flags[bestFitBlock] = 1;
        }
    }

    // Display allocation details for Best Fit
    cout << "\nBest Fit Allocation:";
    cout << "\nBlock no.\tsize\t\tprocess no.\t\tsize";
    for (int i = 0; i < bno; i++) {
        cout << "\n" << i + 1 << "\t\t" << bsize[i] << "\t\t";
        if (flags[i] == 1)
            cout << allocation[i] + 1 << "\t\t\t" << psize[allocation[i]];
        else
            cout << "Not allocated";
    }
}

void worstFit(int bsize[], int psize[], int bno, int pno) {
    int flags[10] = {0};
    int allocation[10] = {-1};

    for (int i = 0; i < pno; i++) {
        int worstFitBlock = -1;
        for (int j = 0; j < bno; j++) {
            if (flags[j] == 0 && bsize[j] >= psize[i]) {
                if (worstFitBlock == -1 || bsize[j] > bsize[worstFitBlock]) {
                    worstFitBlock = j;
                }
            }
        }
        if (worstFitBlock != -1) {
            allocation[worstFitBlock] = i;
            flags[worstFitBlock] = 1;
        }
    }

    // Display allocation details for Worst Fit
    cout << "\nWorst Fit Allocation:";
    cout << "\nBlock no.\tsize\t\tprocess no.\t\tsize";
    for (int i = 0; i < bno; i++) {
        cout << "\n" << i + 1 << "\t\t" << bsize[i] << "\t\t";
        if (flags[i] == 1)
            cout << allocation[i] + 1 << "\t\t\t" << psize[allocation[i]];
        else
            cout << "Not allocated";
    }
}
