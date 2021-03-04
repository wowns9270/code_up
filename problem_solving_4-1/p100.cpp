#include<bits/stdc++.h>
using namespace std;


ifstream in("p100.inp");
ofstream out("p100.out");

int a, b;

int main() {

	
	while (in >> a) {
		in >> b;

		out << a <<" " <<  b <<" ";

		if (b < a) swap(a, b);

		int ret = 0;
		for (int i = a; i <= b; i++) {

			int cnt = 1;
			int k = i;

			while (k != 1) {

				if (k % 2 == 0) {
					k /= 2;
				}
				else {
					k = k * 3 + 1;
				}
				cnt++;
			}
			
			ret = max(ret, cnt);
		}
		out << ret << "\n";
	}
	
	return 0;
}