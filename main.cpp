#include <iostream>
#include "Process.hpp"
#include "RoundRobin.hpp"
#include "FCFS.hpp"
#include "SJN.hpp"
#include "PriorityScheduling.hpp"

using namespace std;

int main()
{
    int no_processes, quantum;
    int *processes, *burst_time, *priority;
    Process ProcessList;

    cout << "Enter the number of processes: ";
    cin >> no_processes;

    for(int i = 1; i <= no_processes; i++)
    {
        int bt, pri;
        cout << "Enter the Burst time for process"<<i<<": ";
        cin >> bt;
        cout << "Enter the priority for process"<<i<<": ";
        cin >> pri;

        ProcessList.append(i, bt, pri);
    }

    // Time quantum
    cout << "Enter the time quantum: ";
    cin >> quantum;

	processes = (int*) new int[no_processes];
    burst_time = (int*) new int[no_processes];
    priority = (int*) new int[no_processes];

	if(!(processes || burst_time || priority))
	{
		cout << "Memory Allocation Failed" << endl;
		exit(1);
	}

    ProcessList.toArray(processes, burst_time, priority);

    float avgWt, avgTat;
    
    RoundRobinInit(processes, no_processes, burst_time, quantum, &avgWt, &avgTat);
    ProcessList.setAverage(avgWt, avgTat, "RR");

    FCFS scheduler1(processes, no_processes, burst_time, &avgWt, &avgTat);
    ProcessList.setAverage(avgWt, avgTat, "FCFN");

    PS schduler2(processes, no_processes, burst_time, priority, &avgWt, &avgTat);
    ProcessList.setAverage(avgWt, avgTat, "Priority");

    SJNInit(processes, no_processes, burst_time, &avgWt, &avgTat);
    ProcessList.setAverage(avgWt, avgTat, "SJN");

    ProcessList.getAverage();

    return 0;
}
