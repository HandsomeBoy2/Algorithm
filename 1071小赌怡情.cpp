#include <iostream> 
using namespace std;

int main ()
{
  int T, K, n1, b, t, n2;
  cin >> T >> K;
  for (int i = 0; i < K; i++) {
    cin >> n1 >> b >> t >> n2;
    if (t > T) {
      if (T != 0){
        cout << "Not enough tokens.  Total = " << T << "." << endl;
      } else {
        cout << "Game Over." << endl;
        break;
      }  
    } else {
      if (n2 > n1 && b == 1 || n2 < n1 && b == 0) {
        T += t; 
        cout << "Win " << t << "!  Total = " << T << "." << endl;
        continue;
      } else if (n2 > n1 && b == 0 || n2 < n1 && b == 1){
        if (i >= 1 && T == 0) {
          cout << "Game Over." << endl;
          break;
        }
        if (T >= t) {
          T -= t;
          cout << "Lose " << t  << "." << "  Total = " << T << "." << endl;
        }  
      }
    }
  }
  return 0;
}
