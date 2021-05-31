#include<bits/stdc++.h>

#define HOLEE 500
#define S 551
#define E 552
using namespace std;

ifstream in("mice.inp");
ofstream out("mice.out");

long long test, n, k, h, m;

struct pp {
	long long x1;
	long long y1;
	long long x2;
	long long y2;
};

vector<pp> line;
vector<pair<long long, long long>> point;
vector<pair<long long, long long>> hole;
vector<pair<long long, long long>> mouse;
vector<vector<long long> > arr;

long long c[600][600];
long long f[600][600];
long long visited[600];


long long ccw(pair<long long, long long> x, pair<long long, long long> y, pair<long long, long long> z) {

	return y.first * z.second + x.first * y.second + x.second * z.first
		- (x.second * y.first + y.second * z.first + x.first * z.second);



}

bool gogo(pair<long long, long long> x, pair<long long, long long> y, pp z) {

	long long r1 = ccw(x, y, { z.x1 , z.y1 });
	long long r2 = ccw(x, y, { z.x2 , z.y2 });

	long long r3 = ccw({ z.x1 , z.y1 }, { z.x2 , z.y2 }, x);
	long long r4 = ccw({ z.x1 , z.y1 }, { z.x2 , z.y2 }, y);


	if( (r1 >= 0 && r2 <= 0 && r3 >= 0 && r4 <= 0) ||
		(r1 <= 0 && r2 >= 0 && r3 >= 0 && r4 <= 0) ||
		(r1 >= 0 && r2 <= 0 && r3 <= 0 && r4 >= 0) ||
		(r1 <= 0 && r2 >= 0 && r3 <= 0 && r4 >= 0) )
			return false;    //교차한다.

	return true;


}

long long bfs(long long s, long long e) {

	
	memset(visited, -1, sizeof(visited));

	queue<long long> q;

	q.push(s);

	while (!q.empty() && visited[e] == -1) {

		long long x = q.front();

		q.pop();


		for (int i = 0; i < arr[x].size(); i++) {

			long long y = arr[x][i];

			if (visited[y] != -1) continue;
			if (c[x][y] - f[x][y] <= 0) continue;

			visited[y] = x;
			q.push(y);

			if (y == e) break;
		}
	}


	if (visited[e] == -1)return 0;

	long long flow = 9999999;

	long long k = e;

	while (k != S) {
		flow = min(flow, c[visited[k]][k] - f[visited[k]][k]);
		k = visited[k];
	}
	k = e;
	while (k != S) {
		f[visited[k]][k] += flow;
		f[k][visited[k]] -= flow;
		k = visited[k];
	}
	return flow;
}

int main() {

	in >> test;


	while (test--) {
		arr.clear(), mouse.clear(), point.clear(), line.clear(), hole.clear();

		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));

		in >> n >> k >> h >> m;

		arr.resize(600);

		for (int i = 0; i < n; i++) {
			long long a, b; in >> a >> b;
			point.push_back({ a,b });
		}

		//라인을 받아준다.
		for (int i = 0; i < point.size(); i++) {
			long long j = (i + 1) % point.size();

			line.push_back({ point[i].first , point[i].second , point[j].first , point[j].second });
		}

		for (int i = 0; i < h; i++) {
			long long a, b; in >> a >> b;
			hole.push_back({ a,b });
		}

		for (int i = 0; i < m; i++) {
			long long a, b; in >> a >> b;
			mouse.push_back({ a,b });
		}




		for (int i = 0; i < mouse.size(); i++) {

			c[S][i] = 1;
			arr[i].push_back(S);
			arr[S].push_back(i);

			for (int j = 0; j < hole.size(); j++) {

				c[j + HOLEE][E] = k;
				arr[j + HOLEE].push_back(E);
				arr[E].push_back(j + HOLEE);

				//각 쥐와 구멍의 조합이 가능한지 판단
				bool check_one = false;
				for (int k = 0; k < line.size(); k++) {

					long long r = ccw({ line[k].x1, line[k].y1 }, { line[k].x2, line[k].y2 }, hole[j]);
					if (r == 0) continue;

					bool check = gogo(mouse[i], hole[j], line[k]);

					if (check == false) check_one = true;
					//check == true 이면 쥐와 구멍이 일치한다.

				}

				if (check_one == false) {
					arr[i].push_back(j + HOLEE);
					arr[j + HOLEE].push_back(i);

					c[i][j + HOLEE] = 1;
				}
			}
		}
	

		long long ret = 0;
		while (1) {


			long long k = bfs(S, E);
			ret += k;
			if (k == 0) break;
		}

		if (ret == mouse.size()) out << "Possible\n";
		else out << "Impossible\n";
	}
	
	return 0;

}