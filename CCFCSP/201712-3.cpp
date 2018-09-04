#include <bits/stdc++.h>
using namespace std;

char s[22],t[22];
map<string,int> _weekday,_month;

void init()
{
    _weekday["sun"]=0;
    _weekday["mon"]=1;
    _weekday["tue"]=2;
    _weekday["wed"]=3;
    _weekday["thu"]=4;
    _weekday["fri"]=5;
    _weekday["sat"]=6;
    _month["jan"]=1;
    _month["feb"]=2;
    _month["mar"]=3;
    _month["apr"]=4;
    _month["may"]=5;
    _month["jun"]=6;
    _month["jul"]=7;
    _month["aug"]=8;
    _month["sep"]=9;
    _month["oct"]=10;
    _month["nov"]=11;
    _month["dec"]=12;
}

int to_int(char s[],int len,int k)
{
    int x;
    if (k==1||(s[0]>='0'&&s[0]<='9')) {
        x=0;
        for (int i=0;i<len;i++) {
            x=x*10+s[i]-'0';
        }
        return x;
    }
    char c=s[len];
    for (int i=0;i<len;i++) {
        if (s[i]<'a') s[i]+='a'-'A';
    }
    s[len]=0;
    string t(s);
    if (k==2) x=_month[t];
    else x=_weekday[t];
    s[len]=c;
    return x;
}

void to_intrange(char s[],int len,bool a[],int k)
{
    int p=0;
    while (p<len&&s[p]!='-') ++p;
    int x,y;
    if (p==len) {
        x=to_int(s,len,k);
        a[x]=true;
    } else {
        x=to_int(s,p,k);
        y=to_int(s+p+1,len-p-1,k);
        while (x<=y) a[x++]=true;
    }
}

void to_intmap(char s[],bool a[],int sz,int k)
{
    if (s[0]=='*') {
        for (int i=0;i<sz;i++) a[i]=true;
        return;
    }
    int p=0,st=0;
    while (true) {
        while (s[p]&&s[p]!=',') ++p;
        to_intrange(s+st,p-st,a,k);
        if (!s[p]) break;
        st=++p;
    }
}

struct Crontab {
    bool MM[60],HH[24],dd[32],mm[13],ww[7];
    char comm[111];
} c[22];

int zeller(int y,int m,int d)
{
    if (m<=2) y-=1,m+=12;
    int c=y/100; y-=c*100;
    int wd=(c/4)-2*c+(y+y/4)+(13*(m+1)/5)+d+6;
    return wd%7;
}

int days[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool leap(int y)
{
    return y%400==0||(y%100!=0&&y%4==0);
}

int month_day(int y,int m)
{
    if (m!=2) return days[m];
    return days[m]+leap(y);
}

struct Scher {
    int yy,mm,dd,HH,MM,ww;
    Scher(char s[]) {
        yy=mm=dd=HH=MM=ww=0;
        for (int i=0;i<4;i++) yy=yy*10+s[i]-'0';
        for (int i=4;i<6;i++) mm=mm*10+s[i]-'0';
        for (int i=6;i<8;i++) dd=dd*10+s[i]-'0';
        for (int i=8;i<10;i++) HH=HH*10+s[i]-'0';
        for (int i=10;i<12;i++) MM=MM*10+s[i]-'0';
        ww=zeller(yy,mm,dd);
    }
    void inc() {
        if (++MM==60) {
            MM=0;
            if (++HH==24) {
                HH=0;
                if (++ww==7) ww=0;
                if (++dd==month_day(yy,mm)+1) {
                    dd=1;
                    if (++mm==12+1) {
                        mm=1;
                        ++yy;
                    }
                }
            }
        }
    }
    bool operator==(const Scher &R) const {
        return yy==R.yy&&mm==R.mm&&dd==R.dd&&HH==R.HH&&MM==R.MM;
    }
};

int main()
{
    init();
    int n;
    scanf("%d%s%s",&n,s,t);
    Scher S(s),T(t);
    for (int i=1;i<=n;i++) {
        scanf("%s",s);
        to_intmap(s,c[i].MM,sizeof(c[i].MM)/sizeof(bool),1);
        scanf("%s",s);
        to_intmap(s,c[i].HH,sizeof(c[i].HH)/sizeof(bool),1);
        scanf("%s",s);
        to_intmap(s,c[i].dd,sizeof(c[i].dd)/sizeof(bool),1);
        scanf("%s",s);
        to_intmap(s,c[i].mm,sizeof(c[i].mm)/sizeof(bool),2);
        scanf("%s",s);
        to_intmap(s,c[i].ww,sizeof(c[i].ww)/sizeof(bool),3);
        scanf("%s",c[i].comm);
    }
    while (!(S==T)) {
        for (int i=1;i<=n;i++) {
            if (!c[i].MM[S.MM]||!c[i].HH[S.HH]) continue;
            if (!c[i].dd[S.dd]||!c[i].ww[S.ww]||!c[i].mm[S.mm]) continue;
            printf("%04d%02d%02d%02d%02d %s\n",S.yy,S.mm,S.dd,S.HH,S.MM,c[i].comm);
        }
        S.inc();
    }
    return 0;
}
