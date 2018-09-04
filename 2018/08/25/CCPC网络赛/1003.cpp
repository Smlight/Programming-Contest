#include <bits/stdc++.h>
using namespace std;

void write(int x)
{
    if (x==0) { putchar('0'); return; }
    char s[20];
    int i=0;
    while (x) s[i++]=x%10+'0',x/=10;
    for (i--;i>=0;i--) putchar(s[i]);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int p;
        scanf("%d",&p);
        for (int i=0;i<p;i++) {
            for (int j=0;j<p;j++) {
                write(i*j%p);
                if (j==p-1) puts("");
                else putchar(' ');
            }
        }
        for (int i=0;i<p;i++) {
            for (int j=0;j<p;j++) {
                write(i*j%p);
                if (j==p-1) puts("");
                else putchar(' ');
            }
        }
    }
    return 0;
}