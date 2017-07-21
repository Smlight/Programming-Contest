#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int MAXN=200010;
int a[MAXN];
int t1[MAXN],t2[MAXN],c[MAXN];

bool cmp(int *r,int a,int b,int l)
{
	return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int str[],int sa[],int rk[],int height[],int n,int m)
{
	n++;
	int i, j, p, *x = t1, *y = t2;
	for(i = 0; i < m; i++)c[i] = 0;
	for(i = 0; i < n; i++)c[x[i] = str[i]]++;
	for(i = 1; i < m; i++)c[i] += c[i-1];
	for(i = n-1; i >= 0; i--)sa[--c[x[i]]] = i;
	for(j = 1; j <= n; j <<= 1) {
		p = 0;
		for(i = n-j; i < n; i++)y[p++] = i;
		for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
		for(i = 0; i < m; i++)c[i] = 0;
		for(i = 0; i < n; i++)c[x[y[i]]]++;
		for(i = 1; i < m; i++)c[i] += c[i-1];
		for(i = n-1; i >= 0; i--)sa[--c[x[y[i]]]] = y[i];
		swap(x,y);
		p = 1;
		x[sa[0]] = 0;
		for(i = 1; i < n; i++)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		if(p >= n)break;
		m = p;
	}
	int k = 0;
	n--;
	for(i = 0; i <= n; i++)rk[sa[i]] = i;
	for(i = 0; i < n; i++) {
		if(k)k--;
		j = sa[rk[i]-1];
		while(str[i+k] == str[j+k])k++;
		height[rk[i]] = k;
	}
}

int rk[MAXN],height[MAXN];
int r[MAXN];
int sa[MAXN];

int main()
{
    int T,cas=0;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) {
            scanf("%d",a+i);
        }
        for (int i=n+1;i<n+m+1;i++) {
            scanf("%d",a+i);
        }
        printf("Case %d: ",++cas);
        a[n]=a[n+m+1]=0;
        da(a,sa,rk,height,n+m+1,10);
        int j,k;
        for (j=k=0;j<n&&k<m;) {
            if (rk[n+1+k]>rk[j]) {
                printf("%d",a[n+1+k++]);
            } else {
                printf("%d",a[j++]);
            }
        }
        for (;k<m;k++) {
            printf("%d",a[n+1+k]);
        }
        for (;j<n;j++) {
            printf("%d",a[j]);
        }
        puts("");
    }
    return 0;
}
