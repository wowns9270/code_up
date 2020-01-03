#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> word;
int ret;

int check_read(int bits) {
	int cnt = 0;
	for (int i = 0; i < word.size(); i++) {
		if ((word[i] & bits) == word[i]) {
			cnt++;
		}
	}
	return cnt;
}

void bruteforce(int idx,int cnt ,int bits) {
	if (cnt == m - 5) {
		int kk =check_read(bits);
		ret = max(ret, kk);
		return;	
	}

	if (idx > 26) {
		return;
	}


	if ((bits & (1 << idx)) == 0) {
		bruteforce(idx + 1, cnt + 1, bits | (1 << idx));
		bruteforce(idx + 1, cnt, bits);
	}
	else {
		bruteforce(idx + 1, cnt, bits);
	}
}
int main() {
	cin >> n >> m;
	//단어를 비트마스크 형태로 저장
	for (int i = 0; i < n; i++) {
		string a; cin >> a;
		int sum = 0;
		for (int j = 0; j < a.size(); j++) {
			sum |= (1 << a[j] - 'a');
		}
		word.push_back(sum);
	}

	//이단어가 없으면 읽을 수 없음
	//즉 5개 이하로는 읽을수 있는단어 0개
	int k = 0;
	k |= (1 << 'a' - 'a');
	k |= (1 << 'c' - 'a');
	k |= (1 << 't' - 'a');
	k |= (1 << 'n' - 'a');
	k |= (1 << 'i' - 'a');

	//모든 경우 탐색
	bruteforce(0,0,k);


	cout << ret;
	return 0;


}