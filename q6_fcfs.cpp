#include <iostream>
using namespace std;

int main(){
    int n;
    float av_wt = 0, av_tat = 0;
    cout<<"\nEnter number of processes: ";
    cin>>n;
    int p[n],wt[n],tat[n];
    cout<<"Enter CPU Burst time for process:\n";
    
    for(int i=0; i<n; i++){
        cout<<"P"<<(i+1)<<" : ";
        cin>>p[i];
    }
    
    //waiting time
    wt[0] = 0;
    for(int i=1; i<n; i++){
        wt[i]=wt[i-1]+p[i-1];
    }
    
    //turn around time = waiting time + burst time
    for(int i=0; i<n; i++){
        tat[i] = wt[i] + p[i];
    }
    
    cout<<"\n---------------------------------------------------\n";
    cout<<"|  process  |   Burst time  |   wt.    |   tat    |\n";
    cout<<"---------------------------------------------------\n";
    for(int i=0; i<n; i++){
        cout<<"    P"<<(i+1)<<"             "<<p[i]<<"            "<<wt[i]<<"           "<<tat[i]<<"\n";
        av_wt+=wt[i];
        av_tat+=tat[i];
    }
    
    //average waiting time and turn around time
    av_wt/=n;
    av_tat/=n;
    cout<<"\n\nAverage waiting time: "<<av_wt<<endl;
    cout<<"\nAverage turn around time: "<<av_tat<<endl;
}