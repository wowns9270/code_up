#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;

char arr[20][20];
bool check[20][20];
vector<pair<int, int>> coin;
int ret = 11;

//동전
void bruteforce(int cnt, int x1, int y1, int x2, int y2) {

	//10번을 넘게 하면 기저
	if (cnt == 11) return;

	//2번동전이 보드판에서 떨어진경우
	if ((x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) && (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)) {
		ret = min(ret, cnt);
		return;
	}

	//1번동전이 떨어진경우
	if ((x2 >= 0 && x2 < n && y2 >= 0 && y2 < m) &&
		(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)) {
		ret = min(ret, cnt);
		return;
	}
	//둘다 떨어지면 안되용
	if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m ||
		x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) {
		return;
	}
	//4방향으로 동전을 이동시킨다.
	for (int i = 0; i < 4; i++) {
		int n_x1 = x1 + dx[i];
		int n_y1 = y1 + dy[i];
		int n_x2 = x2 + dx[i];
		int n_y2 = y2 + dy[i];

		//이동하려는 칸이 벽(#) 이라면 원래위치로
		if (n_x1 >= 0 && n_x1 < n && n_y1 >= 0 && n_y1 < m && arr[n_x1][n_y1] == '#') {
			n_x1 = x1;
			n_y1 = y1;
		}
		//두번째 동전도 마찬가지
		if (n_x2 >= 0 && n_x2 < n && n_y2 >= 0 && n_y2 < m && arr[n_x2][n_y2] == '#') {
			n_x2 = x2;
			n_y2 = y2;
		}
		//다음 단계로 넘어간다.
		bruteforce(cnt + 1, n_x1, n_y1, n_x2, n_y2);
	}
}

int main() {
	cin >> n >> m;
	//동전 두개의 위치를 벡터로 뽑아준다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') {
				coin.push_back(make_pair(i, j));
			}
		}
	}

	//함수로 넘길 때 동전의 위치를 매개변수 값으로 넘겨서
	//보드판을 기억하는 것보다 효율적으로 소스를 짤 수 있다.
	bruteforce(0, coin[0].first, coin[0].second, coin[1].first, coin[1].second);
	
	//가장 작은값이 10보다 크다는 소리니까 즉 한동전만 떨어뜨릴 수 없고
	//10번보다 많이 해야해서
	if (ret == 11) cout << "-1";
	else
		cout << ret;
	return 0;
}