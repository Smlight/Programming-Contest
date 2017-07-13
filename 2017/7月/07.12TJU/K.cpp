#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int M=1e5+5,MAX=3e5+5;
int c1[MAX],c2[MAX];
PII b[M];
int cel[M];

void ins(int c[],int x,int d)
{
    for (int i=x;i<MAX;i+=i&(-i)) {
        c[i]+=d;
    }
}

int get_ans(int c[],int x)
{
    int res=0;
    for (int i=x;i;i-=i&(-i)) {
        res+=c[i];
    }
    return res;
}

int main()
{
    int T,n,m;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        int cnt=0;
        for (int i=1;i<=m;i++) {
            int op,x,y;
            scanf("%d%d",&op,&x);
            if (op==1) {
                cel[++cnt]=0;
                scanf("%d",&y);
                ++x;y+=x-1;
                printf("%d\n",get_ans(c2,y)-get_ans(c1,x-1));
                ins(c1,x,1);
                ins(c2,y,1);
                b[cnt]=PII(x,y);
            } else {
                if (x<=0||x>cnt||cel[x]) continue;
                cel[x]=1;
                ins(c1,b[x].first,-1);
                ins(c2,b[x].second,-1);
            }
        }
    }
    return 0;
}
