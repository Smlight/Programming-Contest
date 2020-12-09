#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    // printf("%d\n",n);
    int k=1;
    int c[4]={0};
    int p=0;
    for (int i=1;i<=n;) {
        if (k%7==0 || k%10==7 || k/10%10==7 || k/100%10==7 || k/1000%10==7) {
            c[p]++;
            // printf("%d\n",c[p]);
        } else {
            ++i;
        }
        ++k;
        p=(p+1)%4;
    }
    for (int i=0;i<4;i++) {
        printf("%d\n",c[i]);
    }
    return 0;
}
