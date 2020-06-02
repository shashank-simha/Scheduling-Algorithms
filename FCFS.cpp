#include<iostream> 
#include "FCFS.hpp"

using namespace std; 

void FCFS::FindWaitingTime(int processes[], int n, int bt[], int wt[]) 
{ 
	// waiting time for first process is 0 
	wt[0] = 0; 

	// calculating waiting time 
	for (int i = 1; i < n ; i++ ) 
		wt[i] = bt[i-1] + wt[i-1] ; 
} 

void FCFS::FindTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[]) 
{ 
	// calculating turnaround time by adding 
	// bt[i] + wt[i] 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

void FCFS::FindAvgTime( int processes[], int n, int bt[], float *avgWt, float *avgTat) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	//Function to find waiting time of all processes 
	FindWaitingTime(processes, n, bt, wt); 

	//Function to find turn around time for all processes 
	FindTurnAroundTime(processes, n, bt, wt, tat); 

	//Display processes along with all details 
	cout << "Processes "<< " Burst time " << " Waiting time " << " Turn around time" << endl; 

	// Calculate total waiting time and total turn 
	// around time 
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t " << wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	*avgWt = (float)total_wt / (float)n;
	*avgTat = (float)total_tat / (float)n;
	cout << "Average waiting time = " << (float)total_wt / (float)n << endl; 
	cout << "Average turn around time = "	<< (float)total_tat / (float)n << endl; 
} 

FCFS::FCFS(int processes[], int no_processes, int burst_time[], float *avgWt, float *avgTat) 
{ 
	cout << "__________________________________________________" << endl << endl;
	cout << "\t\t First Come First Serve" << endl;
	cout << "__________________________________________________" << endl;
	FCFS::FindAvgTime(processes, no_processes, burst_time, avgWt, avgTat); 
}

FCFS::~FCFS()
{
	
}
