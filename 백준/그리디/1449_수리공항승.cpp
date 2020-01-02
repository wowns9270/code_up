#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;

int arr[1010];
int visit[1010];

//최대한 작은 것부터 크기만큼 매워주고 확인하면서 진행
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (visit[arr[i]] == false) {
			cnt++;
			for (int j = arr[i]; j < arr[i] + m; j++) {
				visit[j] = true;
			}
		}
	}
	cout << cnt;
	return 0;
}