#include <cstdio>
using namespace std;

int main()
{
    int a,b,c,d;
    while (scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF) {
        printf("%d\n",a+b+c*c+d);
    }
    return 0;
}
