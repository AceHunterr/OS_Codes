#include<iostream>
using namespace std;

int main() {
    int n, bt[20], su[20], wt[20], tat[20], p[20], i, k, temp;
    float wtavg = 0, tatavg = 0;

    cout << "Enter the number of processes: ";
    cin >> n;
    for(i = 0; i < n; i++) {
        p[i] = i;
        cout << "Enter the burst time of process " << i << ": ";
        cin >> bt[i];
        cout << "System/User process (0/1)? ";
        cin >> su[i];
    }
    for(i = 0; i < n; i++) {
        for(k = i+1; k < n; k++) {
            if(su[i] > su[k]) {
                temp = p[i]; p[i] = p[k]; p[k] = temp;
                temp = bt[i]; bt[i] = bt[k]; bt[k] = temp;
                temp = su[i]; su[i] = su[k]; su[k] = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        wt[i] = (i == 0) ? 0 : (wt[i-1] + bt[i-1]);
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    cout << "\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for(i = 0; i < n; i++) {
        cout << p[i] << "\t\t " << su[i] << "\t\t\t " << bt[i] << "\t\t " << wt[i] << "\t\t " << tat[i] << "\n";
    }
    wtavg /= n;
    tatavg /= n;
    cout << "\nAverage Waiting Time is: " << wtavg << "\n";
    cout << "Average Turnaround Time is: " << tatavg << "\n";

    return 0;
}