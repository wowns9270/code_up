#include<bits/stdc++.h>
using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 }; //�ϵ�����

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
		if (visit[x][y] == false) { //�����Ҷ� �� ���ϴ°��� ����
			visit[x][y] = true;sum += 1;
		}
	int k = 0; // û�� �� ������ �־����� �Ǵ�
	for(int i= 0 ; i<4; i++){
		int idx = (dir + 3-i) % 4; //���ʺ��� ���̸� �� �� �� 3 2 1 ������ �Ǵ�
	if (visit[x+dx[idx]][y+dy[idx]] == false && arr[x + dx[idx]][y + dy[idx]]==0) {
		visit[x + dx[idx]][y + dy[idx]] = true;
		sum += 1; //û�� ������ +1
		x = x + dx[idx]; y = y + dy[idx]; //��ǥ�� �Ű��ְ�
		dir = idx; //������ �׹�������
		k++; // û�Ҹ� �����ϱ�
		break;
	}
	}
	if (k == 0) { // 4���� �� û�Ҹ� ��������
		x = x - dx[dir];
		y = y - dy[dir]; // ����
		if (arr[x][y] == 1) break; //�����ߴµ� ���̶�� ����
	}
	}
	cout << sum;
	return 0;

}