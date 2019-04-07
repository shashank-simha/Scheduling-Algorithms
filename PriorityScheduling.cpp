#include<iostream> 
#include "PriorityScheduling.hpp"

using namespace std; 

void PS::FindWaitingTime(int processes[], int n, int bt[], int wt[]) 
{ 
	// waiting time for first process is 0 
	wt[0] = 0; 

	// calculating waiting time 
	for (int i = 1; i < n ; i++ ) 
		wt[i] = bt[i-1] + wt[i-1] ; 
} 

void PS::FindTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[]) 
{ 
	// calculating turnaround time by adding 
	// bt[i] + wt[i] 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

void PS::FindAvgTime( int processes[], int n, int bt[], int priority[], float *avgWt, float *avgTat) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	//Function to find waiting time of all processes 
	FindWaitingTime(processes, n, bt, wt); 

	//Function to find turn around time for all processes 
	FindTurnAroundTime(processes, n, bt, wt, tat); 

	//Display processes along with all details 
	cout << "Processes " << " Burst time " << "Priority " << " Waiting time " << " Turn around time" << endl; 

	// Calculate total waiting time and total turn 
	// around time 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << processes[i] << "\t\t" << bt[i] << "\t" << priority[i] << "\t " << wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "Average waiting time = " << (float)total_wt / (float)n << endl; 
	cout << "Average turn around time = "	<< (float)total_tat / (float)n << endl; 
} 

void PS::PrioriySort(int processes[], int n, int bt[], int priority[])
{
    int i, j;
    bool swapped;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (priority[j] > priority[j + 1])
            {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;

                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

PS::PS(int processes[], int no_processes, int burst_time[], int priority[], float *avgWt, float *avgTat) 
{ 
	cout << "__________________________________________________" << endl << endl;
	cout << "\t\t Priority Scheduling" << endl;
	cout << "__________________________________________________" << endl;

    PS::PrioriySort(processes, no_processes, burst_time, priority);
	PS::FindAvgTime(processes, no_processes, burst_time, priority, avgWt, avgTat); 
}

PS::~PS()
{
	
}
