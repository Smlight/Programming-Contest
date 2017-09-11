#include <bits/stdc++.h>
using namespace std;

struct Cube {
    int a[73];
    bool operator ==(const Cube &R) {
        for (int i=1;i<=72;i++) {
            if (a[i]!=R.a[i]) return false;
        }
        return true;
    }
    bool solved() {
        for (int i=1;i<=8;i++) {
            int p=(i-1)*9;
            for (int j=1;j<=9;j++) {
                if (a[p+j]!=a[p+1]) return false;
            }
        }
        return true;
    }
};

Cube R(Cube x)
{
    swap(x.a[9],x.a[64]);
    swap(x.a[64],x.a[23]);
    swap(x.a[41],x.a[55]);
    swap(x.a[55],x.a[18]);
    swap(x.a[42],x.a[57]);
    swap(x.a[57],x.a[17]);
    swap(x.a[38],x.a[58]);
    swap(x.a[58],x.a[16]);
    swap(x.a[39],x.a[62]);
    swap(x.a[62],x.a[15]);
    swap(x.a[37],x.a[63]);
    swap(x.a[63],x.a[14]);

    swap(x.a[54],x.a[46]);
    swap(x.a[46],x.a[50]);
    swap(x.a[53],x.a[48]);
    swap(x.a[48],x.a[51]);
    swap(x.a[49],x.a[47]);
    swap(x.a[47],x.a[52]);
    return x;
}
Cube L(Cube x)
{
    swap(x.a[46],x.a[5]);
    swap(x.a[5],x.a[27]);
    swap(x.a[37],x.a[36]);
    swap(x.a[36],x.a[59]);
    swap(x.a[39],x.a[35]);
    swap(x.a[35],x.a[60]);
    swap(x.a[40],x.a[34]);
    swap(x.a[34],x.a[56]);
    swap(x.a[44],x.a[33]);
    swap(x.a[33],x.a[57]);
    swap(x.a[45],x.a[32]);
    swap(x.a[32],x.a[55]);

    swap(x.a[64],x.a[68]);
    swap(x.a[68],x.a[72]);
    swap(x.a[66],x.a[69]);
    swap(x.a[69],x.a[71]);
    swap(x.a[65],x.a[70]);
    swap(x.a[70],x.a[67]);
    return x;
}
Cube U(Cube x)
{
    swap(x.a[68],x.a[54]);
    swap(x.a[54],x.a[19]);
    swap(x.a[45],x.a[14]);
    swap(x.a[14],x.a[28]);
    swap(x.a[44],x.a[15]);
    swap(x.a[15],x.a[30]);
    swap(x.a[43],x.a[11]);
    swap(x.a[11],x.a[31]);
    swap(x.a[42],x.a[12]);
    swap(x.a[12],x.a[35]);
    swap(x.a[41],x.a[10]);
    swap(x.a[10],x.a[36]);

    swap(x.a[1],x.a[5]);
    swap(x.a[5],x.a[9]);
    swap(x.a[3],x.a[6]);
    swap(x.a[6],x.a[8]);
    swap(x.a[2],x.a[7]);
    swap(x.a[7],x.a[4]);
    return x;
}
Cube D(Cube x)
{
    swap(x.a[37],x.a[18]);
    swap(x.a[18],x.a[32]);
    swap(x.a[46],x.a[23]);
    swap(x.a[23],x.a[72]);
    swap(x.a[48],x.a[24]);
    swap(x.a[24],x.a[71]);
    swap(x.a[47],x.a[25]);
    swap(x.a[25],x.a[67]);
    swap(x.a[51],x.a[26]);
    swap(x.a[26],x.a[66]);
    swap(x.a[50],x.a[27]);
    swap(x.a[27],x.a[64]);

    swap(x.a[55],x.a[63]);
    swap(x.a[63],x.a[59]);
    swap(x.a[57],x.a[62]);
    swap(x.a[62],x.a[60]);
    swap(x.a[58],x.a[61]);
    swap(x.a[61],x.a[56]);
    return x;
}
Cube ML(Cube x)
{
    swap(x.a[49],x.a[25]);
    swap(x.a[2],x.a[49]);
    swap(x.a[48],x.a[26]);
    swap(x.a[6],x.a[48]);
    swap(x.a[47],x.a[22]);
    swap(x.a[7],x.a[47]);
    swap(x.a[58],x.a[29]);
    swap(x.a[43],x.a[58]);
    swap(x.a[62],x.a[30]);
    swap(x.a[42],x.a[62]);
    swap(x.a[61],x.a[31]);
    swap(x.a[38],x.a[61]);
    return x;
}
Cube MR(Cube x)
{
    swap(x.a[4],x.a[65]);
    swap(x.a[65],x.a[25]);
    swap(x.a[8],x.a[66]);
    swap(x.a[66],x.a[24]);
    swap(x.a[7],x.a[67]);
    swap(x.a[67],x.a[20]);
    swap(x.a[43],x.a[56]);
    swap(x.a[56],x.a[13]);
    swap(x.a[44],x.a[60]);
    swap(x.a[60],x.a[12]);
    swap(x.a[40],x.a[61]);
    swap(x.a[61],x.a[11]);
    return x;
}
Cube F(Cube x)
{
    swap(x.a[36],x.a[14]);
    swap(x.a[14],x.a[55]);
    swap(x.a[5],x.a[54]);
    swap(x.a[54],x.a[64]);
    swap(x.a[6],x.a[53]);
    swap(x.a[53],x.a[66]);
    swap(x.a[7],x.a[49]);
    swap(x.a[49],x.a[65]);
    swap(x.a[8],x.a[48]);
    swap(x.a[48],x.a[69]);
    swap(x.a[9],x.a[46]);
    swap(x.a[46],x.a[68]);

    swap(x.a[45],x.a[41]);
    swap(x.a[41],x.a[37]);
    swap(x.a[44],x.a[42]);
    swap(x.a[42],x.a[39]);
    swap(x.a[43],x.a[38]);
    swap(x.a[38],x.a[40]);
    return x;
}
Cube B(Cube x)
{
    swap(x.a[1],x.a[50]);
    swap(x.a[50],x.a[72]);
    swap(x.a[10],x.a[63]);
    swap(x.a[63],x.a[32]);
    swap(x.a[12],x.a[62]);
    swap(x.a[62],x.a[33]);
    swap(x.a[13],x.a[61]);
    swap(x.a[61],x.a[29]);
    swap(x.a[17],x.a[60]);
    swap(x.a[60],x.a[30]);
    swap(x.a[18],x.a[59]);
    swap(x.a[59],x.a[28]);

    swap(x.a[19],x.a[23]);
    swap(x.a[23],x.a[27]);
    swap(x.a[21],x.a[24]);
    swap(x.a[24],x.a[26]);
    swap(x.a[20],x.a[25]);
    swap(x.a[25],x.a[22]);
    return x;
}
Cube RB(Cube x)
{
    swap(x.a[1],x.a[54]);
    swap(x.a[54],x.a[23]);
    swap(x.a[3],x.a[53]);
    swap(x.a[53],x.a[24]);
    swap(x.a[4],x.a[52]);
    swap(x.a[52],x.a[20]);
    swap(x.a[8],x.a[51]);
    swap(x.a[51],x.a[21]);
    swap(x.a[9],x.a[50]);
    swap(x.a[50],x.a[19]);
    swap(x.a[41],x.a[63]);
    swap(x.a[63],x.a[28]);

    swap(x.a[10],x.a[14]);
    swap(x.a[14],x.a[18]);
    swap(x.a[12],x.a[15]);
    swap(x.a[15],x.a[17]);
    swap(x.a[11],x.a[16]);
    swap(x.a[16],x.a[13]);
    return x;
}
Cube LB(Cube x)
{
    swap(x.a[1],x.a[27]);
    swap(x.a[27],x.a[68]);
    swap(x.a[3],x.a[26]);
    swap(x.a[26],x.a[69]);
    swap(x.a[2],x.a[22]);
    swap(x.a[22],x.a[70]);
    swap(x.a[6],x.a[21]);
    swap(x.a[21],x.a[71]);
    swap(x.a[5],x.a[19]);
    swap(x.a[19],x.a[72]);
    swap(x.a[45],x.a[10]);
    swap(x.a[10],x.a[59]);

    swap(x.a[36],x.a[28]);
    swap(x.a[28],x.a[32]);
    swap(x.a[35],x.a[30]);
    swap(x.a[30],x.a[33]);
    swap(x.a[31],x.a[29]);
    swap(x.a[29],x.a[34]);
    return x;
}
Cube MU(Cube x)
{
    swap(x.a[40],x.a[16]);
    swap(x.a[16],x.a[29]);
    swap(x.a[39],x.a[17]);
    swap(x.a[17],x.a[33]);
    swap(x.a[38],x.a[13]);
    swap(x.a[13],x.a[34]);
    swap(x.a[49],x.a[20]);
    swap(x.a[20],x.a[70]);
    swap(x.a[53],x.a[21]);
    swap(x.a[21],x.a[69]);
    swap(x.a[52],x.a[22]);
    swap(x.a[22],x.a[65]);
    return x;
}
Cube MF(Cube x)
{
    swap(x.a[2],x.a[52]);
    swap(x.a[52],x.a[67]);
    swap(x.a[3],x.a[51]);
    swap(x.a[51],x.a[71]);
    swap(x.a[4],x.a[47]);
    swap(x.a[47],x.a[70]);
    swap(x.a[11],x.a[58]);
    swap(x.a[58],x.a[34]);
    swap(x.a[15],x.a[57]);
    swap(x.a[57],x.a[35]);
    swap(x.a[16],x.a[56]);
    swap(x.a[56],x.a[31]);
    return x;
}
bool dfs(int dep,Cube now)
{
    if (dep>3) return false;
    if (now.solved()) return true;
    if (dep==3) return false;
    #define re(x) if (dfs(dep+1,x)) return true
    re(R(now));re(R(R(now)));
    re(L(now));re(L(L(now)));
    re(U(now));re(U(U(now)));
    re(D(now));re(D(D(now)));
    re(ML(now));re(ML(ML(now)));
    re(MR(now));re(MR(MR(now)));
    re(F(now));re(F(F(now)));
    re(B(now));re(B(B(now)));
    re(RB(now));re(RB(RB(now)));
    re(LB(now));re(LB(LB(now)));
    re(MU(now));re(MU(MU(now)));
    re(MF(now));re(MF(MF(now)));
    return false;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        Cube now;
        for (int i=1;i<=72;i++) {
            scanf("%d",&now.a[i]);
        }
        puts(dfs(0,now)?"YES":"NO");
    }
    return 0;
}
