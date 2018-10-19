//向下调整
void siftdown(int i)
{
	int t, flag = 0;
	while (i * 2 <= n && flag == 0) {
		if (h[i] > h[i * 2]) 
			t = i * 2;
		else 
			t = i;
		if (i * 2 + 1 <= n) {
			if (h[t] > h[i * 2 + 1])
				t = i * 2 + 1;
		}
		if (t != i) {
			swap(t, i);
			i = t;
		} else {
			flag = 1;
		}
	}
} 

//向上调整
void siftup(int i)
{
	int flag = 0;
	if (i == 1) return;
	while (i != 1 && flag == 0) {
		if (h[i] < h[i / 2])
			swap(i, i / 2);
		else
			flag = 1;
	}
	return;
} 

//向堆中插入元素(建堆)
n = 0; 
for (int i = 1; i <= m; i++) {
	n++;
	h[n] = h[i];
	siftup(n);
}

//建堆 
for (int i = n / 2; i >= 1; i--) 
	siftdown(i);













 


