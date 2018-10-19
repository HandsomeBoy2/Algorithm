#include <iostream>
#include <map> 
using namespace std;
struct stu{
	int id;
	int C;
	int M; 
	int E;
	int A;
};
void sort(struct a) {
	
}
int main() {
	int N, M, sum = 0;
	cin >> N >> M;
	struct stu stu[N];
	map <int, char> p;
	int id[M];
	for (int i = 0; i < N; i++) {
		sum = 0;
		cin >> stu[i].id >> stu[i].C >> stu[i].M >> stu[i].E;
		sum = stu[i].C + stu[i].M + stu[i].E;
		stu[i].A = sum / 3;
		sort(struct stu[i]);
	}
	for (int i = 0; i < M; i++) {
		cin >> id[i];
	}
	
 	return 0;
}

