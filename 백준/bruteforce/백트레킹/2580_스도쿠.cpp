#include<iostream>
using namespace std;

int arr[9][9];
bool low_s[10][10];
bool col_s[10][10];
bool box_s[10][10];

int check(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

void back(int cnt) {
	//여기까지 온것이면 빈칸 다 선택 된것이므로 
	//스도쿠판을 뽑아준다
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	//빈칸이라면
	//후보 1~9까지 가능한것을 골라주는 작업
	if (arr[cnt / 9][cnt % 9] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (low_s[cnt / 9][i] == false && col_s[cnt % 9][i] == false
				&& box_s[check(cnt / 9, cnt % 9)][i] == false) {
				low_s[cnt / 9][i] = true;
				col_s[cnt % 9][i] = true;
				box_s[check(cnt / 9, cnt % 9)][i] = true;
				arr[cnt / 9][cnt % 9] = i;
				back(cnt + 1);
				arr[cnt / 9][cnt % 9] = 0;
				low_s[cnt / 9][i] = false;
				col_s[cnt % 9][i] = false;
				box_s[check(cnt / 9, cnt % 9)][i] = false;

			}
		}
	}
	//빈칸이 아니면 다음 작업
	else back(cnt + 1);
}
int main() {
	//전형적인 백트레킹 
	//입력을 받으면서 행과 열 그리고 박스에 대한 상태를 저장시킨다.
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				low_s[i][arr[i][j]] = true;
				col_s[j][arr[i][j]] = true;
				box_s[check(i, j)][arr[i][j]] = true;
			}
		}
	}
	//시작
	back(0);
}