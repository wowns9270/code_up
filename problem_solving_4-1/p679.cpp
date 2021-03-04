#include<bits/stdc++.h>
using namespace std;


ifstream in("p679.inp");
ofstream out("p679.out");

bool arr[1100000];
int n,a, b;
int lotation() {

	int boal = 1;

	while (boal < (1 << (a - 1))) {


		if (arr[boal] == false) {
			arr[boal] = true;
			boal = boal * 2;
		}
		else {
			arr[boal] = false;
			boal = boal * 2 + 1;
		
		}
	}

	return boal;

}

int main() {
	in >> n;
	while (n--) {

		 in >> a >> b;

		memset(arr, false, sizeof(arr));

		int k = -1;
		for (int i = 0; i < b; i++) {

			k = lotation();
		}
		out << k <<"\n";
	}
	in >> n;
	return 0;
}