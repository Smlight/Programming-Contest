#include <bits/stdc++.h>
using namespace std;

const int N=105;
int a[N];
int c;

bool alright(int a[],int n)
{
    for (int i=1;i<=n;i++) {
        if (a[i]==-1) return false;
    }
    return true;
}

void flip(int a[],int n)
{
    for (int i=1;i<=n;i++) {
        if (a[i]==0) a[i]=1;
        else if (a[i]==1) a[i]=0;
    }
}

void output(int a[],int n)
{
    for (int i=1;i<=n;i++) {
        printf("%d",a[i]);
    }
    puts("");
    fflush(stdout);
    char st[4];
    scanf("%s",st);
    // fprintf(stderr,"St: %s\n",st);
    // fflush(stderr);
    if (st[0]!='Y') exit(0);
}

void debug(int a[],int n)
{
    for (int i=1;i<=n;i++) {
        fprintf(stderr,"%d ",a[i]);
    }
    fprintf(stderr,"\n");
    fflush(stderr);
}

int query(int x)
{
    int y;
    printf("%d\n",x);
    fflush(stdout);
    // fprintf(stderr,"X: %d\n",x);
    // fflush(stderr);
    scanf("%d",&y);
    // fprintf(stderr,"Y: %d\n",y);
    ++c;
    return y;
}

int main()
{
    int T,n;
    scanf("%d%d",&T,&n);
    // fprintf(stderr,"%d %d\n",T,n);
    while (T--) {
        memset(a,-1,sizeof(a));
        c=0;
        for (int i=1;i<=5;i++) {
            a[i]=query(i);
            a[n+1-i]=query(n+1-i);
        }
        if (n<=10) {
            output(a,n);
            continue;
        }
        while (c<=150) {
            if (c%10==0) {
                int p=0,q=0;
                // debug(a,n);
                for (int i=1;i<=n;i++) {
                    for (int j=i+1;j<=n;j++) {
                        if (a[i]!=-1&&a[j]!=-1) {
                            set<int> s;
                            s.insert((a[i]<<1)^(a[j]));
                            s.insert((a[n+1-i]<<1)^(a[n+1-j]));
                            s.insert((a[i]<<1)^(a[j])^3);
                            s.insert((a[n+1-i]<<1)^(a[n+1-j])^3);
                            if (s.size()==4) {
                                p=i;q=j;
                                break;
                            }
                        }
                    }
                    if (p) break;
                }
                if (!p) {
                    int x=query(1);
                    if (x!=a[1]) flip(a,n);
                    x=query(1);
                } else {
                    vector<int> ve;
                    ve.push_back((a[p]<<1)^(a[q]));
                    ve.push_back((a[n+1-p]<<1)^(a[n+1-q]));
                    ve.push_back((a[p]<<1)^(a[q])^3);
                    ve.push_back((a[n+1-p]<<1)^(a[n+1-q])^3);
                    int x=query(p);
                    int y=query(q);
                    x<<=1;
                    x^=y;
                    int pos=0;
                    while (ve[pos]!=x) ++pos;
                    if (pos&1) reverse(a+1,a+n+1);
                    if (pos&2) flip(a,n);
                }
            } else {
                int pos=1;
                while (pos<=n && a[pos]!=-1) ++pos;
                if (pos>n) {
                    output(a,n);
                    break;
                }
                a[pos]=query(pos);
                a[n+1-pos]=query(n+1-pos);
            }
        }
    }
    return 0;
}