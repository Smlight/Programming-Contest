#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100010;
char s[N];
struct sam {
    static const int N=200010,Csize=26;
    int p,q,np,nq,cnt=0,last,a[N][Csize],l[N],f[N];
    inline void init()
    {
        memset(l,0,sizeof(l));
        memset(f,0,sizeof(f));
        memset(b,0,sizeof(b));
        memset(x,0,sizeof(x));
        memset(r,0,sizeof(r));
        for (int i=0;i<=cnt;i++) {
            for (int j=0;j<Csize;j++) {
                a[i][j]=0;
            }
        }
        cnt=0;
        last=++cnt;
    }
    inline int cal(char c)
    {
        return c-'a';
    }
    void extend(int c)
    {
        p=last;
        np=last=++cnt;
        l[np]=l[p]+1;
        while (p&&!a[p][c]) a[p][c]=np,p=f[p];
        if (!p) f[np]=1;
        else {
            q=a[p][c];
            if (l[p]+1==l[q]) {
                f[np]=q;
            } else {
                nq=++cnt;
                l[nq]=l[p]+1;
                memcpy(a[nq],a[q],sizeof(a[q]));
                f[nq]=f[q];
                f[np]=f[q]=nq;
                while (a[p][c]==q) a[p][c]=nq,p=f[p];
            }
        }
    }
    int b[N],x[N],r[N];
    void solve()
    {
        int k;ll ans=0;
        scanf("%d",&k);
        scanf("%s",s+1);
        int len=strlen(s+1);
        for (int i=1;i<=len;i++) extend(cal(s[i]));
        for (int i=1;i<=cnt;i++) b[l[i]]++;
        for (int i=1;i<=len;i++) b[i]+=b[i-1];
        for (int i=1;i<=cnt;i++) x[b[l[i]]--]=i;
        for (int i=p=1;i<=len;i++) {
            p=a[p][cal(s[i])];
            r[p]++;
        }
        for (int i=cnt;i;i--) r[f[x[i]]]+=r[x[i]];
        for (int i=1;i<=cnt;i++) {
            if (r[i]==k) {
                ans+=l[i]-l[f[i]];
            }
        }
        printf("%lld\n",ans);
    }
} sam;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        sam.init();
        sam.solve();
    }
    return 0;
}
