#include<bits/stdc++.h>
using namespace std;
ifstream in("sudoku.inp");
ofstream out("sudoku.out");
int arr[9][9];
char ch_arr[9][9];
bool low_s[10][10];
bool col_s[10][10];
bool box_s[10][10];
void back(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				out << arr[i][j] << " ";
			}
			out << "\n";
		}
		out << "\n";
		return;
	}
	if (arr[cnt / 9][cnt % 9] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (low_s[cnt / 9][i] == false && col_s[cnt % 9][i] == false
				&& box_s[ch_arr[cnt/9][cnt%9]-'a'][i] == false) {
				low_s[cnt / 9][i] = true;
				col_s[cnt % 9][i] = true;
				box_s[ch_arr[cnt / 9][cnt % 9] - 'a'][i] = true;
				arr[cnt / 9][cnt % 9] = i;
				back(cnt + 1);
				arr[cnt / 9][cnt % 9] = 0;
				low_s[cnt / 9][i] = false;
				col_s[cnt % 9][i] = false;
				box_s[ch_arr[cnt / 9][cnt % 9] - 'a'][i] = false;
			}
		}
	}
	else back(cnt + 1);
	return;
}
int main() {
	int test; in >> test;
	int a = 1;
	while (test--) {
		out << "Test Case No: " << a++<<"\n";
		memset(arr, 0, sizeof(arr));
		memset(low_s, false, sizeof(low_s));
		memset(col_s, false, sizeof(col_s));
		memset(box_s, false, sizeof(box_s));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				in >> arr[i][j];
				if (arr[i][j] != 0) {
					low_s[i][arr[i][j]] = true;
					col_s[j][arr[i][j]] = true;
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				in >> ch_arr[i][j];
				if(arr[i][j] !=0)
				box_s[ch_arr[i][j] - 'a'][arr[i][j]] = true;
			}
		}
		back(0);
	}
	return 0;
}