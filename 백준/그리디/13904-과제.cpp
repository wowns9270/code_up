#include<bits/stdc++.h>
using namespace std;

int n, ret;
vector<pair<int, int>> arr;
int visit[1000];

bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.second > y.second) {
		return true;
	}
	else if (x.second == y.second) {
		if (x.first > y.first) return true;
	}
	return false;
}
int main() {
	//�ϴ� ������ ���� ���� �޴� �ͺ��� �������Ѵ�.
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	sort(arr.begin(), arr.end(), cmp);

	//visit �� �׳��� ������ �ߴ��� ���ߴ����̴�.
	//������ 4���� ������ �̹� 4�Ͽ� �ٸ������� ������
	//3���� ���� �������� �ϴ� ���̴�. �̰� �ֱ׷��ĸ�
	//������ ū�� ���� ���� ������ �ִ��� �̷Ｍ �ٸ������� �� �� �ְ� �ϰ�
	//�ճ� �ճ��� üũ�ϸ鼭 �� �� ������ ������ �Ѵ�.
	//�׸���
	for (int i = 0; i < n; i++) {
		if (visit[arr[i].first] == false) {
			visit[arr[i].first] = true;
			ret += arr[i].second;
		}
		else {
			int j = arr[i].first - 1;
			while (1) {
				if (j == 0) break;

				if (visit[j] == false) {
					visit[j] = true;
					ret += arr[i].second;
					break;
				}
				j--;
			}
		}
	}
	cout << ret;
	return 0;
}