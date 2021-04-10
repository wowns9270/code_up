#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

ifstream in("contour.inp");
ofstream out("contour.out");

//사각형
struct square {
	long long x;
	long long y;
	long long x_e;
	long long idx;
};

//우선순위 큐 정렬
bool operator<(square x, square y) {
	if (x.y < y.y) {
		return true;
	}
	return false;
}

struct point {
	long long x;
	long long y;
	long long state; //들어오는지 나가는지
	long long idx;
};

long long a, b, c,ret;

vector<square> arr;
vector<point> point_list;

bool cmp(point x, point y) {
	
	if (x.x < y.x) return true;
	else if (x.x == y.x) {
		if (x.y > y.y) return true;
	}
	return false;
}


int main() {
	long long aaa = 1;
	while (in >> a >> b >> c) {
		out << "Test Case #" << aaa++ << " : ";
		arr.clear();
		point_list.clear();

		long long idx = 0;
		long long ret = 0;

		arr.push_back({ a,b,c,idx++ });
		
		while (1) {
			long long a, b, c; in >> a >> b >> c;

			if (a == 0 && b == 0 && c == 0) break;
			
			arr.push_back({ a,b,c,idx++ });
		}

		for (int i = 0; i < arr.size(); i++) {

			long long a = arr[i].x;
			long long b = arr[i].y;
			long long c = arr[i].x_e;
			long long d = arr[i].idx;

			point_list.push_back({ a,b,1, d }); //들어오는 선
			point_list.push_back({ c,b,2,d });  //나가는선

		}

		//점들을 정리
		sort(point_list.begin(), point_list.end(), cmp);

		priority_queue<square> q;
		q.push(arr[point_list[0].idx]);
		long long cur_x = point_list[0].x;
		for (int i = 1; i < point_list.size(); i++) {

			long long ch = point_list[i].x - point_list[i - 1].x;

			long long point_state = point_list[i].state;
			long long point_x = point_list[i].x;
			long long point_idx = point_list[i].idx;
			long long point_y = point_list[i].y;

			if (point_state == 1) { // 들어오는 사각형

				while (!q.empty()) {

					long long x_s = q.top().x;
					long long x_e = q.top().x_e;
					if (x_s <= point_x && x_e >= point_x) {
						break;
					}
					q.pop();
				}

				if (q.size() == 0) {
					out << ret << " ";
					ret = 0;
					q.push({ arr[point_idx] });
					continue;
				}

				ret += ch * q.top().y;
				q.push({ arr[point_idx] });
			}
			else { //나가는 사각형
				while(!q.empty()) {
					int x_e = q.top().x_e;
					if (x_e < point_x) {
						q.pop();
					}
					else break;
				}				
				ret += ch * q.top().y;
			}
		}
		out << ret <<"\n";
	}
	return 0;

}