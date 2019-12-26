#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int ret;
vector<int> arr;


void bruteforce(int sum) {

	//양끝값 즉 2개가 남을 때 까지 진행해서 최대값을 뽑는다.
	if (arr.size() == 2) {
		ret = max(ret, sum);
		return;
	}

	for (int i = 1; i < arr.size() - 1; i++) {
		//i-1값과 i+1값을 먼저 뽑고 나서
		//중간값을 삭제하고 다음 단계로 진행
		int k_m = arr[i - 1];
		int k = arr[i];
		int k_p = arr[i + 1];
		arr.erase(arr.begin() + i);
		bruteforce(sum + k_m * k_p);
		//뽑았을 경우가 끝나면 다시 원래 자리에 중간값을 다시 넣어주고
		//다음 단계를 진행 즉 이번 i값을 삭제하지 않기로 결정한경우
		//모든 경우를 다본다,

		arr.insert(arr.begin() + i, k);
	}
}
int main() {
	cin >> n;
	//입력
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	bruteforce(0);
	cout << ret;
	return 0;
}