#include<bits/stdc++.h>
using namespace std;
int arr[16];
int n, l, r, x,ret;
vector<int>llist;

// n �� 20 ������ �������� �θ�Ʈ ���� ����..
//�� ������ �������� �������� ���Ƿ� 2^n n�� �ִ� 15�̹Ƿ� 
// ����� �ذᰡ�� �׸��� �� ���ǵ�
// 2���̻� ���°� �ִ��ּ� �׸���
// ������������ ū���� ���̸� ���ϱ� ���� ���ı����ؼ� �����Ͽ���.
void gogo(int idx, int cnt, int sum) {
	if (idx == n) {
		if (cnt >= 2) {
			if (sum >= l && sum <= r) {
				if (llist[llist.size() - 1] - llist[0] >= x) {
					ret++;
				}
			}
		}
		return;
	}
	llist.push_back(arr[idx]);
	gogo(idx + 1, cnt + 1, sum + arr[idx]);
	llist.pop_back();
	gogo(idx + 1, cnt, sum);
}
int main() {
	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	gogo(0, 0, 0); //idx.cnt.sum;
	cout << ret;
	return 0;
}