#include <bits/stdc++.h>
using namespace std;

int a[4][20]={
    {
        0,0,1,1,1,2,2,2,3,3,3,4,4
    },
    {
        0,0,0,0,0,1,2,3,4
    },
    {
        0,0,0,0,0,1,2,2,2,2,2,3,4,4,4,4,4
    },
    {
        0,0,0,0,0,1,2,2,2,2,2,3,4,4,4,4,4
    },
};
int b[4][20]={
    {
        0,4,0,1,4,0,2,4,0,3,4,0,4
    },
    {
        0,1,2,3,4,2,2,2,2
    },
    {
        0,1,2,3,4,0,0,1,2,3,4,0,0,1,2,3,4
    },
    {
        0,1,2,3,4,0,0,1,2,3,4,4,0,1,2,3,4
    },
};
int lim[4]={13,9,17,17};
char mp[505][505];

int check(int i,int j,int k)
{
    int res=0;
    int no=0;
    for (int l=0;l<lim[k];l++) {
        if (mp[i+a[k][l]][j+b[k][l]]!='#') {
            no=1;break;
        }
    }
    res+=!no;
    no=0;
    for (int l=0;l<lim[k];l++) {
        if (mp[i+b[k][l]][j+4-a[k][l]]!='#') {
            no=1;break;
        }
    }
    res+=!no;
    no=0;
    for (int l=0;l<lim[k];l++) {
        if (mp[i+4-a[k][l]][j+4-b[k][l]]!='#') {
            no=1;break;
        }
    }
    res+=!no;
    no=0;
    for (int l=0;l<lim[k];l++) {
        if (mp[i+4-b[k][l]][j+a[k][l]]!='#') {
            no=1;break;
        }
    }
    res+=!no;
    return res;
}

int cnt[4];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0; i<n; i++) {
            scanf("%s",mp[i]);
        }
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i+4<n;i++) {
            for (int j=0;j+4<m;j++) {
                for (int k=0;k<4;k++) {
                    cnt[k]+=check(i,j,k);
                }
            }
        }
        printf("N: %d\nT: %d\nE: %d\nS: %d\n",cnt[0]/2,cnt[1],cnt[2],cnt[3]/2);
    }
    return 0;
}
