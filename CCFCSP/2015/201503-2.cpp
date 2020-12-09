#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
map<int,int> mp;

int main()
{
    int n,x;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&x);
        ++mp[x];
    }
    vector<PII> ve;
    for (map<int,int>::iterator it=mp.begin();it!=mp.end();++it) {
        ve.push_back(PII(-(it->second),it->first));
    }
    sort(ve.begin(),ve.end());
    for (int i=0;i<(int)ve.size();i++) {
        printf("%d %d\n",ve[i].second,-ve[i].first);
    }
    return 0;
}
