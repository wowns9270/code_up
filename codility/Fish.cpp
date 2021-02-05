#include<bits/stdc++.h>
using namespace std;


int solution(vector<int> A, vector<int> B) {
	
	stack<pair<int, int> > st;

	for (int i = 0; i < A.size(); i++) {

		int size = A[i];
		int dir = B[i];

		if (dir == 1) {
			st.push({ size , dir });
			continue;
		}
		if (st.empty()) {
			st.push({ size , dir });
		}
		else {
			while (!st.empty()) {
				int p_size = st.top().first;
				int p_dir = st.top().second;
				if (p_dir == 0) {
					st.push({ size , dir });
					break;
				}
				else {
					if (p_size < size) {
						st.pop();
						if (st.size() == 0) {
							st.push({ size ,dir });
							break;
						}
					}
					else break;
				}
			}
		}
	}
	return (int)st.size();
}
int solution(vector<int> A, vector<int> B) {
	
	stack<pair<int, int> > st;

	for (int i = 0; i < A.size(); i++) {

		int size = A[i];
		int dir = B[i];

		if (dir == 1) {
			st.push({ size , dir });
			continue;
		}
		if (st.empty()) {
			st.push({ size , dir });
		}
		else {

			while (!st.empty()) {

				int p_size = st.top().first;
				int p_dir = st.top().second;

				if (p_dir == 0) {
					st.push({ size , dir });
					break;
				}
				else {
					if (p_size < size) {
						st.pop();
						if (st.size() == 0) {
							st.push({ size ,dir });
							break;
						}
					}
					else break;
				}
			}
		}
	}
	return (int)st.size();
}

int main() {
	cout << solution({ 2,3,4,5  }, { 1,1,1,0});
}