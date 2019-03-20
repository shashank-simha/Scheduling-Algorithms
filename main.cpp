#include<iostream>
#include "RoundRobin.hpp"
#include "FCFS.hpp"

using namespace std;

int main()
{
    int no_processes;
    int *processes, *burst_time;

    cout << "Enter the number of processes: ";
    cin >> no_processes;

	processes = (int*) malloc(no_processes*sizeof(int));
    burst_time = (int*) malloc(no_processes*sizeof(int));

	if(!(processes || burst_time))
	{
		cout << "Memory Allocation Failed" << endl;
		exit(1);
	}

	// process id's 
    for(int i = 1; i <= no_processes; i++)
        processes[i-1] = i;

	// Burst time of all processes 
    for(int i = 1; i <= no_processes; i++)
    {
        cout << "Enter the Burst time for process"<<i<<": ";
        cin >> burst_time[i-1];
    }

    RoundRobinInit(processes, no_processes, burst_time);
    FCFS temp(processes, no_processes, burst_time);
    return 0;
}
