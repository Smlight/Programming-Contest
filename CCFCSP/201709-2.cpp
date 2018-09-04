#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int a[N];
struct Event {
    int op,t,n;
    Event() {}
    Event(int a,int b,int c):op(a),t(b),n(c) {}
    bool operator<(const Event &R) const {
        if (t!=R.t) return t<R.t;
        if (op!=R.op) return op>R.op;
        return n<R.n;
    }
} ev[N*2];

int main()
{
    int n,k,t=0;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) a[i]=i;
    for (int i=1;i<=k;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ev[++t]=Event(0,b,a);
        ev[++t]=Event(1,b+c,a);
    }
    sort(ev+1,ev+1+t);
    for (int i=1;i<=t;i++) {
        if (ev[i].op) {
            int k=1;
            while (a[k]!=0) ++k;
            a[k]=ev[i].n;
        } else {
            int k=1;
            while (a[k]!=ev[i].n) ++k;
            a[k]=0;
        }
//        for (int i=1;i<=n;i++) {
//            printf("%d%c",a[i]," \n"[i==n]);
//        }
    }
    for (int i=1;i<=n;i++) {
        printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}
