#include<bits/stdc++.h>
using namespace std;


int n , t;
vector<int> arr;

int first_num;
int last_num;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a; 
		arr.emplace_back(a);
	}

	cin >> t;

	sort(arr.begin(), arr.end());

	//0 üũ


	//�ε��� ����
	int r = lower_bound(arr.begin(), arr.end(), t) - arr.begin();
	

	int ret = 0;

	int first_num = arr[r - 1] + 1; //2
	int last_num = arr[r]; // 7

	int k_cnt = last_num - t ; // 13 - 10


	while (first_num <= t) {

	
		if (first_num < t)ret += k_cnt;
		else ret += (k_cnt - 1);
		
		first_num++;
	}

	cout << ret;

	//(N-arr[i-1]) * (arr[i]-N) -1;


	// (10 - 8)  * 3 - 1

	// (59 -33) * (100 - 59) - 1;

	return 0;

}