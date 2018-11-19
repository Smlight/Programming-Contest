#include <bits/stdc++.h>
using namespace std;

map<string,int> intrk;
string str[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
vector<int> on_table;
int lex_ord[13];

void init()
{
    for (int i=0;i<13;i++) {
        intrk[str[i]]=i;
    }
    int t=0;
    for (auto &p:intrk) {
        lex_ord[t++]=p.second;
    }
}

char t[128];
int cnt[4][16];
bool mygets(int p)
{
    memset(cnt[p],0,sizeof(cnt[p]));
    if (scanf("%s",t)==EOF) return false;
    cnt[p][intrk[t]]++;
    for (int i=1;i<13;i++) {
        scanf("%s",t);
        cnt[p][intrk[t]]++;
    }
    return true;
}

void check_out(int p)
{
    printf("============IN %d's Hand============\n",p);
    for (int i=0;i<13;i++) {
        printf("%d ",cnt[p][i]);
    }
    printf("\n============IN %d's Hand============\n",p);
}

pair<int,bool> put_down(int p,int r)
{
    int t=cnt[p][r];
    switch (p) {
        case 0:
            if (cnt[p][r]) {
                on_table.push_back(r);
                --cnt[p][r];
                return make_pair(1,true);
            } else {
                for (int i=0;i<13;i++) {
                    if (cnt[p][lex_ord[i]]) {
                        --cnt[p][lex_ord[i]];
                        on_table.push_back(lex_ord[i]);
                        break;
                    }
                }
                return make_pair(1,false);
            }
        case 1:
            if (cnt[p][r]) {
                cnt[p][r]=0;
                for (int i=0;i<t;i++) {
                    on_table.push_back(r);
                }
                return make_pair(t,true);
            } else {
                for (int i=0;i<13;i++) {
                    if (cnt[p][lex_ord[i]]) {
                        --cnt[p][lex_ord[i]];
                        on_table.push_back(lex_ord[i]);
                        break;
                    }
                }
                return make_pair(1,false);
            }
        case 2:
            if (cnt[p][r]) {
                cnt[p][r]=0;
                for (int i=0;i<t;i++) {
                    on_table.push_back(r);
                }
                return make_pair(t,true);
            } else {
                int mn=20;
                for (int i=0;i<13;i++) {
                    if (cnt[p][lex_ord[i]] && cnt[p][lex_ord[i]]<mn) {
                        mn=cnt[p][lex_ord[i]];
                    }
                }
                for (int i=0;i<13;i++) {
                    if (cnt[p][lex_ord[i]]==mn) {
                        cnt[p][lex_ord[i]]=0;
                        for (int j=0;j<mn;j++) {
                            on_table.push_back(lex_ord[i]);
                        }
                        return make_pair(mn,false);
                    }
                }
            }
        case 3:
            cnt[p][r]=0;
            for (int i=0;i<t;i++) {
                on_table.push_back(r);
            }
            int sum = accumulate(cnt[p],cnt[p]+13,0);
            if (t>=3 || sum==0) return make_pair(t,true);
            for (int i=0;i<13;i++) {
                if (cnt[p][lex_ord[i]]) {
                    --cnt[p][lex_ord[i]];
                    on_table.push_back(lex_ord[i]);
                    return make_pair(t+1,false);
                }
            }
    }
    assert(false);
}

bool challenge(int p,int r,int c,int q)
{
    switch (q) {
        case 0:
            if (p==3&&cnt[q][(r+1)%13]==0) return true;
            return (c+cnt[0][r]>4);
        case 1:
            return (p==0&&cnt[q][(r+1)%13]==0);
        case 2:
            return (cnt[q][r]==4);
        case 3:
            return (accumulate(cnt[p],cnt[p]+13,0)==0);
    }
    assert(false);
}

int main()
{
    init();
    while (mygets(0)) {
        for (int i=1;i<4;i++) {
            mygets(i);
        }
        int nowp=-1,nowr=-1;
        on_table.clear();
        while (true) {
            nowp=(nowp+1)%4;
            nowr=(nowr+1)%13;
            auto p=put_down(nowp,nowr);
            int pcc=p.first,stat=p.second;
//            check_out(nowp);
            for (int i=1;i<4;i++) {
                int q=(nowp+i)%4;
                if (challenge(nowp,nowr,pcc,q)) {
                    int y=stat?q:nowp;
                    for (auto x:on_table) {
                        ++cnt[y][x];
                    }
                    on_table.clear();
                }
            }
//            for (int i=0;i<4;i++) check_out(i);
            if (accumulate(cnt[nowp],cnt[nowp]+13,0)==0) break;
        }
        for (int i=0;i<4;i++) {
            vector<int> res;
            for (int j=0;j<13;j++) {
                assert(0<=cnt[i][j]&&cnt[i][j]<=4);
                for (int k=0;k<cnt[i][j];k++) {
                    res.push_back(j);
                }
            }
            if (res.size()==0) {
                puts("WINNER");
            } else {
                int sz=res.size();
                for (int i=0;i<sz;i++) {
                    printf("%s ",str[res[i]].c_str());
                }
                puts("");
            }
        }
    }
    return 0;
}
