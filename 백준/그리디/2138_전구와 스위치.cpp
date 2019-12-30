#include<bits/stdc++.h>
using namespace std;
string a, b, c;
int n;
int gogo(string x, string y, int cnt) {
	for (int i = 1; i < n; i++) {
		if (x[i - 1] != y[i - 1]) {
			x[i - 1] == '0' ? x[i - 1] = '1' : x[i - 1] = '0';
			x[i] == '0' ? x[i] = '1' : x[i] = '0';
			if (i != n - 1)
				x[i + 1] == '0' ? x[i + 1] = '1' : x[i + 1] = '0';
			cnt++;
		}
		if (x == b) {
			return cnt;
		}
	}
	if (x[n - 1] != y[n - 1]) return -1;
}
//그리디
// 0 1 2 3 4 5 6 7 8 9 10
//여기서보면 0 을 바꿀 수 있는건 자기자신 그리고 1이다.
//0을 킬지 말지 선택을하면
//0을 바꿀 수있는건 1하나밖에없다.
//그럼 여기서 1은 0상태와 결과의 0번째 상태가 같으면 바꾸지말고
// 다르면 바꿔준다. 이부분이 그리디이다.
// 그럼 1을 결정을하고나면 1을 바꿀 수 있는건 2	밖에 없다.
// 진짜 설명이 신기하더라. 그렇게 끝까지 가면 9번 비트를 10번이 올바르게 키거나
//말거나한다. 그러면 10번은? 10번이 같지 않으면 불가능한 경우이다..
// 너무 신기하고요
int main() {
	cin >> n;
	cin >> a >> b;
	c = a;
	if (a[0] == '0') a[0] = '1';
	else a[0] = '0';
	if (a[1] == '0') a[1] = '1';
	else a[1] = '0';

	int  on = gogo(a, b, 1);
	int off = gogo(c, b, 0);

	if (on == -1 && off == -1) {
		cout << "-1";
		return 0;
	}
	else if (on == -1) {
		cout << off;
	}
	else if (off == -1) {
		cout << on;
	}
	else cout << min(on, off);
	return 0;
}