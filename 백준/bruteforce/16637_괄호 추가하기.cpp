#include<bits/stdc++.h>
using namespace std;
#define INF -1999999999

long long n,ret=INF;
string a;
vector<int>arr;

//까다로운 문제였다.
// 일단 괄호를 연속해서 놓을 수 없으므로 
// 그걸 예외처리하는부분 
// 그리고 괄호값이 -가 나올 수 있어서 따로 int 배열을 만드는 부분
// 그리고 괄호 계산을 한것이 x + 0 로 나타 낼 수 있는 부분
// 몰랐으면 풀지 못했다.

int main() {
	 cin >> n >>a;
	 int k = n / 2; //k는 연산자의 개수
	 for (int i = 0; i < a.size(); i++) {
		 if (a[i] >= '0' && a[i] <= '9') {
			 arr.push_back(a[i] - '0');
		 }
		 else if (a[i] == '-') arr.push_back(1);
		 else if (a[i] == '+') arr.push_back(0);
		 else if(a[i] =='*')arr.push_back(2);
	 }
	 for (int i = 0; i < (1 << k); i++) { //괄호를 치는 모든 경우
		 vector<int> b(arr);
		bool check = true;
		 for (int j = 0; j < k-1; j++) { //각 자리에서 옆자리가 있는지
			 //괄호를 겹치게 할 순 없으니까..
			 if (i & (1 << j)) { //j자리를 확인 앞에는 확인할 필요 x
				 if (i & (1 << j + 1)) {//옆자리도 괄호면 안된다.
					 check = false;
					 break;
				 }
			 }
		 }
		 if (check == false) continue; //다른 경우를 알아본다.
		 //일단괄호를 놓는게 가능하면 괄호를 처리해준다.
		 for (int j = 0; j < k; j++) {
			 if (i & (1 << j)) {
				 if (b[2 * j + 1] == 0) {
					 b[2 * j] += b[2 * j + 2];
					 b[2 * j + 2] = 0;
				 }
				 else if (b[2 * j + 1] == 1) {
					 b[2 * j] -= b[2 * j + 2];
					 b[2 * j + 2] = 0;
					 b[2 * j + 1] = 0;
				 }
				 else if (b[2 * j + 1] == 2) {
					 b[2 * j] *= b[2 * j + 2];
					 b[2 * j + 2] = 0;
					 b[2 * j + 1] = 0;
				 }
			 }
		 }
		 long long sum =b[0];
		 for (int j = 2; j < n; j+=2) {
			 if (b[j - 1] == 0) {
				 sum += b[j];
			 }
			 else if (b[j - 1] == 1) {
				 sum -= b[j];
			 }
			 else sum *= b[j];
		 }
		 ret = max(ret, sum);
	 }

	 cout << ret;
	 return 0;
}