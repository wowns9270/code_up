#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int test;
int t_n = 1;

//������ XOR������ �˾ƺ��� ��������.
//���⼭ ���� ���� ¦���� ��Ÿ���� ��Ʈ�� �ٽ� ������ ������
//�׳� �� XOR �����ϸ� �ȴ�..



int main() {
	cin >> test;
	while (test--) {
		int n; cin >> n;
		map<int, int> arr;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			arr[a] ++;
		}
		vector<int> llist;
		for (auto it = arr.begin(); it != arr.end(); it++) {
			if (it->second % 2 != 0) {
				llist.push_back(it->first);
			}
		}
		int ret = llist[0];
		for (int i = 1; i < llist.size(); i++) {
			ret ^= llist[i];
		}
		cout << "Case #" << t_n++ << "\n";
		cout << ret << "\n";
	}
}