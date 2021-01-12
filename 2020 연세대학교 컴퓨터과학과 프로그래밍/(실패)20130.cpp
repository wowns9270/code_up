#include<bits/stdc++.h>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

struct ee {
	bool check;
	int x;
	int y;
};

bool check[201][201];
ee gogo[26];

bool key[26];

int n, m;

vector<string> arr;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a; cin >> a;

		arr.push_back(a);
	}

	pair<int, int> st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '@') {
				st.first = i, st.second = j;
			}

			if (arr[i][j] <= 'Z' && arr[i][j] >= 'A') {

				gogo[arr[i][j] - 'A'].check = false;
				gogo[arr[i][j] - 'A'].x = i;
				gogo[arr[i][j] - 'A'].y = j;

			}


		}
	}

	queue<pair<int, int>> q;
	q.push({ st.first, st.second });
	check[st.first][st.second] = true;

	vector<pair<int, int>>ret;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		ret.push_back({ x + 1, y + 1 });



		if (arr[x][y] == '!') break;

		for (int i = 0; i < 4; i++) {

			int ux = x + dx[i];
			int uy = y + dy[i];

			if (arr[ux][uy] == '#') continue;
			if (check[ux][uy] == true) continue;

			//열쇠방
			if (arr[ux][uy] <= 'z' && arr[ux][uy] >= 'a') {

				if (check[ux][uy] == false) {
					check[ux][uy] = true;
					key[arr[ux][uy] - 'a'] = true;
					q.push({ ux,uy });

					if (gogo[arr[ux][uy] - 'a'].check == true) {
						check[gogo[arr[ux][uy] - 'a'].x][gogo[arr[ux][uy] - 'a'].y] = true;
						q.push({ gogo[arr[ux][uy] - 'a'].x,gogo[arr[ux][uy] - 'a'].y });
					}
				}

				
			}
			else if (arr[ux][uy] <= 'Z' && arr[ux][uy] >= 'A') {


				//열쇠도 있고 방문도 가능
				if (key[arr[ux][uy] - 'A'] == true ) {
					check[ux][uy] = true;
					q.push({ ux,uy });
				}
				else if (key[arr[ux][uy] - 'A'] == false) {
					gogo[arr[ux][uy] - 'A'].check = true;
				}
			}
			else {
				check[ux][uy] = true;
				q.push({ ux,uy });
			}
		}
	}


	cout << ret.size() << "\n";

	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i].first << " " << ret[i].second << "\n";
	}
	return 0;



}