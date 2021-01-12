#include<bits/stdc++.h>
#define inf 1e14
using namespace std;

int n, m;

vector<vector<pair<long long , long long> > > arr;

pair<long long, long long > dist[200001];

struct cmp {
	bool operator()(pair<long long, long long> x, pair<long long, long long> y) {
		return x.second > y.second;
	}
};


priority_queue < pair<long long, long long> , vector<pair<long long, long long>>
	, cmp>
	q;


///////////////// 틀린소스 정점을 모두 홀 짝으로 나누어야 풀린다.

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	arr.resize(n + 1);

	for (int i = 0; i < m; i++) {
		long long a, b, c; cin >> a >> b >> c;

		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}

	memset(dist, 0x3f, sizeof dist);

	dist[1].second = 0;

	q.push({ 1,0 }); //정점 1 비용 0

	while (!q.empty()) {

		long long x = q.top().first;
		long long cost = q.top().second;

		q.pop();

		for (int i = 0; i < arr[x].size(); i++) {

			long long y = arr[x][i].first;
			long long cc = arr[x][i].second;

			long long kk = cost + cc;

			if (kk % 2 == 0) { // 짝수인경우
				if (dist[y].second > kk) {
					dist[y].second = kk;
					q.push({ y,kk });
				}

			}
			else { // 홀수 인경우
				if (dist[y].first > kk) {
					dist[y].first = kk;
					q.push({ y,kk });
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {

		long long x = dist[i].first;
		long long y = dist[i].second;

		if (x >= 0x3f3f3f3f3f3f3f3f) x = -1;
		if (y >= 0x3f3f3f3f3f3f3f3f) y = -1;

		cout << x << " " << y << "\n";
	}
	return 0;
}