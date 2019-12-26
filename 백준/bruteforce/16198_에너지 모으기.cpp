#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int ret;
vector<int> arr;


void bruteforce(int sum) {

	//�糡�� �� 2���� ���� �� ���� �����ؼ� �ִ밪�� �̴´�.
	if (arr.size() == 2) {
		ret = max(ret, sum);
		return;
	}

	for (int i = 1; i < arr.size() - 1; i++) {
		//i-1���� i+1���� ���� �̰� ����
		//�߰����� �����ϰ� ���� �ܰ�� ����
		int k_m = arr[i - 1];
		int k = arr[i];
		int k_p = arr[i + 1];
		arr.erase(arr.begin() + i);
		bruteforce(sum + k_m * k_p);
		//�̾��� ��찡 ������ �ٽ� ���� �ڸ��� �߰����� �ٽ� �־��ְ�
		//���� �ܰ踦 ���� �� �̹� i���� �������� �ʱ�� �����Ѱ��
		//��� ��츦 �ٺ���,

		arr.insert(arr.begin() + i, k);
	}
}
int main() {
	cin >> n;
	//�Է�
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	bruteforce(0);
	cout << ret;
	return 0;
}