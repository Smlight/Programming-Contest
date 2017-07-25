#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MO=1e9+7;
const int N=100010,M=26;
struct Node {
    int c[N];
    int len,lead;
    bool operator <(const Node &r) const {
        int i=max(len,r.len)-1;
        while (i>=0&&c[i]==r.c[i]) i--;
        return i>=0&&c[i]<r.c[i];
    }
} a[M];
char s[N];

int main()
{
    int n,cas=0;
    while (scanf("%d",&n)!=EOF) {
        for (int i=0;i<M;i++) {
            memset(a[i].c,0,sizeof(a[i].c));
            a[i].len=1;a[i].lead=0;
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
            }
        }
        for (int i=0;i<M;i++) {
            for (int j=0;j<N-1;j++) {
                a[i].c[j+1]+=a[i].c[j]/M;
                a[i].c[j]%=M;
            }
            for (int j=N-1;j>=0;j--) {
                if (a[i].c[j]!=0) {
                    a[i].len=j+1;
                    break;
                }
            }
        }
        sort(a,a+M);
        ll ans=0;
        int ze=0;
        while (a[ze].lead) ze++;
        ll w=0;
        for (int i=0;i<M;i++) {
            if (i!=ze) {
                ll now=0;
                for (int j=a[i].len-1;j>=0;j--) {
                    now=(now*M%MO+a[i].c[j])%MO;
                }
                ans+=now*(++w)%MO;
                ans%=MO;
            }
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
