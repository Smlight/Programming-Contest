#include <bits/stdc++.h>
using namespace std;

const int N=22;
char s[N];

bool sep(char s[N])
{
    for (int i=0;s[i];i++) {
        if (s[i]=='.') return true;
    }
    return false;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int h,m;
        scanf("%d%d",&h,&m);
        h-=8;
        if (h<0) h+=24;
        scanf("%s",s);
        int x,y;
        if (sep(s)) sscanf(s+4,"%d.%d",&x,&y);
        else sscanf(s+4,"%d",&x),y=0;
//        printf("%d %d\n",x,y);
        if (s[3]=='+') {
            m+=y*6;
            if (m>=60) {
                m-=60;
                h+=1;
            }
            h+=x;
            if (h>=24) {
                h-=24;
            }
        } else {
            m-=y*6;
            if (m<0) {
                m+=60;
                h-=1;
            }
            h-=x;
            if (h<0) {
                h+=24;
            }
        }
        printf("%02d:%02d\n",h,m);
    }
    return 0;
}