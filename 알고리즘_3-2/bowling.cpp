#include<bits/stdc++.h>
using namespace std;

ifstream in("bowling.inp");
ofstream out("bowling.out");

int arr[11];
int st[11];
int sp[11];

int main() {
	int test; in >> test;


	while (test--) {

		memset(arr, 0, sizeof(arr));
		memset(st, 0, sizeof(st));
		memset(sp, 0, sizeof(sp));


		for (int i = 1; i <= 10; i++) {
			int a; in >> a;

			if (st[i - 1] == 1) {//스트일때
				if (st[i - 2] == 1) {
					arr[i - 2] += a;
					arr[i - 1] += a;
				}
				else {
					arr[i - 1] += a;
				}
			}
			//스페어일때
			if (sp[i - 1] == 1) {
				arr[i - 1] += a;
			}
			if (a == 10) {
				st[i] = 1;
				arr[i] += a;
			}
			else {
				int b; in >> b;

				if (st[i - 1] == 1) {//스트일때
						arr[i - 1] += b;
				}
				if (a + b == 10) {
					sp[i] = 1;
					arr[i] += (a + b);
				}
				else {
					arr[i] += (a + b);
				}

			}
		}

		if (st[10] == 1) {
			int b,c; in >> b >> c;

			if (st[9] == 1) {
				arr[9] += b;
			}
			arr[10] += b;
			arr[10] += c;
		}
		else {
			if (sp[10] == 1) {
				int c; in >> c;
				arr[10] += c;
			}
		}
		int ret = 0;
		for (int i = 1; i <= 10; i++) {
			ret += arr[i];
		}
		out << ret <<"\n";
	}
	return 0;
}
