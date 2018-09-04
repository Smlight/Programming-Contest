#include <bits/stdc++.h>
using namespace std;

const int MAXN=20000000;
const int N=20000000;
int euler[MAXN+5];
long long ans[N+5];

void getEuler()
{
    euler[1]=1;
    for(int i=2;i<=MAXN;i++) {
        if(!euler[i]) {
            for(int j=i;j<=MAXN;j+=i) {
                if(!euler[j]) euler[j]=j;
                euler[j]=euler[j]/i*(i-1);
            }
        }
    }
}

template <class T>
inline bool read(T &x)
{
    char c;
    if (c=getchar(),c==EOF) return false;//EOF
    while (c<'0'||c>'9') c=getchar();
    x=(c-'0');
    while (c=getchar(),c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c-'0');
    return true;
}

void write(long long x)
{
    if (x==0) { putchar('0'); return; }
    if (x<0) putchar('-'),x=-x;
    char s[33];
    int i=0;
    while (x) s[i++]=x%10+'0',x/=10;
    for (i--;i>=0;i--) putchar(s[i]);
}

int main()
{
    getEuler();
    ans[0]=0;
    ans[1]=0;
    ans[2]=1;
    for (int i=2;i<=N;i++) {
        if (i&1) {
            ans[i]=ans[i-1]+euler[i]/2;
        } else {
            ans[i]=ans[i-1]+euler[i];
        }
    }
    int T;
    read(T);
    while (T--) {
        int n;
        read(n);
        write(ans[n]);
        puts("");
    }
    return 0;
}