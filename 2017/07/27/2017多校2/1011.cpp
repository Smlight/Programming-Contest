#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N=505,M=105;
PII p[N];
int mp[M<<1][M<<1];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        memset(mp,0,sizeof(mp));
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&p[i].first,&p[i].second);
            mp[p[i].first+M][p[i].second+M]++;
        }
        int ans=0;
        for (int i=1;i<=n;i++) {
            for (int j=i+1;j<=n;j++) {
                int x_1=p[i].first,y_1=p[i].second;
                int x_2=p[j].first,y_2=p[j].second;

                #define inbound(x) -100<=x&&x<=100
                int x_3=x_2-y_1+y_2,y_3=y_2+x_1-x_2;
                int x_4=x_1-y_1+y_2,y_4=y_1+x_1-x_2;
                if (inbound(x_3)&&inbound(x_4)&&inbound(y_3)&&inbound(y_4)) {
                    ans+=mp[x_3+M][y_3+M]*mp[x_4+M][y_4+M];
                }

                x_3=x_2+y_1-y_2;y_3=y_2-x_1+x_2;
                x_4=x_1+y_1-y_2,y_4=y_1-x_1+x_2;
                if (inbound(x_3)&&inbound(x_4)&&inbound(y_3)&&inbound(y_4)) {
                    ans+=mp[x_3+M][y_3+M]*mp[x_4+M][y_4+M];
                }
                #undef inbound
            }
        }
        printf("%d\n",ans/4);
    }
    return 0;
}
