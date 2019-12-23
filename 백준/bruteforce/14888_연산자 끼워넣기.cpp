#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
int n;
//최대 최소 설정
int max_ret = -1000000000;
int min_ret = 1000000000;


void gogo(int idx, int sum, int pl, int mi, int mu, int di) {

	//최대값과 최소값은 전역함수를 사용하여 함수인자
	//대신 사용한다.
	if (idx == n) {
		max_ret = max(max_ret, sum);
		min_ret = min(min_ret, sum);
		return;
	}

	//재귀를 이해해야한다. 더하기 부터 나누기 까지
	//주어진 개수로 모든 경우를 다 해볼수가 있다.
	if (pl > 0) gogo(idx + 1, sum + arr[idx], pl - 1, mi, mu, di);
	if (mi > 0) gogo(idx + 1, sum - arr[idx], pl, mi - 1, mu, di);
	if (mu > 0) gogo(idx + 1, sum * arr[idx], pl, mi, mu - 1, di);
	if (di > 0) gogo(idx + 1, sum / arr[idx], pl, mi, mu, di - 1);
	return;
}
//연산자 끼워넣기 14888
//이문제는 bruteforce로 해결할수있다 숫자의 순서는 바뀌지 않기 때문에
//연산자가 올수있는 모든 경우를 다 해봄으로서 가장 큰 값과 작은값을 찾을수 있다.
//

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a; cin >> a; arr.push_back(a);
	}

	int plus, minus, mul, divide;
	cin >> plus >> minus >> mul >> divide;

	//arr[0]를 함수로 보내는 이유는 피연산자가 하나 설정되어야
	//뒤로 더할지 뺄지 곱할지 나눌지 편하게 하기 위해서이다. 
	gogo(1, arr[0], plus, minus, mul, divide);

	cout << max_ret << "\n";
	cout << min_ret;
	return 0;
}