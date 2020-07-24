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

	//1������� ���� ���ʴ�� �̵���Ų��.
	for (int i = 1; i <= 16; i++) {

		//���� ������ �Ѿ��
		if (place[i].x == -1 && place[i].y == -1 && place[i].dir == -1) continue;


		int x = place[i].x;
		int y = place[i].y;
		int dir = place[i].dir;


		//�ݽð� �������� �����鼭 �ٲܼ� �ִ��� Ȯ�� ���ش�.
		for (int j = 0; j < 8; j++) {

			int nx = x + dx[ (dir + j - 1)%8  + 1];
			int ny = y + dy[(dir + j - 1) % 8 + 1];

			//arr[nx][ny] �� �̵��ϰ� ���� ĭ

			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
			else if (arr[nx][ny].first == 0) { // ����� ��� �ڸ�
				continue;
			}
			else if (arr[nx][ny].first == -1) { // ��ĭ
				place[i].dir = (dir + j - 1) % 8 + 1;
				arr[x][y].second = (dir + j - 1) % 8 + 1;


				place[i].x = nx;
				place[i].y = ny;

				arr[nx][ny] = { i , place[i].dir };

				arr[x][y] = { -1, -1 };

				break;
			}
			else { // �� �ƴϰ� ��踦 �Ѿ�� ������ �ڸ���ü

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


			//�� ������ ���̰�
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

			//����� ��ġ�� �������ش�. //������ -1,-1 �� ǥ��
			place[a] = { i,j,b };
		}
	}
	//����� ��ȣ�� 0�̶�� 
	sum += arr[0][0].first; // 0,0�� ����⸦ �԰� �ڸ��� ���� ������ ��������

	//0,0 �� �ִ� ������ ���� ǥ��
	place[arr[0][0].first] = { -1,-1 , -1 };
	place[0] = { 0,0,arr[0][0].second };

	arr[0][0] = { 0,arr[0][0].second };
	//1���������� �̵��� �Ѵ�.
	gogo();
	cout << ret;
}