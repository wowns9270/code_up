#include<bits/stdc++.h>
using namespace std;
string a;
int b,ret;
vector<int> arr;
void  check() {
	int sum = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		sum *= 10;
		sum += arr[i];
	}
	if (sum <= b) {
		ret = max(ret, sum);
	}
	return;
}
//숫자 재배치 문제
//10^9 이면 최대9!개의 경우가 나오고 그때 만족하는 값들중 최대를 찾는
//문제이다 이런 순열은 next_permutation 이나 pre_permutation으로 해결한ㄷ,
int main() {
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) {
		arr.push_back(a[i] - '0');
	}
	sort(arr.begin(), arr.end());
	do {
		if (arr[0] == 0) continue;
		check();
	} while (next_permutation(arr.begin(), arr.end()));
	if (ret == 0)cout << "-1";
	else cout << ret;
	return 0;
}