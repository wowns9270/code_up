#include<bits/stdc++.h>
using namespace std;
int  h, w, n,ret;
vector<pair<int, int>> arr;

//�ν�ƼĿ�� ������ ���� �ִ밡 �Ǵ� ���̸� ���ϴ� ����
//�ν�ƼĿ�� ���̴� ����� �� 8���̴�. ó���� �򰥷���
//�߸��ߴµ� �׳� ��� ��츦 �� �غô�.
//�̷��� ����ƴ�
int main() {
	cin >> h >> w >> n;

	for (int i = 0; i < n; i++) {
		int r, c; cin >> r >> c;
		arr.push_back({ r,c });
	}

	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {

			int x1 = arr[i].first;
			int y1 = arr[i].second;
			int x2 = arr[j].first;
			int y2 = arr[j].second;

			bool check = false;

			if (max(x1, x2) <= h && y1 + y2 <= w) {
				check = true;
			}
			if (max(y1, y2) <= w && x1 + x2 <= h) {
				check = true;
			}
			if (max(x1, y2) <= h && y1 + x2 <= w) {
				check = true;
			}
			if (max(y1, x2) <= w && x1 + y2 <= h) {
				check = true;
			}
			if (max(y1, x2) <= h && x1 + y2 <= w) {
				check = true;
			}
			if (max(x1, y2) <= w && y1 + x2 <= h) {
				check = true;
			}
			if (max(y1, y2) <= h && x1 + x2 <= w) {
				check = true;
			}
			if (max(x1, x2) <= w && y1 + y2 <= h) {
				check = true;
			}

			if (check == true) {
				int sum = x1 * y1 + x2 * y2;

				ret = max(ret, sum);
			}
		}
	}
	cout << ret;
	return 0;
}