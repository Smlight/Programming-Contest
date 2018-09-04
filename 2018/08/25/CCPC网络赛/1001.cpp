#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;

const int N=100010;
int w[N];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        priority_queue <PII,vector <PII>,greater<PII> > q;
        for (int i=1; i<=n; i++) {
            scanf("%d",&w[i]);
        }
        int cnt=0;
        long long ans=0;
        for (int i=1; i<=n; i++) {
            q.push({w[i],1});
            if (w[i]-q.top().first>0) {
                ans+=w[i]-q.top().first;
                cnt+=q.top().second*2;
                q.pop();
                q.push({w[i],0});
            }
        }
        printf("%I64d %d\n",ans,cnt);
    }
    return 0;
}