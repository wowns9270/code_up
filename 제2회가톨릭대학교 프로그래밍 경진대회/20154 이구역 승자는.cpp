#include<bits/stdc++.h>
using namespace std;


string a;

int ret[26] = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };


int dp[1000010];

int main() {
	cin >> a;

	for (int i = 0; i < a.size(); i++) {

		dp[i] = ret[a[i] - 'A'];
	}



	for (int i = 1; i <= a.size(); i *= 2) {
		for (int j = 0; j+i < a.size(); j += i*2) {
			dp[j] = (dp[j] + dp[j + i]) % 10;
		}
	}

	if (dp[0] % 2 == 0) cout << "You're the winner?";
	else cout << "I'm a winner!";
	
	return 0;

}