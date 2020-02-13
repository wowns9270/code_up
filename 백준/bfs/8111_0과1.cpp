 //0과 1로만 이루어져있어야한다
//1이 적어도 하나는 있어야하고
//수의길이는 100이하
// 수가 0으로 시작하지않는다
//n의 배수중에서 좋아하는수
#include<bits/stdc++.h>
using namespace std;


bool check[20001];
int from[20001];
int how[20001];

int main() {
	int test; cin >> test;
	while (test--) {
		memset(check, false, sizeof(check));
		memset(from, -1, sizeof(from));
		memset(how, -1, sizeof(how));
		int n; cin >> n;

		from[1 % n] = -1;
		how[1] = 1;
		check[1] = true;

		queue<int> q;
		q.push(1);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i <= 1; i++) {
				int ux = (x * 10 + i) % n;

				if (check[ux] == false) {
					check[ux] = true;
					from[ux] = x;
					how[ux] = i;
					q.push(ux);
				}
			}
		}
		if (check[0] == false) {
			cout << "BRAK\n";
		}
		else {
			string a;

			int k = how[0];
			a += to_string(k);
			int kk = from[0]; // 어디서왔냐

			while (1) {
				k = how[kk];
				a += to_string(k);

				kk = from[kk];
				if (kk == -1) break;
			}
			reverse(a.begin(), a.end());
			cout << a<<"\n";
		}
	}
	return 0;
}