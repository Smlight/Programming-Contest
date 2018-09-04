#include <bits/stdc++.h>
using namespace std;

const int MN=22;
char s[MN],a[MN],b[MN],res[MN];
int len;

void mndfs(int pos,int k)
{
    if (pos>len||k==0) {
        if (strcmp(a,res)<0) {
            strcpy(res,a);
        }
        return;
    }
    if (b[pos]==a[pos]) mndfs(pos+1,k);
    for (int i=pos+1;i<len;i++) {
        if (a[i]==b[pos]) {
            swap(a[i],a[pos]);
            mndfs(pos+1,k-1);
            swap(a[i],a[pos]);
        }
    }
}

void mxdfs(int pos,int k)
{
    if (pos>len||k==0) {
        if (strcmp(a,res)>0) {
            strcpy(res,a);
        }
        return;
    }
    if (b[pos]==a[pos]) mxdfs(pos+1,k);
    for (int i=pos+1;i<len;i++) {
        if (a[i]==b[pos]) {
            swap(a[i],a[pos]);
            mxdfs(pos+1,k-1);
            swap(a[i],a[pos]);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int k;
        scanf("%s%d",s,&k);
        len=strlen(s);

        strcpy(a,s);
        strcpy(b,s);
        sort(b,b+len);
        int p=0;
        while (p<len&&b[p]=='0') ++p;
        if (p) swap(b[0],b[p]);
        strcpy(res,s);
        mndfs(0,k);
        printf("%s ",res);

        strcpy(a,s);
        sort(b,b+len,greater<char>());
        strcpy(res,s);
        mxdfs(0,k);
        printf("%s\n",res);
    }
    return 0;
}