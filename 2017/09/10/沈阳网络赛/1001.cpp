#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100010;
int t1[MAXN],t2[MAXN],c[MAXN];
char s[MAXN];
int sa[MAXN];
int rk[MAXN],hei[MAXN];
int mm[MAXN],best[20][MAXN];

bool cmp(int *r,int a,int b,int l)
{
	return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(char str[],int sa[],int rk[],int hei[],int n,int m)
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
		hei[rk[i]] = k;
	}
}

void initRMQ(int n)
{
	mm[0]=-1;
	for(int i=1; i<=n; i++)
		mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
	for(int i=1; i<=n; i++)best[0][i]=i;
	for(int i=1; i<=mm[n]; i++)
		for(int j=1; j+(1<<i)-1<=n; j++) {
			int a=best[i-1][j];
			int b=best[i-1][j+(1<<(i-1))];
			if(hei[a]<hei[b])best[i][j]=a;
			else best[i][j]=b;
		}
}

int askRMQ(int a,int b)
{
	int t;
	t=mm[b-a+1];
	b-=(1<<t)-1;
	a=best[t][a];
	b=best[t][b];
	return hei[a]<hei[b]?a:b;
}

int main()
{
    int T,k;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&k);
        scanf("%s",s);
        int len=strlen(s);
        da(s,sa,rk,hei,len,128);
        initRMQ(len);
        ll ans=0;hei[len+1]=0;
        for (int l=1;l+k-1<=len;l++) {
            int r=l+k-1;
            int a=max(hei[l],hei[r+1]),b;
            if (l==r) b=len-sa[l];
            else b=hei[askRMQ(l+1,r)];
            if (b>a) ans+=b-a;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
