#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int,int>;

const int N=55;
ll C[N][N];
bool b[N];

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    // for (int i=0;i<N;i++) {
    //     C[i][0]=1;
    //     for (int j=1;j<=i;i++) {
    //         C[i][j]=C[i-1][j-1]+C[i-1][j];
    //     }
    // }
    while (T--) {
        int n;
        scanf("%d",&n);
        printf("Case #%d:\n",++cas);
        if (n<=32) {
            for (int i=1;i<=n;i++) {
                printf("%d 1\n",i);
            }
            continue;
        }
        memset(b,0,sizeof(b));
        int d=32;
        if (n&1) d=31;
        n-=d;
        for (int i=29;i>0;i--) {
            if (n>>i&1) {
                b[i]=true;
            }
        }
        vector<PII> ans;
        ans.push_back({1,1});
        --d;
        int k=0;
        for (int i=1;i<=29;i++) {
            if (b[i]) {
                if (k==0) {
                    for (int j=1;j<=i+1;j++) {
                        ans.push_back({i+1,j});
                    }
                } else {
                    for (int j=i+1;j>=1;j--) {
                        ans.push_back({i+1,j});
                    }
                }
                k^=1;
            } else {
                if (d) {
                    if (k==0) {
                        ans.push_back({i+1,1});
                    } else {
                        ans.push_back({i+1,i+1});
                    }
                    --d;
                } else {
                    break;
                }
            }
        }
        for (int i=0;i<d;i++) {
            if (k==0) {
                ans.push_back({i+31,1});
            } else {
                ans.push_back({i+31,i+31});
            }
        }
        // printf("DEBUG!! Len: %d\n",(int)ans.size());
        for (auto &p:ans) {
            printf("%d %d\n",p.first,p.second);
        }
    }
    return 0;
}