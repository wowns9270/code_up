#include<bits/stdc++.h>
using namespace std;

int test , n , m, r;

ifstream in("p10010.inp");
ofstream out("p10010.out");

vector<string> arr;

int dx[] = { 1,-1,0,0,-1,-1,1,1 };
int dy[] = { 0,0,1,-1,1,-1,-1,1 };

bool gogo(int x, int y, string r, int dir) {

	bool ans = true;

	for (int i = 0; i < r.size(); i++) {


		
		if (x < 0 || y < 0 || x >= n || y >= m) {
			ans = false;
			break;
		}

		int k = arr[x][y] >= 'A' && arr[x][y] <='Z' ? arr[x][y] - 'A' : arr[x][y] - 'a';
		int k2 = r[i] >= 'A' && r[i] <='Z' ? r[i] - 'A' : r[i] - 'a';

		if (k != k2) {
			ans = false;
			break;
		}

		x = x + dx[dir];
		y = y + dy[dir];

	}

	return ans;

}



pair<int, int> solution(string k1) {

	for (int i = 0; i < arr.size(); i++) {

		for (int j = 0; j < arr[i].size(); j++) {

			int k = arr[i][j] >= 'A' && arr[i][j] <= 'Z' ? arr[i][j] - 'A' : arr[i][j] - 'a';
			int k2 = k1[0] >= 'A' && k1[0] <= 'Z' ? k1[0] - 'A' : k1[0] - 'a';

			if (k != k2) continue;

			for (int k = 0; k < 8; k++) {				
				bool check = gogo(i, j, k1 , k );

				if (check == true) {
					return { i+1,j+1 };
				}

			}

		}
	}
}


int main() {

	in >> test;

	while (test--) {

		in >> n >> m;

		arr.clear();

		for (int i = 0; i < n; i++) {
			string k; in >> k;
			arr.push_back(k);
		}

		in >> r;

		for (int i = 0; i < r; i++) {
			string r1; in >> r1;

			pair<int,int> ret = solution(r1);
			out << ret.first << " " << ret.second << "\n";
		}

		out << "\n";
	}
	return 0;

}