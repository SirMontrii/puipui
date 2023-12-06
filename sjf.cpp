#include <iostream>
using namespace std;

void sjf(int burst_time[], int n, float &avg_waiting_time, float &avg_turnaround_time) {
    int waiting_time[n], turnaround_time[n];

    
    bool executed[n] = {false};

    int total_executed = 0; 
    int current_time = 0;   // Current time

    while (total_executed < n) {
        int shortest = -1;
        int shortest_burst = INT16_MAX;

        
        for (int i = 0; i < n; i++) {
            if (!executed[i] && burst_time[i] < shortest_burst && burst_time[i] > 0) {
                shortest = i;
                shortest_burst = burst_time[i];
            }
        }

        if (shortest == -1) {
            current_time++;
        } else {
            waiting_time[shortest] = current_time;
            current_time += burst_time[shortest];
            turnaround_time[shortest] = current_time;
            executed[shortest] = true;
            total_executed++;
        }
    }

    
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    avg_waiting_time = total_waiting_time / n;
    avg_turnaround_time = total_turnaround_time / n;

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turnaround_time[i] << endl;
    }
}

int main() {
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    int burst_time[n];
    float avg_waiting_time, avg_turnaround_time;

    cout << "Enter the burst times for each process:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> burst_time[i];
    }

    sjf(burst_time, n, avg_waiting_time, avg_turnaround_time);

    cout << "Average Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;

    return 0;
}
