#include<bits/stdc++.h>
using namespace std;
const int N=105;
int et[N];

int main()
{
    int n, x, y;
    vector<pair<pair<int, int>, int> >v;
    vector<pair<int, pair<int, int> > >out;
    vector<int>bb;
    queue<pair<pair<int, int>, int> >rq;
    double mean=0, sd=0;
    cout<<"Number of process, n: ";
    cin>>n;
    for(int i=0; i<n; i++) {
        cout<<"Enter the arrival time of P"<<i+1<<": ";
        cin>>x;
        cout<<"Enter the burst time of P"<<i+1<<": ";
        cin>>y;
        out.push_back(make_pair(i+1, make_pair(x, y)));
        bb.push_back(y);
        mean+=y;
        if(x==0) rq.push(make_pair(make_pair(x, i+1), y));
        else v.push_back(make_pair(make_pair(x, i+1), y));
    }
    sort(v.begin(), v.end());
    sort(bb.begin(), bb.end());
    mean/=n;
    for(int i=0; i<bb.size(); i++) sd+=(bb[i]-mean)*(bb[i]-mean);
    sd/=n;
    sd=sqrt(sd);
    double med=0;
    if(n%2) med=double(bb[n/2]);
    else med=double((bb[(n-1)/2]+bb[n/2])/2);
    int tq=ceil(sd*med), shesh=0, cnt=0, tot=n;
    cout<<"Gantt chart"<<endl;
    while(!rq.empty()) {
        int att=rq.front().first.first;
        int id=rq.front().first.second;
        int bt=rq.front().second;
        rq.pop();
        cout<<shesh<<" P"<<id<<" ";
        tot--;
        if(bt>=tq) {
            shesh+=tq;
            bt-=tq;
        }
        else {
            shesh+=bt;
            bt=0;
        }
        while(v[cnt].first.first<=shesh && cnt<v.size()) {
            rq.push(v[cnt]);
            cnt++;
        }
        if(bt) rq.push(make_pair(make_pair(att, id), bt));
        else et[id]=shesh;
    }
    cout<<endl;
    double st=0, sw=0;
    for(int i=0; i<n; i++) {
        int endt=et[out[i].first];
        int tt=endt-out[i].second.first;
        int wt=tt-out[i].second.second;
        cout<<"Process: P"<<out[i].first<<"\t"<<"End time: "<<endt<<"\t"<<"Waiting time: "<<wt<<"\t"<<"Turnaround time: "<<tt<<endl;
        st+=tt;
        sw+=wt;
    }
    st/=n, sw/=n;
    cout<<"Average waiting time: "<<sw<<endl;
    cout<<"Average turnaround time: "<<st<<endl;
}
