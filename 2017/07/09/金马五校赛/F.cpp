#include <bits/stdc++.h>
using namespace std;

const int N=50010;
int n;
int a[N],b[N],c[N],d[N];

void LIS(int a[])
{
	int tot=0;
	for (int i=1;i<=n;i++) {
		if (tot==0||d[tot]<a[i]) {
			d[b[i]=++tot]=a[i];
		} else {
			int p=lower_bound(d+1,d+1+tot,a[i])-d;
			d[b[i]=p]=a[i];
		}
	}
	tot=0;
	for (int i=n;i>=1;i--) {
		if (tot==0||d[tot]<a[i]) {
			d[c[i]=++tot]=a[i];
		} else {
			int p=lower_bound(d+1,d+1+tot,a[i])-d;
			d[c[i]=p]=a[i];
		}
	}
}

int main()
{
    while (scanf("%d",&n)!=EOF) {
        for (int i=1;i<=n;i++) {
            scanf("%d",a+i);
        }
        LIS(a);
        int ans=0;
        for (int i=1;i<=n;i++) {
            ans=max(min(b[i],c[i])*2-1,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
