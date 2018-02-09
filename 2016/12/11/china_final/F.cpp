#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=300030;
char s[MAXN];
int str[MAXN];
int sa[MAXN];
int t1[MAXN],t2[MAXN],c[MAXN];
int rk[MAXN],height[MAXN];

bool cmp(int *r,int a,int b,int l)
{
	return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int str[],int sa[],int rank[],int height[],int n,int m)
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
	for(i = 0; i <= n; i++)rank[sa[i]] = i;
	for(i = 0; i < n; i++) {
		if(k)k--;
		j = sa[rank[i]-1];
		while(str[i+k] == str[j+k])k++;
		height[rank[i]] = k;
	}
}

void solve(int lim,int n)
{
    int ans=n+1,pos=-1;
    for (int i=1;i<=n;i++) {
        while (i<=n&&sa[i]>=lim) i++;
        if (i>n) break;
        int cur1=height[i];
        for (int p=i-1;p&&sa[p]<lim;p--) {
            cur1=min(cur1,height[p]);
        }
        int cur2=height[i+1];
        for (int q=i+1;q<=n&&sa[q]<lim;q++) {
            cur2=min(cur2,height[q+1]);
        }
        int cur=max(cur1,cur2);
        if (cur<lim-sa[i]) {
            if (cur+1<ans) {
                ans=cur+1;
                pos=sa[i];
            }
        }
    }
    if (pos==-1) {
        puts("Impossible");
    } else {
        for (int i=0;i<ans;i++) {
            putchar(str[pos+i]);
        }
        puts("");
    }
}

int main()
{
    int T,n;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		scanf("%d",&n);
		int up=140,len=0,firstl;
		for (int i=1;i<=n;i++) {
            scanf("%s",s);
            int nl=strlen(s);
            if (i==1) firstl=nl;
            for (int j=0;j<nl;j++) {
                str[len++]=s[j];
            }
            str[len++]=up+i;
		}
		str[--len]=0;
		da(str,sa,rk,height,len,up+n);
		printf("Case #%d: ",t);
		solve(firstl,len);
	}
	return 0;
}
