#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> arr(8);
int block[101], ret;


//이게 맞나 싶을 정도로 그냥 해봤는데 되더라 
//각종류마다 땅이 고른지 안고른지 판단해서 하면된다 
// 보고싶지 않다/
int main() {

	arr[1].push_back("0000"); arr[1].push_back("0");
	arr[2].push_back("00");
	arr[3].push_back("001"); arr[3].push_back("10");
	arr[4].push_back("100"); arr[4].push_back("01");
	arr[5].push_back("000"); arr[5].push_back("10");
	arr[5].push_back("01"); arr[5].push_back("101");
	arr[6].push_back("000"); arr[6].push_back("00");
	arr[6].push_back("20"); arr[6].push_back("011");
	arr[7].push_back("000"); arr[7].push_back("00");
	arr[7].push_back("02"); arr[7].push_back("110");

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> block[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[m].size(); j++) {//종류
			int q = i;
			if (n - i >= arr[m][j].size()) {
				int d = block[q] - (arr[m][j][0] - 48);
				bool check = false;
				for (int k = 0; k < arr[m][j].size(); k++) { //종류별
					if (d != block[q++] - (arr[m][j][k] - 48)) {
						check = true;
					}
				}
				if (check == false) ret++;
			}
		}
	}

	cout << ret;
	return 0;
}