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
	//�ü��� �����Ÿ��� �ּ� 1�̴�.
	//�ڱ� ��ĭ�� �������� �ƴ��� �Ǵ�.
	if (copy_arr[lo - 1][col] == 1) {
		return { lo - 1,col };
	}
	else {
		//��ĭ�� ���Ͱ� �ƴ϶��
		//�Ÿ��� ���� �켱������ �°� ���͸� ����
		//�湮 �迭�� �ʱ�ȭ ���ش�.
		memset(visit2, false, sizeof(visit2));
		queue<pair<int, int>> q;

		//�Ÿ��� 1�� ���� ��ġ�� �湮ó�����ְ�
		//�� �� �� ������ ����
		q.push({ lo - 1,col });
		visit2[lo - 1][col] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			//x,y�� �Ÿ��� ������ �� �������� ��¥�� ���ʿ䵵 ������
			//�Ѿ�ش�.
			if (abs(lo - x) + abs(col - y) >= d) continue;
			//3��������
			for (int i = 0; i < 3; i++) {
				int ux = x + dx[i];
				int uy = y + dy[i];

				if (ux < 0 || ux >= n || uy < 0 || uy >= m) continue;

				//���ʷ� ���� ���̸� ����ǥ�� �������ش�.
				if (copy_arr[ux][uy] == 1) {
					return { ux,uy };
				}
				//���̾ƴϸ� �湮ó�����ְ� ���� Ž���� �����Ѵ�.
				else if (copy_arr[ux][uy] == 0 && visit2[ux][uy] == false) {
					visit2[ux][uy] = true;
					q.push({ ux,uy });
				}
			}
		}
		//�Ÿ��ȿ� ����  ������ -1 -1 �� �����Ѵ�.
		return { -1,-1 };
	}
}

//������ ���� �ȴ�.
int start_game() {
	int attack_cnt = 0;
	//�迭����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}
	int a = n;
	while (a >= 1) {

		vector<pair<int, int>> point;
		//�ü��� ������ ��ġ�� �ߺ��Ǵ°� ���� �� �־
		// ���� ��ǥ�� �����Ѵ�.
		for (int i = 0; i < arrow.size(); i++) {
			auto it = check_attack(a, arrow[i]);
			if (it.first == -1 && it.second == -1) continue;
			//-1,-1 �̸� ���� ������ ���Ͱ� ���ٴ� ��
			else {
				point.push_back(it);
				//��ǥ�� ����
			}
		}

		//�ߺ����� �ʰ� ���� ���ɼ� ����
		for (int i = 0; i < point.size(); i++) {
			if (copy_arr[point[i].first][point[i].second] == 1) {
				copy_arr[point[i].first][point[i].second] = 0;
				attack_cnt++;
			}
		}
		//������ ��ġ�� ����������
		//�ü��� ��ġ�� �ϳ� �ø���.
		a--;
	}
	return attack_cnt;
}
void gogo(int idx, int cnt) { // �ü� ��ġ
	if (idx == m) { // �ü��� 3���� ����.
		if (cnt == 3) {
			//3�������� ������ �����Ѵ�.
			//���⼭ memcpy(copy,arr,sizeof(arr)) ������
			//�迭 ���簡 �����ϴ�.
			int k = start_game();
			ret = max(ret, k);
		}
		return;
	}

	//�ü��� ���� ��� ���� �ʴ� ���
	arrow.push_back(idx);
	gogo(idx + 1, cnt + 1);
	arrow.pop_back();
	gogo(idx + 1, cnt);
}
int main() {
	cin >> n >> m >> d;
	//�Է��� �޴´�/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	//�ü��� ���� �۾�
	gogo(0, 0);
	cout << ret;
	return 0;
}