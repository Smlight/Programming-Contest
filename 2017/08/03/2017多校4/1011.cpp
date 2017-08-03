#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int pos[4]={0,5,12,17};
int P[10]={123567,36,13457,13467,2346,12467,124567,136,1234567,123467};
char mp[30][30];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        for (int i=0;i<7;i++) {
            scanf("%s",mp[i]);
        }
        string ans;
        for (int i=0;i<4;i++) {
            int p=pos[i];
            int x=0;
            if (mp[0][p+1]=='X'&&mp[0][p+2]=='X') x=x*10+1;
            if (mp[1][p]=='X'&&mp[2][p]=='X') x=x*10+2;
            if (mp[1][p+3]=='X'&&mp[2][p+3]=='X') x=x*10+3;
            if (mp[3][p+1]=='X'&&mp[3][p+2]=='X') x=x*10+4;
            if (mp[4][p]=='X'&&mp[5][p]=='X') x=x*10+5;
            if (mp[4][p+3]=='X'&&mp[5][p+3]=='X') x=x*10+6;
            if (mp[6][p+1]=='X'&&mp[6][p+2]=='X') x=x*10+7;
            for (int j=0;j<10;j++) {
                if (P[j]==x) {
                    ans+=char(j+'0');
                    break;
                }
            }
            if (i==1) ans+=':';
        }
        printf("%s\n",ans.c_str());
    }
    return 0;
}
