#include<bits/stdc++.h>
using namespace std;

int n, w, h;

vector<string> arr;


int main() {
	cin >> n >> h >> w;

	for (int i =0; i < h; i++) {

		string a; cin >> a;
		arr.push_back(a);
	}

	string ret;

	for (int i = 0; i < n; i++) {
		ret += '?';
	}



	for (int i = 0; i <arr.size(); i++) {
		
		for (int j = 0; j < arr[i].size(); j++) {

			if (arr[i][j] == '?') continue;

			int k = j / w;

			ret[k] = arr[i][j];

		}

	}


	cout << ret;
	return 0;


}