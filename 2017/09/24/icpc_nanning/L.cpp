#include <bits/stdc++.h>
using namespace std;

const int N=1000005;
int a[N],d[N];
int x,n=0;

int LIS(int a[])
{
	int tot=0;
	for (int i=1; i<=n; i++) {
		if (tot==0||d[tot]<=a[i]) {
			d[++tot]=a[i];
		} else {
			int p=upper_bound(d+1,d+1+tot,a[i])-d;
			d[p]=a[i];
		}
	}
	return tot;
}

int main()
{
    while (scanf("%d",&x)!=EOF) {
        if (x>=10000) {
            for (int i=1;i<=5;i++) {
                a[++n]=x-10000;
            }
        } else if (x>=0) {
            a[++n]=x;
        }
    }
    printf("%d\n",LIS(a));
    return 0;
}
