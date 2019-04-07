#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
using namespace std;

class Process
{
private:
    struct P
    {
        int pid;
        int burst_time;
        int priority;
        struct P * next;
    };

    struct avg
    {
        float avgWtRR, avgWtFCFN, avgWtPri, avgWtSJN;
        float avgTatRR, avgTatFCFN, avgTatPri, avgTatSJN;
    };
    
    struct P *head, *current, *newprocess;
    
    struct avg *average;

public:
    Process();
    ~Process();

    void append(int pid, int bt, int pri);

    void toArray(int process[], int bt[], int pri[]);

    void setAverage(float wt, float tat, string algo);

    void getAverage();

};

#endif