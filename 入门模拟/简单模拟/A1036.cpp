#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
struct stu{
	string name;
	char gender;
	string ID;
	int grade;
};
int main(){
	int N;
	cin >> N;
	struct stu stu;
	struct stu mStuMin = {"", 'a', "", 101};
	struct stu fStuMax = {"", 'a', "", -1};
	for(int i = 0; i < N; i++){
		cin >> stu.name >> stu.gender >> stu.ID >> stu.grade;
		if(stu.gender == 'M'){
			if(stu.grade < mStuMin.grade) {
				mStuMin = stu;
			}
		}else{
			if(stu.grade >= fStuMax.grade) {
				fStuMax = stu;
			}
		}
	}
	
	if(fStuMax.grade != -1){
		cout << fStuMax.name << " " << fStuMax.ID << endl;
	} else{
		cout << "Absent" << endl;
	}
	if(mStuMin.grade != 101){
		cout << mStuMin.name << " " << mStuMin.ID << endl;
	} else{
		cout << "Absent" << endl;
	}
	if(fStuMax.grade == -1 || mStuMin.grade == 101){
		cout << "NA" << endl;
	} else {
		cout << fStuMax.grade - mStuMin.grade;
	}
	
	return 0;
}

