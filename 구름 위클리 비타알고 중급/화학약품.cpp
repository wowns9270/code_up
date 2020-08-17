#include<bits/stdc++.h>
using namespace std;

int n;

vector<int> arr;
vector<int> arr2;

vector<int> llist;
vector<int> llist2;

void gogo(int idx, int sum , int cnt , vector<int> & arr , vector<int> & llist) {

	if (idx >= arr.size()) {
		llist.push_back(sum);
		return;
	}

	gogo(idx + 1, sum + arr[idx], cnt + 1, arr, llist);
	gogo(idx + 1, sum, cnt, arr, llist);

}

int main() {

	cin >> n;

	for (int i = 0; i < (n+1) / 2; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	for (int i = (n+1) / 2; i < n; i++) {
		int a; cin >> a;
		arr2.push_back(a);
	}

	//각 그룹의 부분집합을 구하자
	gogo(0, 0 , 0 , arr , llist);
	gogo(0, 0 , 0 , arr2 , llist2);

	sort(llist.begin(), llist.end());
	sort(llist2.begin(), llist2.end());
	//각각의 양끝 좌표
	int i = 0; int j = llist2.size()-1;
	long long cnt = 0;
	while (i < llist.size() && j >= 0) {

		// 두 수의 합
		long long sum = llist[i] + llist2[j];
		//합이 0인 경우
		if (sum == 0) {
			long long c1 = 1;
			long long c2 = 1;
			i++;
			j--;
			while ( i < llist.size() && llist[i] == llist[i - 1]) {

				c1++;
				i++;

			}
			while (j >= 0 && llist2[j] == llist2[j + 1]) {
				c2++;
				j--;
			}

			cnt += c1 * c2;
		}
		else if (sum > 0) {
			j--;
		}
		else if (sum < 0) {
			i++;
		}
	}
	cout << cnt - 1;
}