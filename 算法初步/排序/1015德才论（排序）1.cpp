#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct stu {
    int numb;
    int de;
    int cai;
    int leve;
};
int comp(stu x,stu y)
{
    if(x.leve > y.leve)  
		return 1;
    else 
	{
		if(x.leve == y.leve)  
		{
			if(x.cai + x.de > y.cai + y.de)   
			return 1;
		else
			{
				if(x.cai + x.de == y.cai + y.de)
				{
					if(x.de > y.de ) 
						return 1;
					else
					{
						if(x.de == y.de )
							{
								if( x.numb < y.numb )
									return 1;
								else
									return 0;
							}
						else
							return 0;
					}
				}
					else return 0;
			}
		}
		else
			return 0;
	}
}
int main() {
    stu a[100000];
    stu a1[100], a2[100], a3[100], a4[100],t;
    int count = 0;
     
    int N,L,H,i,j;
    cin >> N >> L >> H;
    for(i=0; i<N; i++) {
        cin >> a[i].numb >> a[i].de >> a[i].cai;
        if ( a[i].de >= L  &&  a[i].cai >= L) {
            count++;
            if( a[i].de >= H  &&  a[i].cai >=H )
                a[i].leve = 4;
            else if( a[i].de >= H  &&  a[i].cai < H )
                a[i].leve = 3;
            else if( a[i].de < H  &&  a[i].cai <H && a[i].de >=a[i].cai  )
                a[i].leve  = 2;
            else
                a[i].leve = 1;
        }
        else
        	a[i].leve = 0;
    }
  sort(a,a+i,comp);
    cout << count << "\n";
    for(i = 0; i < count; i++) {
        cout <<  a[i].numb << " " << a[i].de << " " << a[i].cai << "\n";
    }  
}

