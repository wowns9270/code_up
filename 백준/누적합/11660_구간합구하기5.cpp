#include<bits/stdc++.h>
using namespace std;

int n, m;
long long arr[1025][1025];
long long sum[1025][1025];

int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];

			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
				arr[i][j];
		}
	}
	//1,1 에서 각 i,j 까지 부분합이나오고

	while (m--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		cout << sum[c][d] - sum[a-1][d] - 
			sum[c][b-1] + sum[a-1][b-1]<<"\n";
	}
	return 0;

}