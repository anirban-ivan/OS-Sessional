#include <bits/stdc++.h>
using namespace std;
const int N=105;
int avail[N], alloc[N][N], mx[N][N], need[N][N], fin[N], tmp[N], sm[N];

main()
{
    int n, m;
    vector<int>ans;
    cout<<"Number of processes: ";
    cin>>n;
    cout<<"Types of resources: ";
    cin>>m;
    cout<<"Number of instances of resources: ";
    for(int i=0; i<m; i++) cin>>tmp[i];
    for(int i=0; i<n; i++) {
        cout<<"Number of allocated resources for P"<<i<<": ";
        for(int j=0; j<m; j++) {
            cin>>alloc[i][j];
            sm[j]+=alloc[i][j];
        }
        cout<<"Maximum needed resources for P"<<i<<": ";
        for(int j=0; j<m; j++) cin>>mx[i][j];
        for(int j=0; j<m; j++) need[i][j]=mx[i][j]-alloc[i][j];
    }
    for(int i=0; i<m; i++) {
        avail[i]=tmp[i]-sm[i];
    }
    int fll=0;
    while(1) {
        int cnt=0;
        for(int i=0; i<n; i++) {
            if(fin[i]) cnt++;
            else {
                int fl=0;
                for(int j=0; j<m; j++) {
                    if(need[i][j]>avail[j]) {
                        fl=1;
                        break;
                    }
                }
                if(!fl) {
                    fin[i]=1;
                    ans.push_back(i);
                    cnt++;
                    for(int j=0; j<m; j++) {
                        avail[j]+=alloc[i][j];
                    }
                }
            }
        }
        if(cnt==n) {
            fll=1;
            break;
        }
        if(cnt==0) break;
    }
    cout<<"Safe State: ";
    if(fll) {
        cout<<"Yes"<<endl;
        for(int i=0; i<n; i++) {
            if(i<n-1) cout<<"P"<<ans[i]<<"->";
            else cout<<"P"<<ans[i];
        }
    }
    else cout<<"No";
}
