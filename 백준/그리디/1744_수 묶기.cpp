#include<bits/stdc++.h>
using namespace std;
int n, ret;
int arr[10001];
int pl, ze, mi;

vector<int> pl_arr;
vector<int> mi_arr;


//1�� ��� �ʿ����
// 0�� ������ Ȧ�� �϶� ��� �ֵǷ� �� ���ְ�
// ����� Ȧ���϶��� 1�� ������ ¦���� ����� �ش���
// ���
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > 0) {

			if (arr[i] == 1) ret += 1;
			else {
				pl_arr.push_back(arr[i]);
				pl++;
			}
		}
		else if (arr[i] == 0) ze++;
		else {
			mi_arr.push_back(arr[i]);
			mi++;
		}
	}

	if (pl_arr.size() % 2 != 0) pl_arr.push_back(1);
	sort(pl_arr.begin(), pl_arr.end());
	for (int i = 0; i < pl_arr.size(); i += 2) {
		ret += pl_arr[i] * pl_arr[i + 1];
	}

	sort(mi_arr.begin(), mi_arr.end());
	if (mi_arr.size() % 2 != 0) {
		if (ze > 0) mi_arr.erase(mi_arr.begin() + mi_arr.size() - 1);
		else mi_arr.push_back(1);
	}

	for (int i = 0; i < mi_arr.size(); i += 2) {
		ret += mi_arr[i] * mi_arr[i + 1];
	}
	cout << ret;
	return 0;
}