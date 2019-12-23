#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
int n;
//�ִ� �ּ� ����
int max_ret = -1000000000;
int min_ret = 1000000000;


void gogo(int idx, int sum, int pl, int mi, int mu, int di) {

	//�ִ밪�� �ּҰ��� �����Լ��� ����Ͽ� �Լ�����
	//��� ����Ѵ�.
	if (idx == n) {
		max_ret = max(max_ret, sum);
		min_ret = min(min_ret, sum);
		return;
	}

	//��͸� �����ؾ��Ѵ�. ���ϱ� ���� ������ ����
	//�־��� ������ ��� ��츦 �� �غ����� �ִ�.
	if (pl > 0) gogo(idx + 1, sum + arr[idx], pl - 1, mi, mu, di);
	if (mi > 0) gogo(idx + 1, sum - arr[idx], pl, mi - 1, mu, di);
	if (mu > 0) gogo(idx + 1, sum * arr[idx], pl, mi, mu - 1, di);
	if (di > 0) gogo(idx + 1, sum / arr[idx], pl, mi, mu, di - 1);
	return;
}
//������ �����ֱ� 14888
//�̹����� bruteforce�� �ذ��Ҽ��ִ� ������ ������ �ٲ��� �ʱ� ������
//�����ڰ� �ü��ִ� ��� ��츦 �� �غ����μ� ���� ū ���� �������� ã���� �ִ�.
//

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a; arr.push_back(a);
	}

	int plus, minus, mul, divide;
	cin >> plus >> minus >> mul >> divide;

	//arr[0]�� �Լ��� ������ ������ �ǿ����ڰ� �ϳ� �����Ǿ��
	//�ڷ� ������ ���� ������ ������ ���ϰ� �ϱ� ���ؼ��̴�. 
	gogo(1, arr[0], plus, minus, mul, divide);

	cout << max_ret << "\n";
	cout << min_ret;
	return 0;
}