#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=1e9+7;
const int N=100010,M=26;
struct Node {
    int c[N];
    int len,lead;
    bool operator <(const Node &r) const {
        if (len!=r.len) return len<r.len;
        int i=len;
        while (i>=0&&c[i]==r.c[i]) i--;
        if (i<0) return false;
        return c[i]<r.c[i];
    }
} a[M];
ll po[N*2];
char s[N];

int main()
{
    int n,cas=0;
    po[0]=1;
    for (int i=1;i<N*2;i++) {
        po[i]=po[i-1]*M%MO;
    }
    while (scanf("%d",&n)!=EOF) {
        for (int i=0;i<M;i++) {
            memset(a[i].c,0,sizeof(a[i].c));
            a[i].len=a[i].lead=0;
        }
        while (n--) {
            scanf("%s",s);
            int n=strlen(s);
            if (n>1) {
                a[s[0]-'a'].lead=1;
            }
            for (int i=n-1,k=0;i>=0;i--,k++) {
                int x=s[i]-'a';
                a[x].c[k]++;
                a[x].len=max(a[x].len,k);
            }
        }
        for (int i=0;i<M;i++) {
            int x=0;
            for (int j=0;j<=a[i].len;j++) {
                a[i].c[j]+=x;
                x=a[i].c[j]/M;
                a[i].c[j]%=M;
            }
            while (x) {
                int j=++a[i].len;
                a[i].c[j]=x%M;
                x/=M;
            }
        }
        sort(a,a+M);
        ll ans=0;
        int ze=0;
        for (int i=0;i<M;i++) {
            if (!a[i].lead) {
                ze=i;
                break;
            }
        }
        int w=0;
        for (int i=0;i<M;i++) {
            if (i!=ze) {
                ++w;
                for (int j=0;j<=a[i].len;j++) {
                    ans+=po[j]*a[i].c[j]%MO*w%MO;
                    ans%=MO;
                }
            }
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
