#include<bits/stdc++.h>
using namespace std;


ifstream in("rectangle.inp");
ofstream out("rectangle.out");

int gcd(int a, int b) {

	if (b == 0) return a;
	return gcd(b, a % b);
}

vector<int> arr;
vector<int> ret;
int main() {

	for (int i = 2; i < 100; i++) { // m

		for (int j = 1; j < i; j++) { //n

			if ((i + j) % 2 == 0) continue;


			if (gcd(i, j) == 1) {

				int x = 2 * i * j;
				int y = i * i - j * j;

				int r = 2 * (x + y);
				arr.push_back(r);
			}
		}
	}

	sort(arr.begin(), arr.end());


	ret.push_back(arr[0]);

	for (int i = 1; i < arr.size(); i++) {

		if (ret[i - 1] + arr[i] >= 2000000) break;
		ret.push_back(ret[i - 1] + arr[i]);
	}

	int n; in >> n;

	while (n--) {

		int a; in >> a;

		for (int i = 0; i < ret.size(); i++) {
			if (a > ret[i]) {
				continue;
			}
			else if (a == ret[i]) {
				out << i + 1 << "\n";
				break;
			}
			else {
				out << i  << "\n";
				break;
			}
		}



	}





}