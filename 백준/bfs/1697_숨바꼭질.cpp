#include<bits/stdc++.h>	
using namespace std;
int arr[100011];
int a, b;
void bfs(int x) {
	arr[x] = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int nx = q.front();
		q.pop();
		int ux1 = nx - 1;
		int ux2 = nx + 1;
		int ux3 = nx * 2;
		if (ux1 >= 0 && ux1 <= 100000 && arr[ux1] == -1) {
			arr[ux1] = arr[nx] + 1;
			q.push(ux1);
		}
		if (ux2 >= 0 && ux2 <= 100000 && arr[ux2] == -1) {
			arr[ux2] = arr[nx] + 1;
			q.push(ux2);
		}
		if (ux3 >= 0 && ux3 <= 100000 && arr[ux3] == -1) {
			arr[ux3] = arr[nx] + 1;
			q.push(ux3);
		}
	}
}
int main() {
	cin >> a >> b;
	memset(arr, -1, sizeof(arr));
	bfs(a);
	cout << arr[b];
	return 0;
}