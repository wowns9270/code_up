//#include<bits/stdc++.h>
//using namespace std;
//
//map<int , int> arr;
//
//vector<int> solution(int N, vector<int> A) {
//	
//	int ret = 0;
//	int all_ret = 0;
//
//	for (int i = 0; i < A.size(); i++) {
//
//		int k = A[i];
//
//		if (k >= 1 && k <= N) {
//			arr[k]++;
//			ret = max(ret, arr[k]);
//		}
//		else if (k == N + 1) {
//			all_ret += ret;
//			arr.clear();
//			ret = 0;
//		}
//	}
//	vector<int> ret2;
//	for (int i = 1; i <= N; i++) {
//		ret2.push_back(arr[i] + all_ret);
//	}
//	return ret2;
//}
#include<bits/stdc++.h>
using namespace std;
int arr[100001];
vector<int> solution(int N, vector<int> A) {

	int ret = 0;
	int all_ret = 0;

	for (int i = 0; i < A.size(); i++) {

		int k = A[i];

		if (k >= 1 && k <= N) {
			
			if (arr[k] < all_ret) {
				arr[k] = all_ret + 1;
			}
			else {
				arr[k]++;
			}

			ret = max(ret, arr[k]);

		}
		else if (k == N + 1) {
			all_ret = ret;
		}
	}

	vector<int> ret2;
	for (int i = 1; i <= N; i++) {
		if (arr[i] < all_ret) {
			arr[i] = all_ret;
		}

		ret2.push_back(arr[i]);
	}
	return ret2;
}







int main() {
	solution(5, { 3,4,4,6,1,4,4 });
	return 0;
}