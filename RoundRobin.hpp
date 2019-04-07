#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

void RRFindWaitingTime(int processes[], int n, int bt[], int wt[], int quantum);

void RRFindTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);

void RRFindAvgTime(int processes[], int n, int bt[], int quantum);

void RoundRobinInit(int processes[], int no_processes, int burst_time[], int quantum);

#endif