#include<bits/stdc++.h>
using namespace std;

ifstream in("point.inp");
ofstream out("point.out");

int n;
struct pp {
	int x; 
	int y;
};

vector<pp> arr;
int ccw(pp x, pp y, pp z) {

	return x.x * y.y + y.x * z.y + z.x * x.y
		- (x.y * y.x + y.y * z.x + z.y * x.x);

}
int main() {
	in >> n;
	for (int i = 0; i < n; i++) {
		int x, y; in >> x >> y;

		arr.push_back({x, y});
	}
	in >> n;
	while (n--) {
		pp p; in >> p.x >> p.y;
		bool line_with = false;
		for (int i = 0; i < arr.size(); i++) {

			int k = (i + 1) % arr.size();

			if (max(arr[i].x, arr[k].x) >= p.x &&
				min(arr[i].x, arr[k].x) <= p.x &&
				max(arr[i].y , arr[k].y) >= p.y &&
				min(arr[i].y , arr[k].y) <= p.y) {

				if (ccw(arr[i], arr[k], p) == 0) {
					//선위에 있다,
					line_with = true;
				}
			}
		}
		if (line_with) {
			out << 1 << "\n";
		}
		else { // 선위에 없다.

			int cnt = 0;
			for (int i = 0; i < arr.size(); i++) {

				int k = (i + 1) % arr.size();

				if (arr[i].y < p.y && arr[k].y >= p.y
					&& ccw(arr[i], arr[k], p) > 0) {
					cnt++;
				}
				else if (arr[k].y < p.y && arr[i].y >= p.y
					&& ccw(arr[k], arr[i], p) > 0) {
					cnt++;
				}
			}

			if (cnt % 2 == 0) {
				out << 0 << "\n";
			}
			else {
				out << 1 << "\n";
			}
		}
	}
	return 0;
}