#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stu1
{
	int num;
	int de;
	int cai;
};
int cmp (struct stu1 node1, struct stu1 node2) 
{
	if (node1.de + node1.cai != node2.de + node2.cai ) 
		return (node1.de + node1.cai) > (node2.de + node2.cai);
	else if (node1.de != node2.de)
		return node1.de > node2.de;
	else 
		return node1.num < node2.num;
}
int main()
{
	int N, L, H;  //N为考生总数 L录取最低分数线 H为优先录取线
	cin >> N >> L >> H;
	int cnt = N;
	vector <stu1> a[4];
	stu1 stu;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &stu.num, &stu.de, &stu.cai);
		if (stu.de < L || stu.cai < L) 
			cnt--;
		else if (stu.de >= H && stu.cai >= H)
			a[0].push_back(stu);
		else if (stu.de >= H && stu.cai < H) 
			a[1].push_back(stu);
		else if (stu.de >= stu.cai && stu.de < H && stu.cai < H) 
			a[2].push_back(stu);
		else 
			a[3].push_back(stu);		
	}
	printf("%d\n", cnt);
	for (int i = 0; i < 4; i++) {
		sort(a[i].begin(), a[i].end(), cmp);
		for (int j = 0; j < a[i].size(); j++) 
		printf("%d %d %d\n", a[i][j].num,	a[i][j].de, a[i][j].cai);
    }
	return 0;
}

