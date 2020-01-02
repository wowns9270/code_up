#include<bits/stdc++.h>
using namespace std;

vector<string> arr_ret;
set<char> word;
vector<int> d;
int gogo() {
	int arr[26];
	int sum = 0;
	set<char>::iterator it;
	int i = 0;
	for (it = word.begin(); it != word.end(); ++it) {
		arr[*it - 65] = d[i++];
	}

	//이부분을 스트링을 인트로 변환하면서 했었는데 시간초과가 났다.
	//변환하는데 시간이 많이 걸리는 거 같다.
	for (string s : arr_ret) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + arr[x - 65];
		}
		sum += now;
	}
	return sum;
}

int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string k; cin >> k;
		arr_ret.push_back(k);
		//나오는 알파벳을 set에 저장
		for (int j = 0; j < k.size(); j++) {
			word.insert(k[j]);
		}
	}

	//set의 개수만큼 큰값부터 뽑는다/
	for (int i = 0; i < word.size(); i++) {
		d.push_back(9 - i);
	}
	int ret = 0;
	do {
		int sum = gogo();
		ret = max(ret, sum);
	} while (prev_permutation(d.begin(), d.end()));

	cout << ret;
	return 0;
}