#include<bits/stdc++.h>
using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 }; //북동남서

int n, m, x, y, dir, sum;
int arr[51][51];
bool visit[51][51];

int main() {
	cin >> n >> m >> x >> y >> dir;
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++)
			cin >> arr[i][j]; 
	}
	while (1) {
		if (visit[x][y] == false) { //후진할때 또 더하는것을 방지
			visit[x][y] = true;sum += 1;
		}
	int k = 0; // 청소 할 뱡향이 있었는지 판단
	for(int i= 0 ; i<4; i++){
		int idx = (dir + 3-i) % 4; //왼쪽부터 북이면 서 남 동 3 2 1 순으로 판단
	if (visit[x+dx[idx]][y+dy[idx]] == false && arr[x + dx[idx]][y + dy[idx]]==0) {
		visit[x + dx[idx]][y + dy[idx]] = true;
		sum += 1; //청소 했으면 +1
		x = x + dx[idx]; y = y + dy[idx]; //좌표를 옮겨주고
		dir = idx; //방향은 그방향으로
		k++; // 청소를 했으니까
		break;
	}
	}
	if (k == 0) { // 4방향 다 청소를 안했으면
		x = x - dx[dir];
		y = y - dy[dir]; // 후진
		if (arr[x][y] == 1) break; //후진했는데 벽이라면 종료
	}
	}
	cout << sum;
	return 0;

}