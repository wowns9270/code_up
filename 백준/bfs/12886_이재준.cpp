#include<iostream>
#include<queue>
using namespace std;

int sum;
//2�����迭�� �������� 3���������ϸ� �����Ӵ���
//2���� ���� �˸� �ϳ��� ���� �ڵ������� �� �� �ֱ� �����̴�.
bool arr[1501][1501];

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	arr[a][b] = true;

	//����츦 �� �ѷ����鼭 ���� �� �ִ� ��츦 ã�´�.
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
//BFS��� �����ϱ� �������.
int main() {
	int a, b, c; cin >> a >> b >> c;
	sum = a + b + c;
	//3���� ������ �������� ������ �ϴ� �Ұ����ϴ�.
	if (sum % 3 != 0) {
		cout << "0";
		return 0;
	}
	//BFS ����
	bfs(a, b);

	//�Ȱ��� ���� �迭�� �湮 �Ǿ����� 1
	if (arr[sum / 3][sum / 3] == true) cout << "1";
	else cout << "0";


}