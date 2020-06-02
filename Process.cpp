#include <iostream>
#include "Process.hpp"

using namespace std;

Process::Process() 
{ 
    head = current = newprocess = NULL;
}

Process::~Process() {}

void Process::append(int pid, int bt, int pri)
{
    if(head == NULL)
    {
        try
        {
            current = new P;
            current -> pid = pid;
            current -> burst_time = bt;
            current -> priority = pri;
            current -> next = NULL;
            head = current;   

            cout << "Process created successfully" << endl;       
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            cout << "Failed to create process" << endl;
        }
    }

    else
    {
        try
        {
            newprocess = new P;
            newprocess -> pid = pid;
            newprocess -> burst_time = bt;
            newprocess -> priority = pri;            
            newprocess -> next = NULL;
            current -> next = newprocess;
            current = current -> next;
            cout << "Process created successfully" << endl;       
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            cout << "Failed to create process" << endl;
        }
        
    }
}

void Process::toArray(int process[], int bt[], int pri[])
{
    struct P *trav = head;
    int i = 0;
    while(trav != NULL)
    {
        process[i] = trav -> pid;
        bt[i] = trav -> burst_time;
        pri[i] = trav -> priority;
        i++;
        trav = trav -> next;
    }
}

void Process::setAverage(float wt, float tat, string algo)
{
    if(algo == "RR")
    {
        average.avgWtRR = wt;
        average.avgTatRR = tat;
    }

    else if (algo == "FCFN") 
    {
        average.avgWtFCFN = wt;
        average.avgTatFCFN = tat;
    }
    

    else if (algo == "Priority") 
    {
        average.avgWtPri = wt;
        average.avgTatPri = tat;
    }


    else if (algo == "SJN") 
    {
        average.avgWtSJN = wt;
        average.avgTatSJN = tat;
    }

    else
    {
        cout << "Invalid algorithm" << endl;
    }
    
}

void Process::getAverage()
{
    cout << endl << endl;
    cout << "________________________________________________________" << endl << endl;
    cout << "Algorithm" << "\t\t" << "Avg WT" << "\t\t" << "Avg TAT" << endl;
    cout << "________________________________________________________" << endl << endl;

    cout << "RR" << "\t\t\t" << average.avgWtRR << "\t\t" << average.avgTatRR << endl;
    cout << "FCFN" << "\t\t\t" << average.avgWtFCFN << "\t\t" << average.avgTatFCFN << endl;
    cout << "Priority" << "\t\t" << average.avgWtPri << "\t\t" << average.avgTatPri << endl;
    cout << "SJN" << "\t\t\t" << average.avgWtSJN << "\t\t" << average.avgTatSJN << endl;
    
    cout << endl << endl << "Optimal algorithm(s)" << endl << endl;
    
    cout << "Based on Waiting time: \t\t";
    if(average.avgWtRR <= average.avgWtFCFN && average.avgWtRR <= average.avgWtPri && average.avgWtRR <= average.avgWtSJN)
        cout << "RR \t";
    if(average.avgWtFCFN <= average.avgWtRR && average.avgWtFCFN <= average.avgWtPri && average.avgWtFCFN <= average.avgWtSJN)
        cout << "FCFN \t";
    if(average.avgWtPri <= average.avgWtRR && average.avgWtPri <= average.avgWtFCFN && average.avgWtPri <= average.avgWtSJN)
        cout << "Priority \t";
    if(average.avgWtSJN <= average.avgWtRR && average.avgWtSJN <= average.avgWtFCFN && average.avgWtSJN <= average.avgWtPri)
        cout << "SJN \t";
    cout << endl;

    cout << "Based on Turn Around time: \t";
    if(average.avgTatRR <= average.avgTatFCFN && average.avgTatRR <= average.avgTatPri && average.avgTatRR <= average.avgTatSJN)
        cout << "RR \t";
    if(average.avgTatFCFN <= average.avgTatRR && average.avgTatFCFN <= average.avgTatPri && average.avgTatFCFN <= average.avgTatSJN)
        cout << "FCFN \t";
    if(average.avgTatPri <= average.avgTatRR && average.avgTatPri <= average.avgTatFCFN && average.avgTatPri <= average.avgTatSJN)
        cout << "Priority \t";
    if(average.avgTatSJN <= average.avgTatRR && average.avgTatSJN <= average.avgTatFCFN && average.avgTatSJN <= average.avgTatPri)
        cout << "SJN \t";
    cout << endl;
}