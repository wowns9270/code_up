#include<bits/stdc++.h>
using namespace std;

vector<string> arr_ret;
set<char> word;
vector<int> d;
int gogo() {
	int arr[26];
	int sum = 0;
	set<char>::iterator it;
	int i = 0;
	for (it = word.begin(); it != word.end(); ++it) {
		arr[*it - 65] = d[i++];
	}

	//�̺κ��� ��Ʈ���� ��Ʈ�� ��ȯ�ϸ鼭 �߾��µ� �ð��ʰ��� ����.
	//��ȯ�ϴµ� �ð��� ���� �ɸ��� �� ����.
	for (string s : arr_ret) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + arr[x - 65];
		}
		sum += now;
	}
	return sum;
}

int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string k; cin >> k;
		arr_ret.push_back(k);
		//������ ���ĺ��� set�� ����
		for (int j = 0; j < k.size(); j++) {
			word.insert(k[j]);
		}
	}

	//set�� ������ŭ ū������ �̴´�/
	for (int i = 0; i < word.size(); i++) {
		d.push_back(9 - i);
	}
	int ret = 0;
	do {
		int sum = gogo();
		ret = max(ret, sum);
	} while (prev_permutation(d.begin(), d.end()));

	cout << ret;
	return 0;
}