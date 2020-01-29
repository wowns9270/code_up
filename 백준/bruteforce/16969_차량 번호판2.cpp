#include<bits/stdc++.h>
using namespace std;
#define INF 1000000009
string n;

//차량번호판 1에서 글자수 제한이 1000000로 늘었고
//그에따라 나머지연산을 통해 계산
//값 자체가 int를 초과할 수 있어서 long long 으로 바꿨다.
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