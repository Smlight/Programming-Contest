#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        int ans=0;
        while (n--) {
            int a,b,c,ab,bc,ac,abc;
            scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);
            int ra=a-(ab+ac-abc);
            int rb=b-(ab+bc-abc);
            int rc=c-(ac+bc-abc);
            int rab=ab-abc;
            int rbc=bc-abc;
            int rac=ac-abc;
            if (ra<0||rb<0||rc<0||rab<0||rac<0||rbc<0) continue;
            ans=max(ans,ra+rb+rc+rab+rac+rbc+abc);
        }
        printf("%d\n",ans);
    }
    return 0;
}
