#include <stdio.h>
#define INF 999999
int dis[7], book[7] = {0};//book����������¼��Щ�����Ѿ������������� 
int h[7], pos[7], size; //h��������ѣ�pos�����洢ÿ�������ڶ��е�λ�ã�sizeΪ�ѵĴ�С 

void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	
	//ͬ������pos
	t = pos[h[x]];
	pos[h[x]] = pos[h[y]];
	pos[h[y]] = t;
}

void siftdown(int i)
{
	int t, flag = 0; 
	while (i * 2 <= size && flag == 0) {
		if (dis[h[i]] > dis[h[i * 2]])
			t = i * 2;
		else 
		 	t = i;
		if (i * 2 + 1 <= size) {
			if (dis[h[t]] > dis[h[i * 2 + 1]])
				t = i * 2 + 1;
		}
		if (t != i) {
			swap(t, i);
			i = t;
		} else {
			flag = 1;			
		}
	}
	return;
}

void siftup(int i)
{
	int flag = 0;
	if (i == 0) return;
	while (i != 1 && flag == 0) {
		if (dis[h[i]] < dis[h[i / 2]])
			swap(i, i / 2);
		else
			flag = 1;
		i = i / 2;
	} 
	return;
}

int pop()
{
	int t;
	t = h[1];
	h[1] = h[size];
	pos[h[1]] = 1;
	size--;
	siftdown(1);
	return t;
} 
 
int main()
{
	int i, j, k, m, n;
	int u[19], v[19], w[19], first[17], next[19];
	int count = 0, sum = 0;
	//����m��n 
	scanf("%d %d", &m, &n);
	//�����
	for (i = 1; i <= n; i++) 
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	//����������ͼ��������Ҫ�����еı��ٷ���洢һ��
	for (i = n + 1; i<= 2 * n; i++) {
		u[i] = v[i - n];
		v[i] = u[i - n];
		w[i] = w[i - n];
	}
	//��ʼʹ���ڽӱ�洢�� 
	for (i = 1; i <= m; i++) first[i] = -1; 
	
	for (i = 1; i <= 2 * n; i++) {
		next[i] = first[u[i]];
		first[u[i]] = i;
	}
	//Prim���Ĳ��ֿ�ʼ
	//��1�Ŷ������������
	book[1] = 1;
	count++;
	
	//��ʼ��dis���飬������1�Ŷ��㵽�����������ĳ�ʼ����
	dis[1] = 0; 
	for (i = 2; i <= m; i++) dis[i] = INF;
	k = first[1];
	while (k != -1) {
		dis[v[k]] = w[k];
		k = next[k];
	}
	//��ʼ���� 
	size = m; 
	for (i = 1; i <= size; i++) {
		h[i] = i;
		pos[i] = i;
	}
	for (i = size / 2; i >= 1; i--) 
		siftdown(i);
	pop(); //�ȵ���һ���Ѷ�Ԫ�� 
	
	while (count < m) {
		j = pop();
		book[j] = 1; count++; sum+= dis[j]; 
		
		//ɨ�赱ǰ����j���еıߣ�����jΪ�м��㣬�����ɳ� 
		k = first[j];
		while (k != -1) {
			if (book[v[k]] == 0 && dis[v[k]] > w[k]) {
				dis[v[k]] = w[k];
				siftup(pos[v[k]]);
 			} 
 			k = next[k]; 
		}	
	}
	
	printf("%d", sum);
	
	getchar();getchar();
	return 0;
}

