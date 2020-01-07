#include<bits/stdc++.h>
using namespace std;
int n;
char arr[10000][10000];
void gogo2(int center,int y_h) {
	arr[y_h][center] = '*';
	arr[y_h + 1][center - 1] = '*';
	arr[y_h + 1][center + 1] = '*';
	arr[y_h + 2][center - 2] = '*';
	arr[y_h + 2][center - 1] = '*';
	arr[y_h + 2][center] = '*';
	arr[y_h + 2][center + 1] = '*';
	arr[y_h + 2][center + 2] = '*';
	return;
}
void gogo(int center,int size,int y_h) {
	if (size == 3) {
		gogo2(center,y_h);
		return;
	}
	int n_center = size / 2;
	gogo(center, n_center, y_h);
	gogo(center - n_center, n_center, y_h + n_center);
	gogo(center + n_center, n_center, y_h + n_center);
}
int main() {
	 cin >> n;
	 memset(arr, ' ', sizeof(arr));
	 gogo(n - 1,n,0);

	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j <= 2*n-1; j++) {
			 cout << arr[i][j];
		 }
		 cout << "\n";
	 }
	 return 0;
}