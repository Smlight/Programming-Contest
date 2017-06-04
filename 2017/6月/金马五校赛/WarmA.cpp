#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX=1e6;
int prime[MAX+1],f[MAX+1];
int tot=0;

void init()
{
    for(int i=2;i<=MAX;i++) {
        if(!f[i]) prime[++tot]=i;
        for(int j=1;j<=tot&&prime[j]<=MAX/i;j++) {
            f[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
    f[0]=f[1]=0;
    for (int i=2;i<=MAX;i++) {
        f[i]=f[i-1]+(f[i]==0);
    }
}

int a,b,k;

bool check(int m)
{
    for (int i=a;i<=b-m+1;i++) {
        if (f[i+m-1]-f[i-1]<k) return false;
    }
    return true;
}

int bs(int l,int r)
{
    int res=-1;
    while (l<=r) {
        int m=(l+r)>>1;
        if (check(m)) {
            res=m;r=m-1;
        } else {
            l=m+1;
        }
    }
    return res;
}

int main()
{
    init();
    while (scanf("%d%d%d",&a,&b,&k)!=EOF) {
        printf("%d\n",bs(1,b-a+1));
    }
    return 0;
}
