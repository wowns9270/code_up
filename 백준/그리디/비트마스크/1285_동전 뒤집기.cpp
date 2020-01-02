#include<bits/stdc++.h>
using namespace std;

char arr[21][21];
//그리디와 비트마스크를 이용한 풀이
//행과 열 상태를 따라 보면 최대 2^n*2^n*n^2 너무 경우가 많아서 힘들다
//행만 결정시키면 열은 뒤집나 마나 작은것을 선택하면 되므로
//2^n * n^2 =   최대 419,430,400로  4초 정도에 가능하다
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ret = 0;
	int ans = 4000;
	for (int i = 0; i < (1 << n); i++) { //비트상태
		ret = 0;
		for (int j = 0; j < n; j++) { //각 열
			int sum = 0;
			for (int k = 0; k < n; k++) { //행
				char go = arr[k][j];
				if (i & (1 << k)) {
					go == 'H' ? go = 'T' : go = 'H';
				}

				if (go == 'H') sum++; //SUM 각행의 H
			}
			sum = min(sum, n - sum);
			ret += sum;
		}
		ans = min(ans, ret);
	}
	cout << ans;
	return 0;
}