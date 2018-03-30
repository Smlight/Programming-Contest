#include <bits/stdc++.h>
using namespace std;

set< vector<int> > allst;
int roll[3][3][4]={
	{
		{2,6,10,14},
		{22,21,23,24},
		{4,8,12,16}
	},
	{
		{1,2,4,3},
		{18,15,22,6},
		{17,16,21,5}
	},
	{
		{5,6,8,7},
		{3,21,10,20},
		{4,23,9,18}
	}
};
int a[40],c[40];

bool have()
{
	vector<int> v;
	for (int i=1;i<=24;i++) {
		v.push_back(a[i]);
	}
	if (allst.find(v)!=allst.end()) return true;
	allst.insert(v);
	return false;
}

int tot=0; 
void print(int a[])
{
	if (++tot!=100) return;
	for (int i=1;i<=24;i++) {
		printf("%d ",a[i]);
	}
	puts("");
//	system("pause");
}

int main()
{
	vector<int> v(24,2);
	for (int i=5-1;i<=12-1;i++) v[i]=1;
	for (int i=17-1;i<=24-1;i++) v[i]=3;
	queue< vector<int> > Q;
	if (allst.find(v)==allst.end()) {
		Q.push(v);
		allst.insert(v);
	}
	while (!Q.empty()) {
		vector<int> v(Q.front());
		Q.pop();
		for (int i=0;i<3;i++) {
			for (int j=0;j<3;j++) {
				for (int k=0;k<4;k++) {
					c[roll[i][j][k]-1]=v[roll[i][j][(k+1)%4]-1];
				}
				for (int k=0;k<4;k++) {
					v[roll[i][j][k]-1]=c[roll[i][j][k]-1];
				}
			}
			if (allst.find(v)==allst.end()) {
				Q.push(v);
				allst.insert(v);
			}
		}
//		printf("%d\n",allst.size());
	}
	printf("%d\n",allst.size());
	return 0;
}
