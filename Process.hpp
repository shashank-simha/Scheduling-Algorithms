#ifndef PROCESS_H
#define PROCESS_H

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

    struct P *head, *current, *newprocess;

    struct avg
    {
        float avgWtRR, avgWtFCFN, avgWtPri, avgWtSJN;
        float avgTatRR, avgTatFCFN, avgTatPri, avgTatSJN;
    };
    
public:
    Process();
    ~Process();

    void append(int pid, int bt, int pri);

    void toArray(int process[], int bt[], int pri[]);
};

#endif