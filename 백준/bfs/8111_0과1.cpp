 //0�� 1�θ� �̷�����־���Ѵ�
//1�� ��� �ϳ��� �־���ϰ�
//���Ǳ��̴� 100����
// ���� 0���� ���������ʴ´�
//n�� ����߿��� �����ϴ¼�
#include<bits/stdc++.h>
using namespace std;


bool check[20001];
int from[20001];
int how[20001];

int main() {
	int test; cin >> test;
	while (test--) {
		memset(check, false, sizeof(check));
		memset(from, -1, sizeof(from));
		memset(how, -1, sizeof(how));
		int n; cin >> n;

		from[1 % n] = -1;
		how[1] = 1;
		check[1] = true;

		queue<int> q;
		q.push(1);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i <= 1; i++) {
				int ux = (x * 10 + i) % n;

				if (check[ux] == false) {
					check[ux] = true;
					from[ux] = x;
					how[ux] = i;
					q.push(ux);
				}
			}
		}
		if (check[0] == false) {
			cout << "BRAK\n";
		}
		else {
			string a;

			int k = how[0];
			a += to_string(k);
			int kk = from[0]; // ��𼭿Գ�

			while (1) {
				k = how[kk];
				a += to_string(k);

				kk = from[kk];
				if (kk == -1) break;
			}
			reverse(a.begin(), a.end());
			cout << a<<"\n";
		}
	}
	return 0;
}