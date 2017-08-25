#include <bits/stdc++.h>
using namespace std;

const int N=100000;
double area[N+5];

void init()
{
    for (int i=4;i<=N;i++) {
        if (i%4==0) {
            area[i]=(i/4)*(i/4)*2;
        } else if (i%4==1) {
            area[i]=area[i-1]+(i/4-1)+0.5;
        } else {
            area[i]=area[i-1]+i/4+0.5;
        }
    }
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",lower_bound(area,area+N,n)-area);
    }
    return 0;
}
