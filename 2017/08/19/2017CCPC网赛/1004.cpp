#include <bits/stdc++.h>
using namespace std;

const int N=1000010;
const int MO=1e9+7;
int nt[N],val[N];
char a[N],b[N];

void KMP(char x[],int nt[],int val[])
{
    nt[0]=-1;
    nt[1]=0;
    val[0]=0;
    val[1]=1;
    int l=strlen(x);
    for (int i=1;i<l;i++) {
        nt[i+1]=0;
        val[i+1]=i+1;
        for (int j=nt[i];j>=0;j=nt[j]) {
            if (x[i]==x[j]) {
                nt[i+1]=j+1;
                val[i+1]+=val[j+1];
                val[i+1]%=MO;
                break;
            }
        }
    }
}

int main ()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",a);
        scanf("%s",b);
        int la=strlen(a);
        int lb=strlen(b);
        reverse(a,a+la);
        reverse(b,b+lb);
        KMP(b,nt,val);
        int ans=0;
        int j=0;
        for (int i=0;i<la;i++) {
            int k=j;
            for (j=0;k>=0;k=nt[k]) {
                if (a[i]==b[k]) {
                    j=k+1;
                    break;
                }
            }
            ans+=val[j];
            if (ans>=MO) ans%=MO;
        }
        printf("%d\n",ans);
    }
    return 0;
}
