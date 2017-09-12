#include <bits/stdc++.h>
using namespace std;

const int N=100010;
int nxt[N],c[N+10];
bool b[N];
char s[N],t[N];

void ins(int x,int d)
{
    for (int i=x;i<=N;i+=i&(-i)) {
        c[i]+=d;
    }
}

int get(int x)
{
    int res=0;
    for (int i=x;i;i-=i&(-i)) {
        res+=c[i];
    }
    return res;
}

void kmp_pre(char x[],int m,int nxt[])
{
	int i,j;
	j=nxt[0]=-1;
	i=0;
	while(i<m) {
		while(-1!=j && x[i]!=x[j])j=nxt[j];
		nxt[++i]=++j;
	}
}

void KMP_Count(char x[],int m,char y[],int n,int pre)
{
	int i,j;
	i=j=0;
	while(i<n) {
		while(-1!=j && y[i]!=x[j]) j=nxt[j];
		i++;
		j++;
		if(j>=m) {
            b[pre+i-m]=true;
            ins(pre+i-m+1,1);
			j=nxt[j];
		}
	}
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        scanf("%s",s);
        scanf("%s",t);
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        int ls=strlen(s);
        int lt=strlen(t);
        kmp_pre(t,lt,nxt);
        KMP_Count(t,lt,s,ls,0);
        while (n--) {
            char op[2];
            scanf("%s",op);
            if (op[0]=='Q') {
                int l,r;
                scanf("%d %d",&l,&r);
                if (r-l+1<lt) {
                    puts("0");
                } else {
                    printf("%d\n",get(r-lt+1)-get(l-1));
                }
            } else {
                int x;char ch;
                scanf("%d %c",&x,&ch);
                x--;
                if (s[x]!=ch) {
                    int p=max(0,x-lt+1);
                    for (int i=p;i<=x;i++) {
                        if (b[i]) {
                            b[i]=false;
                            ins(i+1,-1);
                        }
                    }
                    s[x]=ch;
                    KMP_Count(t,lt,s+p,ls-p,p);
                }
            }
        }
        puts("");
    }
    return 0;
}
