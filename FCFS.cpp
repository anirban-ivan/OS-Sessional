#include<bits/stdc++.h>
using namespace std;
const int N=105;
int st[N], en[N];

int main()
{
    int n, x, y;
    vector< pair< pair<int, int>, int > >p;
    cout<<"Number of process, n: ";
    cin>>n;
    for(int i=1; i<=n; i++) {
        cout<<"Enter the burst time of P"<<i<<": ";
        cin>>x;
        cout<<"Enter the arrival time of P"<<i<<": ";
        cin>>y;
        p.push_back(make_pair(make_pair(y, i), x));
    }
    sort(p.begin(), p.end());
    cout<<"Gantt Chart"<<endl;
    int ager=0;
    for(int i=0; i<n; i++) {
        st[i]=ager;
        cout<<st[i]<<" P"<<p[i].first.second<<" ";
        ager+=p[i].second;
        en[i]=ager;
    }
    cout<<endl;
    double tot_tt=0, tot_wt=0;
    for(int i=0; i<n; i++) {
        int tt=en[i]-p[i].first.first;
        int wt=tt-p[i].second;
        tot_tt+=double(tt);
        tot_wt+=double(wt);
        cout<<"Process: P"<<p[i].first.second<<"\t"<<"Start time: "<<st[i]<<"\t"<<"Waiting time: "<<wt<<"\t"<<"Turnaround time: "<<tt<<endl;
    }
    tot_tt/=n;
    tot_wt/=n;
    cout<<"Average waiting time: "<<tot_wt<<endl;
    cout<<"Average turnaround time: "<<tot_tt<<endl;
}
