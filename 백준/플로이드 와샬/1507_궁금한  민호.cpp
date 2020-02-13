//양방향 그래프
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int n, arr[21][21];

int main() {
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	} //간선정보를 받는다.


	sum /= 2; //양방향이니까 2로 나눠주면 모든 가중치 합이고

	set<pair<int, int>> sell;
	for (int k = 1; k <= n; k++) {

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (i != k && k != j && arr[i][j] == (arr[i][k] + arr[k][j])) {
					if (sell.count({ i,j }) == 0 && sell.count({ j,i }) == 0) {
						sell.insert({ i,j });
					}
				}

				if (i != k && k != j && arr[i][j] > arr[i][k] + arr[k][j]) {
					cout << -1;
					return 0;
				}


			}
		}
	}
	int n_sum = 0;
	for (auto it = sell.begin(); it != sell.end(); it++) {
		n_sum += arr[it->first][it->second];
	}
	cout << sum - n_sum;
	return 0;
}