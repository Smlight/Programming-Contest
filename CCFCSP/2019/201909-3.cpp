#include <bits/stdc++.h>
using namespace std;

struct RGB {
    int R,G,B;
    RGB operator+(const RGB &rhs) const {
        return {R+rhs.R,G+rhs.G,B+rhs.B};
    }
    RGB operator/(const int &rhs) const {
        return {R/rhs, G/rhs, B/rhs};
    }
    bool operator==(const RGB &rhs) const {
        return R==rhs.R && G==rhs.G && B==rhs.B;
    }
};

RGB get_one()
{
    char s[9]={0};
    scanf("%s",s);
    int len=strlen(s);
    if (len==2) {
        for (int i=6;i>1;i--) {
            s[i]=s[1];
        }
    } else if (len==4) {
        s[6]=s[5]=s[3];
        s[4]=s[3]=s[2];
        s[2]=s[1];
    }
    RGB res({0,0,0});
    sscanf(s+1,"%2x",&res.R);
    sscanf(s+3,"%2x",&res.G);
    sscanf(s+5,"%2x",&res.B);
    return res;
}

void set_color(RGB color)
{
    printf("\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B");
    char s[9];
    sprintf(s,"%d",color.R);
    for (int i=0;s[i];i++) {
        printf("\\x%02X",s[i]);
    }
    printf("\\x3B");
    sprintf(s,"%d",color.G);
    for (int i=0;s[i];i++) {
        printf("\\x%02X",s[i]);
    }
    printf("\\x3B");
    sprintf(s,"%d",color.B);
    for (int i=0;s[i];i++) {
        printf("\\x%02X",s[i]);
    }
    printf("\\x6D");
}

void reset_color()
{
    printf("\\x1B\\x5B\\x30\\x6D");
}

void print_space()
{
    printf("\\x20");
}

void print_line()
{
    printf("\\x0A");
}

RGB origin_photo[1080][1920];

int main()
{
    int n,m,p,q;
    scanf("%d%d%d%d",&m,&n,&p,&q);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            origin_photo[i][j] = get_one();
        }
    }
    RGB normal({0,0,0});
    for (int i=0;i<n;i+=q) {
        RGB pre({0,0,0});
        for (int j=0;j<m;j+=p) {
            RGB avg({0,0,0});
            for (int x=0;x<q;x++) {
                for (int y=0;y<p;y++) {
                    avg = avg + origin_photo[i+x][j+y];
                }
            }
            avg = avg / (p*q);
            if (avg == pre) {
                print_space();
            } else if (avg == normal) {
                reset_color();
                print_space();
                pre = avg;
            } else {
                set_color(avg);
                print_space();
                pre = avg;
            }
        }
        if (pre == normal) {
            print_line();
        } else {
            reset_color();
            print_line();
        }
    }
    puts("");
    return 0;
}
