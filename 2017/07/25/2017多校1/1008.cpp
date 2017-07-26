#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
const int N=1e7+5;
unsigned x, y, z;
uint a[N];
struct Query {
    int id,k;
    unsigned ans;
} b[110];

inline unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}

bool cmp1(const Query &a,const Query &b)
{
    return a.k<b.k;
}

bool cmp2(const Query &a,const Query &b)
{
    return a.id<b.id;
}

void quickSelect(uint a[],int l,int r,int rank)
{
    int i=l,j=r;
    uint mid=a[(l+r)/2];
    do {
        while (a[i]<mid) ++i;
        while (a[j]>mid) --j;
        if (i<=j) {
            swap(a[i],a[j]);
            ++i;--j;
        }
    } while (i<=j);
    if (l<=j&&rank<=j-l+1) quickSelect(a,l,j,rank);
    if (i<=r&&rank>=i-l+1) quickSelect(a,i,r,rank-(i-l));
}

int main()
{
    int n,m,cas=0;
    while (scanf("%d%d%u%u%u",&n,&m,&x,&y,&z)!=EOF) {
        for (int i=1;i<=m;i++) {
            scanf("%d",&b[i].k);
            b[i].id=i;b[i].k++;
        }
        for (int i=1;i<=n;i++) {
            a[i]=rng61();
        }
        sort(b+1,b+1+m,cmp1);
        int pre=n;
        for (int i=m;i>=1;i--) {
            if (i<m&&b[i].k==b[i+1].k) {
                b[i].ans=b[i+1].ans;
            } else {
                quickSelect(a,1,pre,b[i].k);
                b[i].ans=a[b[i].k];
            }
            pre=b[i].k;
        }
        sort(b+1,b+1+m,cmp2);
        printf("Case #%d:",++cas);
        for (int i=1;i<=m;i++) {
            printf(" %u",b[i].ans);
        }
        puts("");
    }
    return 0;
}
