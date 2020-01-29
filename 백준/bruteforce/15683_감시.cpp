#include<bits/stdc++.h>
using namespace std;
#define INF 199999999
int arr[9][9];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 }, n, m, ret = INF;
vector<vector<int>> ch = { {},{0},{0,2},{0,1},{0,1,2},{0,1,2,3} };
struct cctv { int x, y, num; }; //좌표랑 cctv종류
vector<cctv> llist;
vector<int> dir;


//이런거 너무 약하다..
// 일단 cctv종류마다 볼수있는 방향을 ch에 저장시켰다.
// 각각의 방향마다 2번은 반대방향 (+2) 3번은 옆에 4번은 옆옆까지 5번은 모두다
// 볼 수 있게 만들었고
// llist에는 각 cctv를 저장했다.
// 재귀를 돌리면서 각 cctv의 방향을 정해주었다.
// 그 방향은 dir에 저장하였고
// cctv를 하나하나 정해진 방향으로 또 ch에 있는 방향 수 만큼
// 돌려서 정답을 찾아냈다.
// 너무 헷갈린다 ㄹㅇ 시간이 촉박하면 풀 수 있을까?

int gogo2() {//각 cctv의 사각지대 계산
	int temp[9][9];
	memcpy(temp, arr, sizeof(arr)); // 배열 복사
	for (int i = 0; i < llist.size(); i++) {
		for (int j = 0; j < ch[llist[i].num].size(); j++) {
			int dr = (dir[i] + ch[llist[i].num][j] + 4) % 4;
			int x = llist[i].x + dx[dr];
			int y = llist[i].y + dy[dr];
			while (1) {
				if (temp[x][y] == 6) break;
				if (x < 0 || y < 0 || x >= n || y >= m) break;
				if (temp[x][y] == 0) {
					temp[x][y] = llist[i].num;
					x += dx[dr];
					y += dy[dr];
				}
				else {
					x += dx[dr];
					y += dy[dr];
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) sum++;
		}
	}
	return sum;
}
void gogo(int idx) { //각 cctv 방향을 정해준다 모든 경우를 해본다.
	if (idx == llist.size()) { //모든 cctv의 방향을 선택했다.
		int k = gogo2(); //사각지대를 검사하고
		ret = min(ret, k); //최대값을 계산
		return;
	}
	for (int i = 0; i < 4; i++) { //각각의 cctv방향을 정해준다.
		dir.push_back(i);
		gogo(idx + 1);
		dir.pop_back();
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				llist.push_back({ i,j,arr[i][j] });
			}
		}
	}
	gogo(0);
	cout << ret;
	return 0;
}