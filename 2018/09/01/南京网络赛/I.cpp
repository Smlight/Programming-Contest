#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=4000010;
const int MO=1000000007;
int tr[N][10];
int fa[N];
int len[N];
char s[N];
int n;
int po[N],val[N];

inline void add(int &a,int b) { a=(a+b>=MO)?a+b-MO:a+b; }

ll fpow(ll x,ll n)
{
    ll res(1);
    for (;n;n>>=1,x=x*x%MO) {
        if (n&1) res=res*x%MO;
    }
    return res;
}

void New(int t,int x)
{
    n++;
    tr[t][x]=n;
    len[n]=len[t]+2;
    if (len[t]==-1) {
        val[n]=x;
    } else {
        val[n]=x;
        add(val[n],val[t]*10LL%MO);
        add(val[n],x*fpow(10,len[n]-1)%MO);
    }
}

int main()
{
    scanf("%s",s+1);
    int L=strlen(s+1);
    s[0]=' ';
    n=1;
    fa[0]=1;
    fa[1]=1;
    len[0]=0;
    val[0]=0;
    len[1]=-1;
    val[1]=0;
    int last=0;
    for (int i=1;i<=L;i++) {
        int k=s[i]-'0';
        while (s[i]!=s[i-len[last]-1]) last=fa[last];
        int j=fa[last];
        while ((len[j]>-1) && (s[i]!=s[i-len[j]-1])) j=fa[j];
        j=tr[j][k];
        if (!tr[last][k]) { //新建节点
            New(last,k);
            fa[tr[last][k]]=j;
        }
        last=tr[last][k];//从当前点转移到子树
    }
    int ans=0;
    for (int i=1;i<=n;i++) add(ans,val[i]);
    printf("%d\n",ans);
    return 0;
}
