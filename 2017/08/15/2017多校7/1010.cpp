#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N],b[N];
vector<int> ve;

void read(int &x)
{
	char c=getchar(); x=0;
	while (!(c>='0'&&c<='9')) c=getchar();
	for (;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
}

void write(int x)
{
	if (x==0)
	{
		putchar('0');
		return;
	}
	if (x<0) putchar('-'),x=-x;
	char s[20];
	int i=0;
	while (x)
	{
		s[i++]=x%10+'0';
		x/=10;
	}
	for (i--;i>=0;i--) putchar(s[i]);
}

int main()
{
    int T,n,m;
    read(T);
    while (T--) {
        read(n);
        read(m);
        for (int i=0;i<n;i++) {
            read(a[i]);b[i]=0;
        }
        --m;
        ve.clear();
        for (int i=0;i<n;i++) {
            if (((m+i)&i)==i) {
                ve.push_back(i);
            }
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<ve.size();j++) {
                if (ve[j]>i) break;
                b[i]^=a[i-ve[j]];
            }
        }
        for (int i=0;i<n;i++) {
            write(b[i]);
            if (i==n-1) puts("");
            else putchar(' ');
        }
    }
    return 0;
}
