#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map> 
using namespace std;
const int maxn = 100;
const int maxm = 200;
int head[maxn];  //存储起点为vi的第一条边的位置 
struct NODE 
{
	int from; 	 //起点 
	int to; 	//终点 
	int w; 		//权值 
};
NODE edge[maxm]; 
bool cmp (NODE a, NODE b)
{
	if (a.from == b.from && a.to == b.to) return a.w < b.w;
	if (a.from == b.from) return a.to < b.to;
	return a.from < b.from;
}
int main()
{
	int n, m; 
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> edge[i].from >> edge[i].to >> edge[i].w;
	sort(edge, edge + m, cmp);
	memset(head, -1, sizeof(head));
	head[edge[0].from] = 0;
	for (int i = 1; i < m; i++)
		if (edge[i].from != edge[i-1].from) [edge[i].from] = i;
	for (int i = 1; i <= n; i++) {
		for (int k = head[i]; edge[k].from == i && k < m; k++) {
			cout << edge[k].from << " " << edge[k].to << " " << edge[k].w << endl; 
		}
	}
	return 0;
}


