#include<bits/stdc++.h>
using namespace std;
#define INF 199999999
int arr[9][9];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 }, n, m, ret = INF;
vector<vector<int>> ch = { {},{0},{0,2},{0,1},{0,1,2},{0,1,2,3} };
struct cctv { int x, y, num; }; //��ǥ�� cctv����
vector<cctv> llist;
vector<int> dir;


//�̷��� �ʹ� ���ϴ�..
// �ϴ� cctv�������� �����ִ� ������ ch�� ������״�.
// ������ ���⸶�� 2���� �ݴ���� (+2) 3���� ���� 4���� �������� 5���� ��δ�
// �� �� �ְ� �������
// llist���� �� cctv�� �����ߴ�.
// ��͸� �����鼭 �� cctv�� ������ �����־���.
// �� ������ dir�� �����Ͽ���
// cctv�� �ϳ��ϳ� ������ �������� �� ch�� �ִ� ���� �� ��ŭ
// ������ ������ ã�Ƴ´�.
// �ʹ� �򰥸��� ���� �ð��� �˹��ϸ� Ǯ �� ������?

int gogo2() {//�� cctv�� �簢���� ���
	int temp[9][9];
	memcpy(temp, arr, sizeof(arr)); // �迭 ����
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
void gogo(int idx) { //�� cctv ������ �����ش� ��� ��츦 �غ���.
	if (idx == llist.size()) { //��� cctv�� ������ �����ߴ�.
		int k = gogo2(); //�簢���븦 �˻��ϰ�
		ret = min(ret, k); //�ִ밪�� ���
		return;
	}
	for (int i = 0; i < 4; i++) { //������ cctv������ �����ش�.
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