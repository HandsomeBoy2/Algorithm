#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
   int n, m, sum, k;
   float average = 0.0f;
   cin >> n >> m;
   vector<int> a(n);
   int *b = new int[n];
   for (int i = 0; i < n; i++) {
     sum = 0;
     k = 0;
     for (int j = 0; j < n; j++) {
       cin >> a[j];
     }
     for (int j = 1; j < n; j++) {
       if (a[j] <= m && a[j] >= 0) {
         b[k++] = a[j];
       }
     }
     sort(b, b+k);
     for (int j = 1; j < k - 1; j++) {
       sum += b[j];
     }
     average = sum / (k-1-1);
     printf("%.0f\n" ,(average + a[0] + 0.5) / 2);
   }

    return 0;
}

