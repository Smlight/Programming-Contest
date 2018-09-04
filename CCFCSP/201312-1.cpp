#include <bits/stdc++.h>
using namespace std;

const int M=10001;
int c[M];

int main()
{
    int n,x;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&x);
        ++c[x];
    }
    int mx=*max_element(c,c+M);
    for (int i=0;i<M;i++) {
        if (c[i]==mx) {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
