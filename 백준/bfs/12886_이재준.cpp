#include<iostream>
#include<queue>
using namespace std;

int sum;
//2차원배열로 한이유는 3차원으로하면 터질뿐더러
//2개의 돌을 알면 하나의 값은 자동적으로 알 수 있기 때문이다.
bool arr[1501][1501];

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	arr[a][b] = true;

	//모든경우를 다 둘러보면서 만들 수 있는 경우를 찾는다.
	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		int c = sum - a - b;
		q.pop();
		if (a != b) {
			if (a > b) {
				int n_a = a - b;
				int n_b = b + b;

				if (arr[n_a][n_b] == false) {
					arr[n_a][n_b] = true;
					q.push(make_pair(n_a, n_b));
				}
			}
			else {
				int n_a = a + a;
				int n_b = b - a;

				if (arr[n_a][n_b] == false) {
					arr[n_a][n_b] = true;
					q.push(make_pair(n_a, n_b));
				}
			}
		}
		if (b != c) {
			if (b > c) {
				int n_c = c + c;
				int n_b = b - c;
				if (arr[a][n_b] == false) {
					arr[a][n_b] = true;
					q.push(make_pair(a, n_b));
				}
			}
			else {
				int n_c = c - b;
				int n_b = b + b;
				if (arr[a][n_b] == false) {
					arr[a][n_b] = true;
					q.push(make_pair(a, n_b));
				}
			}
		}
		if (a > c) {
			int n_a = a - c;
			int n_c = c + c;

			if (arr[n_a][b] == false) {
				arr[n_a][b] = true;
				q.push(make_pair(n_a, b));
			}
		}
		else {
			int n_c = c - a;
			int n_a = a + a;

			if (arr[n_a][b] == false) {
				arr[n_a][b] = true;
				q.push(make_pair(n_a, b));
			}
		}
	}
}
//BFS라고 생각하기 힘들었다.
int main() {
	int a, b, c; cin >> a >> b >> c;
	sum = a + b + c;
	//3개로 나누어 떨어지지 않으면 일단 불가능하다.
	if (sum % 3 != 0) {
		cout << "0";
		return 0;
	}
	//BFS 시작
	bfs(a, b);

	//똑같이 나눈 배열이 방문 되었으면 1
	if (arr[sum / 3][sum / 3] == true) cout << "1";
	else cout << "0";


}