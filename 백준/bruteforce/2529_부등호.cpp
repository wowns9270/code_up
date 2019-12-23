#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<char> compare;
vector<int> big;
vector<int> small;

//백준 부등호 2529
//브루트 포스 문제중 순열을 이용한 문제이다.


//조건에 부합한지 확인하는 함수 true랑false가 의미상 거꿀로지만
//조건에 부합 즉 부등호게 맞다면 false를 반환한다.
bool check_cc(vector<int>& arr) {
	for (int i = 0; i < compare.size(); i++) {
		if (compare[i] == '<') {
			if (arr[i] >= arr[i + 1]) return true;
		}
		else if (compare[i] == '>') {
			if (arr[i] <= arr[i + 1]) return true;
		}
	}

	return false;
}

void small_brouteforce() {

	while (1) {
		//small은 반대로 부등호가 만족하지 않으면 다음 순열을 불러온다.
		// 123 이 만족하지 않으면 다음 순열인  132
		if (check_cc(small) == true)
			next_permutation(small.begin(), small.end());
		else {
			for (int i = 0; i < big.size(); i++) {
				cout << small[i];
			}
			cout << "\n";
			break;
		}

	}
}


//가장 큰 수를 구하는 함수 두 함수를 나눈 이유는
//prev_permutation 과 next_permutation이 다르기 때문이다.
void big_brouteforce() {

	while (1) {
		//true이면 부등호가 만족하지 않으므로
		//이전 순열을 부른다 987 이라면 이전 순열은 978 을 호출한다.
		if (check_cc(big) == true)
			prev_permutation(big.begin(), big.end());
		else {
			//else로 들어오면 지금까지 순열중 가장 큰것이 만족하므로
			//값을 뽑아주고 함수를 빠져나온다.
			for (int i = 0; i < big.size(); i++) {
				cout << big[i];
			}
			cout << "\n";
			break;
		}

	}
}

int main() {
	int n; cin >> n;

	//대소비교 문자들을 벡터에 순서대로 추가한다.
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		compare.push_back(c);
	}
	//조건에서 선택되는 숫자는 모두 달라야 하기에
	//가장 큰 수는 즉 3개라면 987 숫자 3개 4개라면 9876 숫자들로 구성된것이
	//가장 큰 수를 만들 수있다 가장 작은수는 반대이다 012 0123
	for (int i = 0; i < n + 1; i++) {
		big.push_back(9 - i);
		small.push_back(i);
	}
	//조건에 부합하는 가장 큰 수와 작은수를 찾는다,
	big_brouteforce();
	small_brouteforce();
	return 0;

}