#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> line;


// 이건진짜 시발 아는게 힘이다. 절대 모른다
// 그룹으로 나눠서 그룹의 크기가 최대 감소순열이고
// 그룹의 개수가 최대 증가순열 개수이다...
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	   
	if (m + k - 1 <= n && n <= m * k) {
		for (int i = 1; i <= n; i++) {
			arr.push_back(i);
		}
		line.push_back(0); //처음경계
		line.push_back(k); // 첫 k개 최대 감소순열 개수
		n -= k; //전체 개수에서 n개 빠지고
		m -= 1; // 그룹 수도 하나 감소

		int gs = m == 0 ? 1 : n / m;
		int r = m == 0 ? 0 : n % m;
		for (int i = 0; i < m; i++) {
			line.push_back(line.back() + gs + (r > 0 ? 1 : 0));
			if (r > 0) {
				r -= 1;
			}
		}

		for (int i = 0; i < line.size()-1; i++) {
			reverse(arr.begin() + line[i], arr.begin() + line[i + 1]);
		}

		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] <<" ";
		}
	}
	else {
		cout << -1;
	}
	return 0;
}