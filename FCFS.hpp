#ifndef FCFS_H
#define FCFS_H

class FCFS
{
private:
    void FindWaitingTime(int processes[], int n, int bt[], int wt[]);

    void FindTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);

    void FindAvgTime(int processes[], int n, int bt[]);

public:
    FCFS(int processes[], int no_processes, int burst_time[]);

    ~FCFS();
};

#endif