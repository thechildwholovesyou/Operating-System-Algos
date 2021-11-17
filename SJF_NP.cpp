#include<bits/stdc++.h>
using namespace std;

struct struct_process{
    int pid;
    int at;
    int bt;
    int ct,wt,tat,rt,start_time;
}ps[100];

int main()
{
    int n;
    cin>>n;
    bool is_completed[100]={false};
    bool is_first_process=true;
    int sum_tat=0,sum_wt=0,sum_rt=0;
    float cpu_utilization;
    int total_idle_time=0, length_cycle, prev=0, current_time=0;

    cout<<fixed<<setprecision(2);
    
    for(int i=0;i<n;i++)
    {
        cin>>ps[i].at;
        ps[i].pid=i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>ps[i].bt;
    }

    int completed=0;
    while(completed!=n)
    {
        int min_idx=-1;
        int minimum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(ps[i].at<=current_time and is_completed[i]==false){
                if(ps[i].bt <minimum)
                {
                    minimum=ps[i].at;
                    min_idx=i;
                }
                if(ps[i].bt==minimum)
                {
                    if(ps[i].at<ps[min_idx].at){
                        minimum=ps[i].bt;
                        min_idx=i;
                    }
                }
            }
        }
        if(min_idx==-1){
            current_time++;
        }
        else{
            ps[min_idx].start_time=current_time;
            ps[min_idx].ct=ps[min_idx].start_time+ps[min_idx].bt;
            ps[min_idx].tat=ps[min_idx].ct-ps[min_idx].at;
            ps[min_idx].wt=ps[min_idx].tat-ps[min_idx].bt;
            ps[min_idx].wt=ps[min_idx].wt;

            sum_tat+=ps[min_idx].tat;
            sum_wt+=ps[min_idx].wt;
            sum_rt+=ps[min_idx].wt;
            total_idle_time+=(is_first_process==true)? 0: (ps[min_idx].start_time-prev);

            completed++;
            is_completed[min_idx]=true;
            current_time=ps[min_idx].ct;
            prev=current_time;
            is_first_process=false;
        }
    }

    int max_completion_time=INT_MIN;
    int min_arrival_time=INT_MAX;

    for(int i=0;i<n;i++){
        max_completion_time=max(max_completion_time,ps[i].ct);
        min_arrival_time=min(min_arrival_time,ps[i].at);
    }
    length_cycle=max_completion_time-min_arrival_time;

    cpu_utilization=(float)(length_cycle-total_idle_time)/length_cycle;

     cout<<"\nAverage Turn Around time= "<< (float)sum_tat/n;
    cout<<"\nAverage Waiting Time= "<<(float)sum_wt/n;
    cout<<"\nAverage Response Time= "<<(float)sum_rt/n;    
    cout<<"\nThroughput= "<<n/(float)length_cycle;
    cout<<"\nCPU Utilization(Percentage)= " << cpu_utilization*100;
    return 0;
}