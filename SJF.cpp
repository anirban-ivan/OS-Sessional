#include <bits/stdc++.h>
using namespace std;
const int N=105;
int st[N], en[N], ar[N], br[N];

int main()
{
    int n, x, y, cnt=0;
    vector<pair<pair<int, int>, int> >v;
    priority_queue<pair<pair<int, int>, int> >pq;
    vector<int>ans;
    cout<<"Number of process, n: ";
    cin>>n;
    for(int i=1; i<=n; i++) {
        cout<<"Enter the burst time of P"<<i<<": ";
        cin>>x;
        cout<<"Enter the arrival time of P"<<i<<" ";
        cin>>y;
        ar[i]=y, br[i]=x;
        if(y==0) pq.push(make_pair(make_pair(-x, -y), -i));
        else v.push_back(make_pair(make_pair(y, x), i));
    }
    sort(v.begin(), v.end());
    cout<<"Gannt Chart"<<endl;//considering the cpu won't be idle
    int tm=0, tot=0;
    while(tot<n) {
        int pid=-pq.top().second;
        st[pid]=tm;
        ans.push_back(pid);
        int b_time=-pq.top().first.first;
        int a_time=-pq.top().first.second;
        pq.pop();
        tm+=b_time;
        cout<<st[pid]<<" P"<<pid<<" ";
        en[pid]=tm;
        while(v[cnt].first.first<=tm && cnt<v.size()) {
            int arr=v[cnt].first.first;
            int brr=v[cnt].first.second;
            int id=v[cnt].second;
            pq.push(make_pair(make_pair(-brr, -arr), -id));
            cnt++;
        }
        tot++;
    }
    cout<<endl;
    double sw=0, sst=0;
    for(int i=0; i<ans.size(); i++) {
        cout<<"Process: P"<<ans[i]<<"\t";
        cout<<"Start time: "<<st[ans[i]]<<"\t";
        int tt=en[ans[i]]-ar[ans[i]];
        int wt=tt-br[ans[i]];
        cout<<"Waiting time: "<<wt<<"\t";
        sw+=double(wt);
        cout<<"Turnaround time: "<<tt<<endl;
        sst+=double(tt);
    }
    sst/=n, sw/=n;
    cout<<"Average waiting time: "<<sw<<endl;
    cout<<"Average turnaround time: "<<sst<<endl;
}
