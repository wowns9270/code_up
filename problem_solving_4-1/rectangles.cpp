#include<bits/stdc++.h>
using namespace std;
#define MAX 10000


ifstream in("rectangles.inp");
ofstream out("rectangles.out");

int n;

struct pp {

	int x;    
	int y_d;
	int y_u;
	int state; // 시작선 , 끝선

};

vector<pp> arr;

int max_y = 0;
int min_y = 20001;

struct tree {
	int y_sum;
	int cnt;
};

tree seg[800000];

bool cmp(pp a, pp b) {

	if (a.x < b.x) {
		return true;
	}
	return false;
}

void update(int x, int y, int s, int r, int l , int node) {

	//주어진 범위를 벗어나면 업데이트 할 필요 없다.
	if (r > y || l < x) {
		return;
	}
	//완전히 범위 안에 들어간 경우
	else if (x <= r && l <= y) {
		if (s == 1) seg[node].cnt++;
		else seg[node].cnt--;
	} 
	else {
		int m = (r + l) / 2;

		update(x, y, s, r, m, node * 2);
		update(x, y, s, m + 1, l, node * 2 + 1);
	}

	if (seg[node].cnt > 0) {  
		seg[node].y_sum = l - r + 1;
	}
	else {
		seg[node].y_sum = seg[node * 2].y_sum + seg[node * 2 + 1].y_sum;
	}
}

int main() {

	in >> n;

	for (int i = 0; i < n; i++) {

		int a, b, c, d;
		in >> a >> b >> c >> d;
		arr.push_back({ a+ MAX,b+ MAX,d+ MAX -1,1 });
		arr.push_back({ c+ MAX,b+ MAX,d+ MAX -1,2 });

		max_y = max(max_y, d+ MAX);
		min_y = min(min_y, b+ MAX);
	}

	sort(arr.begin(), arr.end() , cmp);


	int ret = 0;
	for (int i = 0; i < arr.size(); i++) {

		if (i) {
			int dx = arr[i].x - arr[i - 1].x;
			ret += dx * seg[1].y_sum;
		}
		update(arr[i].y_d, arr[i].y_u, arr[i].state, min_y, max_y , 1);
	}

	out << ret << "\n";
}