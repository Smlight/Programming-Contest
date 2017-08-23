#include <bits/stdc++.h>
using namespace std;

const char sp[]="(q*|w*|e*|r*|t*|y*|u*|i*|o*|p*|a*|s*|d*|f*|g*|h*|j*|k*|l*|z*|x*|c*|v*|b*|n*|m*)";

int main() {
    int T;
    scanf("%d", &T);
    scanf("\n");
    while(T--) {
        string a, b, c;
        getline(cin,a);
        getline(cin,b);
        for (int i=0;i<b.length();i++) {
            if (i<b.length()-1&&b[i]=='.'&&b[i+1]=='*') {
                c+=sp;i++;
            } else {
                c+=b[i];
            }
        }
        auto re = regex(c);
        if(regex_match(a, re)) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    return 0;
}
