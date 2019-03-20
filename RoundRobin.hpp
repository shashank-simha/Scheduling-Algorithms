#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

void FindWaitingTime(int processes[], int n, int bt[], int wt[], int quantum);

void FindTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);

void FindAvgTime(int processes[], int n, int bt[], int quantum);

void RoundRobinInit(int processes[], int no_processes, int burst_time[]);

#endif