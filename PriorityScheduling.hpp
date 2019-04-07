#ifndef PRIORITYSCHEDULING_H
#define  PRIORITYSCHEDULING_H

class PS
{
private:
    void FindWaitingTime(int processes[], int n, int bt[], int wt[]);

    void FindTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);

    void FindAvgTime(int processes[], int n, int bt[], int priority[]);

    void PrioriySort(int processes[], int n, int bt[], int priority[]);

public:
    PS(int processes[], int no_processes, int burst_time[], int priority[]);

    ~PS();
};

#endif
