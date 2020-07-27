#include<bits/stdc++.h>
using namespace std;
int dx[] = { 0 ,0 ,-1,1 };
int dy[] = { 1,-1,0,0 };
struct horse {int num;int x, y; int dir;int h;};
int n, k , color[12][12];
horse llist[11];
vector<vector<vector<horse>>> arr;
vector<horse> temp;
void move(int ux , int uy) {
	for (int i = 0; i < temp.size(); i++) {

		llist[temp[i].num] = { temp[i].num , ux , uy , temp[i].dir , (int)arr[ux][uy].size() };
		arr[ux][uy].push_back({ temp[i].num , ux , uy ,temp[i].dir ,(int)arr[ux][uy].size() });
	}
}
int main() {
	cin >> n >> k;
	arr.resize(n, vector<vector<horse>>(n));
	//ÆÇÀÇ »ö±òÀ» ¹Þ´Â´Ù.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> color[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		int a, b, c; cin >> a >> b >> c;
		llist[i] = { i , a - 1,b - 1,c - 1,(int)arr[a - 1][b - 1].size() };
		arr[a - 1][b - 1].push_back({ i,a - 1,b - 1,c - 1,(int)arr[a - 1][b - 1].size() });
	}
	int turn = 0;
	while (turn <= 1000) {
		bool check = false;
		for (int i = 1; i <= k; i++) {

			int dir = llist[i].dir;

			int x = llist[i].x;
			int y = llist[i].y;
			int h = llist[i].h;

			int ux = x + dx[dir];  //°¡¾ßÇÒ ¹æÇâ
			int uy = y + dy[dir];

			temp.assign(arr[x][y].begin() + h, arr[x][y].end()); // ¿Å°Ü¾ß ÇÒ ¸»µé
			arr[x][y].erase(arr[x][y].begin() + h , arr[x][y].end());

			//ÆÇÀ» ¹þ¾î³µÀ» ¶§
			if ( (ux < 0 || uy < 0 || ux >= n || uy >= n) || color[ux][uy] == 2) {
				if (temp[0].dir == 0) temp[0].dir = 1;
				else if (temp[0].dir == 1) temp[0].dir = 0;
				else if (temp[0].dir == 2) temp[0].dir = 3;
				else if (temp[0].dir == 3) temp[0].dir = 2;

				ux = x + dx[temp[0].dir];
				uy = y + dy[temp[0].dir];

				if ((ux < 0 || uy < 0 || ux >= n || uy >= n) || color[ux][uy] == 2) {
					llist[temp[0].num].dir = temp[0].dir;
					move(x, y);
				}
				else if (color[ux][uy] == 0) {
					move(ux, uy);
					if ((int)arr[ux][uy].size() >= 4) check = true;
				}
				else if (color[ux][uy] == 1) { //»¡ 
					reverse(temp.begin(), temp.end());
					move(ux, uy);
					if (arr[ux][uy].size() >= 4) check = true;
				}
			}
			else {
				if (color[ux][uy] == 0) { // Èò 
					move(ux, uy);
					if (arr[ux][uy].size() >= 4) check = true;
				}
				else if (color[ux][uy] == 1) { //»¡ 
					reverse(temp.begin(), temp.end());
					move(ux, uy);
					if ((int)arr[ux][uy].size() >= 4) check = true;
				}
			}
		}
		turn++;
		if (check == true) break;
	}
	if (turn > 1000) cout << -1;
	else
	cout << turn;
	return 0;
}