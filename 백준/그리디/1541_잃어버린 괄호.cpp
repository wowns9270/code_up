#include<bits/stdc++.h>
using namespace std;

int ret;

//어렵게 말해도 사실 -가 등장한 뒤 모든수는 음수가 될수 있다.
int main() {
	string a; cin >> a;

	string temp;
	int state = 0;
	for (int i = 0; i < a.size(); i++) {


		if (a[i] >= '0' && a[i] <= '9') {
			temp += a[i];
		}
		else {
			int k = atoi(temp.c_str());
			temp.clear();

			if (state == 0) ret += k;
			else ret -= k;
		}


		if (a[i] == '-') state = 1;
	}

	if (state == 0) ret += atoi(temp.c_str());
	else ret -= atoi(temp.c_str());
	cout << ret;
	return 0;
}