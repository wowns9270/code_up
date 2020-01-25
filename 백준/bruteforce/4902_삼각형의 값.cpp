#include<bits/stdc++.h>
using namespace std;
int arr[401][801],n,ret,summ[401][801];
void gogo(int lo, int left , int right ,int sum) {
	if (lo < 1 || lo > n) return;
	if (left <1 || right > lo * 2) return;
	//for (int i = left; i <= right; i++) sum += arr[lo][i];
	sum += summ[lo][right] - summ[lo][left-1];
	if (ret < sum) ret = sum;
	
	if (left % 2 != 0) {
		gogo(lo + 1, left, right + 2, sum);
	}
	else {
		gogo(lo - 1, left - 2, right, sum);
	}
}
int main() {
	int a = 1;
	while (1) {
		ret = 0;
		 cin >> n;
		if (n == 0)break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < 2 * i; j++) {
				cin >> arr[i][j];
				//합을 미리 구해놓지 않으면 시간초과가 뜬다.
				summ[i][j] = summ[i][j - 1] + arr[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < 2 * i; j++) {
				gogo(i, j,j , 0);
			}
		}
		cout << a++ << ". " << ret <<"\n";
	}
	return 0;
}