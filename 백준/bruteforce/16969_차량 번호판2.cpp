#include<bits/stdc++.h>
using namespace std;
#define INF 1000000009
string n;

//������ȣ�� 1���� ���ڼ� ������ 1000000�� �þ���
//�׿����� ������������ ���� ���
//�� ��ü�� int�� �ʰ��� �� �־ long long ���� �ٲ��.
long long gogo(int cnt, int pre , long long sum) {
	if (cnt == n.size()) {
		return sum;
	}
	if (pre == 0) {
		if (n[cnt] == 'd') {
			return gogo(cnt + 1, 1, sum * 10%INF);
		}
		else if (n[cnt] == 'c') {
			return gogo(cnt + 1, 2, sum * 26%INF);
		}
	}
	else if (pre == 1) {
		if (n[cnt] == 'd') {
			return gogo(cnt + 1, 1, sum * 9%INF);
		}
		else if (n[cnt] == 'c') {
			return gogo(cnt + 1, 2, sum * 26%INF);
		}
	}
	else {
		if (n[cnt] == 'd') {
			return gogo(cnt + 1, 1, sum * 10%INF);
		}
		else if (n[cnt] == 'c') {
			return gogo(cnt + 1, 2, sum * 25%INF);
		}
	}
}
int main() {
	 cin >> n;
	 cout << gogo(0, 0 , 1);
	 return 0;
}