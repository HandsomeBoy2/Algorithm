#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int Galleon = 0, Sickle = 0, Knut = 0;
	int Galleon1 = 0, Sickle1 = 0, Knut1 = 0;
	scanf("%d.%d.%d", &Galleon, &Sickle, &Knut);
	scanf("%d.%d.%d", &Galleon1, &Sickle1, &Knut1);	
	if (Galleon1 >= Galleon) {
		int t1 = Galleon1 - Galleon;
		int t2 = Sickle1 - Sickle;
		int t3 = Knut1 - Knut;
		    if (t2 >= 0) {
		    	t2 = Sickle1 - Sickle;
			} else {
				t1 = t1 -1;
				t2 = Sickle1 + 17 - Sickle;
		    }
			if (t3 >= 0) {
				t3 = Knut1 - Knut;
			} else {
				t2 = t2 -1;
				t3 = Knut1 + 19 - Knut;
			}
			cout << t1 << "." << t2 << "." << t3;
		} else {
			int t1 = Galleon - Galleon1;
			int t2 = Sickle - Sickle1;
			int t3 = Knut - Knut1;
			if (t2 >= 0) {
		    	t2 = Sickle - Sickle1;
			} else {
				t1 = t1 -1;
				t2 = Sickle + 17 - Sickle1;
		    }
			if (t3 >= 0) {
				t3 = Knut - Knut1;
			} else {
				t2 = t2 -1;
				t3 = Knut + 19 - Knut1;
			}
			cout << "-" << t1 << "." << t2 << "." << t3;			
	}
	return 0;
}

