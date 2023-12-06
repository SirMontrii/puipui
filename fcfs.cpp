#include <iostream>
using namespace std;

void fcfs(int processes[], int n, int burst_time[], float &avg_waiting_time, float &avg_turnaround_time) {
    int waiting_time[n], turnaround_time[n];


    waiting_time[0] = 0;


    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }


    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
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
        cout << "P" << processes[i] << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turnaround_time[i] << endl;
    }
}

int main() {
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    int processes[n];
    int burst_time[n];
    float avg_waiting_time, avg_turnaround_time;

    cout << "Enter the burst times for each process:" << endl;
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        cout << "Process " << i + 1 << ": ";
        cin >> burst_time[i];
    }

    fcfs(processes, n, burst_time, avg_waiting_time, avg_turnaround_time);

    cout << "Average Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;

    return 0;
}
