#ifndef SJN_H
#define SJN_H

void SJNFindWaitingTime(int processes[], int n, int bt[], int wt[]);

void SJNFindTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);

void SJNFindAvgTime(int processes[], int n, int bt[]);

void SJNInit(int processes[], int no_processes, int burst_time[]);

void SJNSort(int processes[], int n, int bt[]);

#endif