#include <iostream>
using namespace std;

// Function to find the waiting time for all
// processes
void SJNFindWaitingTime(int processes[], int n, int bt[], int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

// Function to calculate turn around time
void SJNFindTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

//Function to calculate average time
void SJNFindAvgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    SJNFindWaitingTime(processes, n, bt, wt);

    // Function to find turn around time for all processes
    SJNFindTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with all details
    cout << "Processes " << " Burst time " << " Waiting time " << " Turn around time\n";

    // Calculate total waiting time and total turn
    // around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << processes[i] << "\t\t" << bt[i] << "\t " << wt[i] << "\t\t " << tat[i] << endl;
    }

    cout << "Average waiting time = " << (float)total_wt / (float)n << endl;
    cout << "Average turn around time = " << (float)total_tat / (float)n << endl;
}

void SJNSort(int processes[], int n, int bt[])
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;

                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void SJNInit(int processes[], int no_processes, int burst_time[])
{
    // Sorting processes by burst time.
    SJNSort(processes, no_processes, burst_time);

    cout << "__________________________________________________" << endl << endl;
	cout << "\t\t Shortest Job Next" << endl;
	cout << "__________________________________________________" << endl;
    cout << "Order of process execution: ";
    for (int i = 0; i < no_processes; i++)
        cout << processes[i] << " ";
        cout << endl;

    SJNFindAvgTime(processes, no_processes,burst_time);
}