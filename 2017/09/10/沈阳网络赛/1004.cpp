#include <bits/stdc++.h>
using namespace std;

const int N=100010;
int a[N],b[N],d[N];
int T,n,k;

int LIS(int a[])
{
	int tot=0;
	for (int i=1;i<=n;i++) {
		if (tot==0||d[tot]<=a[i]) {
			d[++tot]=a[i];
		} else {
			*upper_bound(d+1,d+1+tot,a[i])=a[i];
		}
	}
	return tot;
}

int main()
{
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            b[i]=-a[i];
        }
        int x=LIS(a),y=LIS(b);
        if (n-x>k&&n-y>k) {
            puts("A is not a magic array.");
        } else {
            puts("A is a magic array.");
        }
    }
    return 0;
}
