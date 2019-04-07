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
        average -> avgWtRR = wt;
        average -> avgTatRR = tat;
    }

    else if (algo == "FCFN") 
    {
        average -> avgWtFCFN = wt;
        average -> avgTatFCFN = tat;
    }
    

    else if (algo == "Priority") 
    {
        average -> avgWtPri = wt;
        average -> avgTatPri = tat;
    }


    else if (algo == "SJN") 
    {
        average -> avgWtSJN = wt;
        average -> avgTatSJN = tat;
    }

    else
    {
        cout << "Invalid algorithm" << endl;
    }
    
}

void Process::getAverage()
{
    cout << "Algorithm" << "\t\t" << "Avg WT" << "\t\t" << "Avg TAT" << endl;

    cout << "RR" << "\t\t\t" << average -> avgWtRR << "\t\t" << average -> avgTatRR << endl;
    cout << "FCFN" << "\t\t\t" << average -> avgWtFCFN << "\t\t" << average -> avgTatFCFN << endl;
    cout << "Priority" << "\t\t\t" << average -> avgWtPri << "\t\t" << average -> avgTatPri << endl;
    cout << "SJN" << "\t\t\t" << average -> avgWtSJN << "\t\t" << average -> avgTatSJN << endl;
}