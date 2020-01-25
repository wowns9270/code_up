#include<bits/stdc++.h>
using namespace std;
int n, m, d, ret;
int dx[] = { 0,-1,0 };
int dy[] = { -1,0,1 };
int arr[16][16];
vector<int> arrow;
int copy_arr[16][16];
bool visit2[16][16];
pair<int, int> check_attack(int lo, int col) {
	//궁수의 사정거리는 최소 1이다.
	//자기 윗칸이 몬스터인지 아닌지 판단.
	if (copy_arr[lo - 1][col] == 1) {
		return { lo - 1,col };
	}
	else {
		//위칸이 몬스터가 아니라면
		//거리에 따른 우선순위에 맞게 몬스터를 공격
		//방문 배열을 초기화 해준다.
		memset(visit2, false, sizeof(visit2));
		queue<pair<int, int>> q;

		//거리가 1인 괴물 위치는 방문처리해주고
		//왼 위 오 순으로 진행
		q.push({ lo - 1,col });
		visit2[lo - 1][col] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			//x,y가 거리랑 같으면 그 다음값은 어짜피 볼필요도 없으니
			//넘어가준다.
			if (abs(lo - x) + abs(col - y) >= d) continue;
			//3방향으로
			for (int i = 0; i < 3; i++) {
				int ux = x + dx[i];
				int uy = y + dy[i];

				if (ux < 0 || ux >= n || uy < 0 || uy >= m) continue;

				//최초로 적이 보이면 그좌표를 리턴해준다.
				if (copy_arr[ux][uy] == 1) {
					return { ux,uy };
				}
				//적이아니면 방문처리해주고 다음 탐색을 진행한다.
				else if (copy_arr[ux][uy] == 0 && visit2[ux][uy] == false) {
					visit2[ux][uy] = true;
					q.push({ ux,uy });
				}
			}
		}
		//거리안에 적이  없으면 -1 -1 을 리턴한다.
		return { -1,-1 };
	}
}

//게임이 시작 된다.
int start_game() {
	int attack_cnt = 0;
	//배열복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}
	int a = n;
	while (a >= 1) {

		vector<pair<int, int>> point;
		//궁수가 공격한 위치가 중복되는게 있을 수 있어서
		// 공격 좌표를 저장한다.
		for (int i = 0; i < arrow.size(); i++) {
			auto it = check_attack(a, arrow[i]);
			if (it.first == -1 && it.second == -1) continue;
			//-1,-1 이면 공격 가능한 몬스터가 없다는 말
			else {
				point.push_back(it);
				//좌표를 저장
			}
		}

		//중복하지 않게 몬스터 샤냥수 증가
		for (int i = 0; i < point.size(); i++) {
			if (copy_arr[point[i].first][point[i].second] == 1) {
				copy_arr[point[i].first][point[i].second] = 0;
				attack_cnt++;
			}
		}
		//몬스터의 위치를 내리지말고
		//궁수의 위치를 하나 올린다.
		a--;
	}
	return attack_cnt;
}
void gogo(int idx, int cnt) { // 궁수 배치
	if (idx == m) { // 궁수는 3명을 고른다.
		if (cnt == 3) {
			//3명을고르면 게임을 진행한다.
			//여기서 memcpy(copy,arr,sizeof(arr)) 를통해
			//배열 복사가 가능하다.
			int k = start_game();
			ret = max(ret, k);
		}
		return;
	}

	//궁수를 고르는 경우 고르지 않는 경우
	arrow.push_back(idx);
	gogo(idx + 1, cnt + 1);
	arrow.pop_back();
	gogo(idx + 1, cnt);
}
int main() {
	cin >> n >> m >> d;
	//입력을 받는다/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	//궁수를 고르는 작업
	gogo(0, 0);
	cout << ret;
	return 0;
}