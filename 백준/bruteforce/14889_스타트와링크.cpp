#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[20][20];
vector<int> team;

int gogo() {
	vector<int> team1;
	vector<int> team2;

	for (int i = 0; i < team.size(); i++) {
		if (team[i] == 1) {
			team1.push_back(i);
		}
		else team2.push_back(i);
	}
	int sum1 = 0;
	for (int i = 0; i < team1.size() - 1; i++) {
		for (int j = i + 1; j < team1.size(); j++) {
			sum1 += arr[team1[i]][team1[j]];
			sum1 += arr[team1[j]][team1[i]];
		}
	}
	int sum2 = 0;
	for (int i = 0; i < team2.size() - 1; i++) {
		for (int j = i + 1; j < team2.size(); j++) {
			sum2 += arr[team2[i]][team2[j]];
			sum2 += arr[team2[j]][team2[i]];
		}
	}
	return abs(sum1 - sum2);
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n / 2; i++) {
		team.push_back(1);
	}
	for (int i = 0; i < n / 2; i++) {
		team.push_back(2);
	}
	int min_ret = 1000000;
	do {
		int k = gogo();
		min_ret = min(min_ret, k);
	} while (next_permutation(team.begin(), team.end()));

	cout << min_ret;
	return 0;
}