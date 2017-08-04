#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;
struct Node {
    ll cnt,exc;
    int ch[2];
} tr[N*20];
int tot;
ll ans;
int num[31][2];

void newnode()
{
    ++tot;
    tr[tot].cnt=tr[tot].exc=0;
    tr[tot].ch[0]=tr[tot].ch[1]=0;
}

void ins(int x)
{
    int rt=1;
    for (int j=30;j>=0;j--) {
        int k=(x>>j)&1;
        if (tr[rt].ch[k]==0) {
            newnode();
            tr[rt].ch[k]=tot;
        }
        if (tr[rt].ch[k^1]) {
            int tmp=tr[rt].ch[k^1];
            ans+=(tr[tmp].cnt)*(tr[tmp].cnt-1)/2-tr[tmp].exc;
            ans+=(num[j][k^1]-tr[tmp].cnt)*tr[tmp].cnt;
        }
        rt=tr[rt].ch[k];
        tr[rt].cnt++;
        tr[rt].exc+=num[j][k]-tr[rt].cnt;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,x;
        tot=0;ans=0;
        newnode();
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for (int i=1;i<=n;i++) {
            scanf("%d",&x);
            for (int j=30;j>=0;j--) {
                num[j][(x>>j)&1]++;
            }
            ins(x);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
