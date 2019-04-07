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