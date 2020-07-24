#include<bits/stdc++.h>
using namespace std;

int dx[] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[] = { 0 ,0,-1,-1,-1,0,1,1,1 };

vector<vector<pair<int, int>>> arr(4,vector<pair<int,int>> (4));
int sum;
int ret;

struct fish {
	int x;
	int y;
	int dir;
};

pair<int, int > shark = { 0,0 };

vector<fish> place(17);

void fish_movement() {

	//1번물고기 부터 차례대로 이동시킨다.
	for (int i = 1; i <= 16; i++) {

		//죽은 물고기는 넘어가자
		if (place[i].x == -1 && place[i].y == -1 && place[i].dir == -1) continue;


		int x = place[i].x;
		int y = place[i].y;
		int dir = place[i].dir;


		//반시계 방향으로 돌리면서 바꿀수 있는지 확인 해준다.
		for (int j = 0; j < 8; j++) {

			int nx = x + dx[ (dir + j - 1)%8  + 1];
			int ny = y + dy[(dir + j - 1) % 8 + 1];

			//arr[nx][ny] 는 이동하고 싶은 칸

			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
			else if (arr[nx][ny].first == 0) { // 여기는 상어 자리
				continue;
			}
			else if (arr[nx][ny].first == -1) { // 빈칸
				place[i].dir = (dir + j - 1) % 8 + 1;
				arr[x][y].second = (dir + j - 1) % 8 + 1;


				place[i].x = nx;
				place[i].y = ny;

				arr[nx][ny] = { i , place[i].dir };

				arr[x][y] = { -1, -1 };

				break;
			}
			else { // 상어가 아니고 경계를 넘어가지 않으면 자리교체

				place[i].dir = (dir + j - 1) % 8 + 1;
				arr[x][y].second = (dir + j - 1) % 8 + 1;


				int kx = place[i].x;
				int ky = place[i].y;

				place[i].x = place[arr[nx][ny].first].x;
				place[i].y = place[arr[nx][ny].first].y;

				place[arr[nx][ny].first].x = kx;
				place[arr[nx][ny].first].y = ky;



				pair<int, int> temp2 = arr[nx][ny];
				arr[nx][ny] = arr[x][y];
				arr[x][y] = temp2;

				break;
			}
		}
	}
}
void gogo() {
	fish_movement();
		
		int x = place[0].x;
		int y = place[0].y;
		int dir = place[0].dir;


		for (int i = 1; ; i++) {

			int ux = x + dx[dir] * i;
			int uy = y + dy[dir] * i;

			if (ux < 0 || uy < 0 || ux >= 4 || uy >= 4) break;

			if (arr[ux][uy].first == -1 && arr[ux][uy].second == -1 ) continue;


			sum += arr[ux][uy].first;


			vector<vector<pair<int, int>>> temp2 = arr;
			vector<fish> temp3 = place;


			//그 물고기는 죽이고
			place[arr[ux][uy].first] = { -1,-1,-1 };
			arr[x][y] = { -1,-1 };
			arr[ux][uy] = { 0 , arr[ux][uy].second };

			place[0] = { ux,uy,arr[ux][uy].second };

			gogo();

			arr = temp2;
			place = temp3;

			
			ret = max(sum, ret);
			sum -= arr[ux][uy].first;
		}
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b; cin >> a >> b;

			arr[i][j] = { a,b };

			//물고기 위치를 저장해준다. //죽으면 -1,-1 로 표시
			place[a] = { i,j,b };
		}
	}
	//상어의 번호는 0이라고 
	sum += arr[0][0].first; // 0,0의 물고기를 먹고 자리를 차지 방향은 물고기방향

	//0,0 에 있던 물고기는 죽음 표시
	place[arr[0][0].first] = { -1,-1 , -1 };
	place[0] = { 0,0,arr[0][0].second };

	arr[0][0] = { 0,arr[0][0].second };
	//1번물고기부터 이동을 한다.
	gogo();
	cout << ret;
}