#include <bits/stdc++.h>
using namespace std;

char P[10]="DCBAS";

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        int sc=0,dw=0,jj=0,jjcount=0,jjwin=0,x;
        for (int i=1;i<=n;i++) {
            scanf("%d",&x);
            if (jj) {
                jjwin+=x;
                jjcount++;
                if (jjwin==2) {
                    dw=min(dw+1,4);
                    sc=0;
                    jj=0;
                } else if (jjcount==3||jjwin==0&&jjcount==2) {
                    sc=60;
                    jj=0;
                }
            } else {
                if (x) {
                    sc+=10;
                    if (sc>=100) {
                        jj=1;
                        jjwin=jjcount=0;
                    }
                } else {
                    sc=max(sc-5,0);
                }
            }
        }
        printf("%c\n",P[dw]);
    }
    return 0;
}
