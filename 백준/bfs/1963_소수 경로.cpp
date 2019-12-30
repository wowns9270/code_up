#include<bits/stdc++.h>
using namespace std;

bool prime[10001];
bool visit[10001];
int arr_ret[10001];
int convert(int x, int i, int j) {
	if (i == 0 && j == 0) return -1;

	string k;
	k = to_string(x);
	char c = j + 48;

	k[i] = c;

	return atoi(k.c_str());
}

//갈 수 있는 경로를 모두 보고 후보자중 소수 이면 체크해주고 도착점 까지 가는
//문제
int main() {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	int squrnt = (int)sqrt(10000);
	for (int i = 2; i <= squrnt; i++) {
		if (prime[i]) {

			for (int j = i * i; j <= 10000; j += i) {
				prime[j] = false;
			}
		}
	}
	int n; cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		memset(visit, false, sizeof(visit));
		memset(arr_ret, 0, sizeof(arr_ret));
		queue<int> q;
		q.push(a);
		visit[a] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int candidate = convert(x, i, j);

					if (candidate == -1) continue;


					if (prime[candidate] == true && visit[candidate] == false) {
						q.push(candidate);
						arr_ret[candidate] = arr_ret[x] + 1;
						visit[candidate] = true;
					}
				}
			}
		}
		cout << arr_ret[b] << "\n";
	}
	return 0;
}