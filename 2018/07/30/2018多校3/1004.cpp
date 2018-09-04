#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        if(n == 1) puts("5");
        else printf("%d\n", n + 5);
    }
    return 0;
}