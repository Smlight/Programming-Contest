#include <bits/stdc++.h>
using namespace std;

char a[5][5];

int C(int x, int y) {
    int x1 = a[x][y], x2 = a[x][y + 1], x3 = a[x + 1][y], x4 = a[x + 1][y + 1];
    a[x][y + 1] = x1;
    a[x + 1][y + 1] = x2;
    a[x][y] = x3;
    a[x + 1][y] = x4;
}

int R(int x, int y) {
    int x1 = a[x][y], x2 = a[x][y + 1], x3 = a[x + 1][y], x4 = a[x + 1][y + 1];
    a[x + 1][y] =  x1;
    a[x][y] = x2;
    a[x + 1][y + 1] = x3;
    a[x][y + 1] = x4;
}

int px[] = {0, 0, 0, 1, 1};
int py[] = {0, 0, 1, 0, 1};

void show() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            printf("%c", a[i][j]);
        }
        puts("");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int q;
        scanf("%d", &q);
        for(int i = 0; i < 3; ++i) {
            scanf("%s", a[i]);
        }
//        show();
        char cmd[4];
        while(q--) {
            scanf("%s", cmd);
            int idx = cmd[0] - '0';
            if(cmd[1] == 'R') R(px[idx], py[idx]);
            else C(px[idx], py[idx]);
//            show();
        }

        show();

    }
    return 0;
}