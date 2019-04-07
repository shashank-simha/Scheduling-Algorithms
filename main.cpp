#include<iostream>
#include "RoundRobin.hpp"
#include "FCFS.hpp"
#include "SJN.hpp"
#include "PriorityScheduling.hpp"

using namespace std;

int main()
{
    int no_processes, quantum;
    int *processes, *burst_time, *priority;

    cout << "Enter the number of processes: ";
    cin >> no_processes;

	processes = (int*) new int[no_processes];
    burst_time = (int*) new int[no_processes];
    priority = (int*) new int[no_processes];

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

    // Priorities
    for(int i = 1; i <= no_processes; i++)
    {
        cout << "Enter the priority for process"<<i<<": ";
        cin >> priority[i-1];
    }

    // Time quantum
    cout << "Enter the time quantum: ";
    cin >> quantum;

    RoundRobinInit(processes, no_processes, burst_time, quantum);
    FCFS scheduler1(processes, no_processes, burst_time);
    SJNInit(processes, no_processes, burst_time);
    PS schduler2(processes, no_processes, burst_time, priority);

    return 0;
}
