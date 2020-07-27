#include<bits/stdc++.h>
using namespace std;

int n;

char arr[6][6];

bool result;

int k;

vector<pair<int, int>> teacher;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


bool search(int x , int y) {


		for (int j = 0; j < 4; j++) {

			for (int k = 1; ; k++) {

				int ux = x + dx[j] * k;
				int uy = y + dy[j] * k;


				if (arr[ux][uy] == 'O') break;
				if (ux < 0 || uy < 0 || ux >= n || uy >= n) break;


				if (arr[ux][uy] == 'S') {
					return true;
				}
			}
		}
	return false;
}
void gogo(int cnt) {

	if (cnt == 3) {

		for (int i = 0; i < teacher.size(); i++) {

			if (search(teacher[i].first, teacher[i].second) == true) {
				return;
			}
		}

		result = true;
		return;


	}


	for (int i = 0; i < n; i++) {

		for (int j = 0;  j < n; j++) {

		
			if (arr[i][j] == 'X') {

				//장애물 설치
				arr[i][j] = 'O';
				gogo(cnt + 1);
				arr[i][j] = 'X';
			}
		}
	}
}
int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			char a; cin >> a;

			arr[i][j] = a;
			//선생님을 벡터에 넣어주고
			if (arr[i][j] == 'T') {
				teacher.push_back({ i,j });
			}
			//학생의 수를 세준다
			else if (arr[i][j] == 'S') k++;
		}
	}


	gogo(0);

	
	if (result == true) cout << "YES";
	else cout << "NO";

	return 0;
}