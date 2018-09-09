#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;

char mp[6][6];
int a[3][3];
int sss[] = { 0, 0, 0, 0, 0, 0, 10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 360, 1080, 144, 1800, 3600 };
vector<PII> v1,v2;
double ans;
int tot;
bool vis[10];

void dfs(int dep)
{
    if (dep>=v1.size()) {
        ++tot;
        vector<int> ve;
        for (int i=1;i<=9;i++) {
            if (!vis[i]) {
                ve.push_back(i);
            }
        }
//        printf("%u %u\n",ve.size(),v2.size());
        int sz=v2.size();
        double sc[8]={0};
        int cnt=0;
        do {
            ++cnt;
            for (int i=0;i<sz;i++) {
                a[v2[i].first][v2[i].second]=ve[i];
            }
//            int okc = 0, nokc = 0;
            for(int i = 0; i < 3; ++i) {
                sc[i] += sss[a[i][0] + a[i][1] + a[i][2]];
            }
            for(int i = 0; i < 3; ++i) {
                sc[3+i] += sss[a[0][i] + a[1][i] + a[2][i]];
            }
            sc[6] += sss[a[0][0] + a[1][1] + a[2][2]];
            sc[7] += sss[a[2][0] + a[1][1] + a[0][2]];
        } while (next_permutation(begin(ve),end(ve)));
        double res=*max_element(sc,sc+8);
        ans+=res/cnt;
        return;
    }
    for (int i=1;i<=9;i++) {
        if (!vis[i]) {
            a[v1[dep].first][v1[dep].second]=i;
            vis[i]=true;
            dfs(dep+1);
            vis[i]=false;
            a[v1[dep].first][v1[dep].second]=0;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        v1.clear();
        v2.clear();
        memset(vis,0,sizeof(vis));
        for (int i=0;i<3;i++) {
            scanf("%s",mp[i]);
            for (int j=0;j<3;j++) {
                if (mp[i][j]=='*') {
                    v1.push_back({i,j});
                    a[i][j]=0;
                } else if (mp[i][j]=='#') {
                    v2.push_back({i,j});
                    a[i][j]=0;
                } else {
                    a[i][j]=mp[i][j]-'0';
                    vis[a[i][j]]=true;
                }
            }
        }
        ans=0;
        tot=0;
        dfs(0);
        printf("%.6f\n",ans/tot);
    }
    return 0;
}
