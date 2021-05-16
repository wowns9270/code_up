#include<bits/stdc++.h>
using namespace std;


ifstream in("scc.inp");
ofstream out("scc.out");

int n , m;

vector<vector<int> > arr;
vector<vector<int> > re;
stack<int> st;

int visited[10001];
int finish[10001];

void dfs(int x) {

	for (int i = 0; i < arr[x].size(); i++) {
		
		int k = arr[x][i];

		if (visited[k] == -1) {
			visited[k] = 0;
			dfs(k);
		}
	}
	st.push(x);
}

void re_dfs(int x) {


	for (int i = 0; i < re[x].size(); i++) {

		int r = re[x][i];

		if (finish[r] == -1) {
			finish[r] = 0;
			re_dfs(r);
		}
	}
}


int main() {

	in >> n >> m;

	arr.resize(n + 1);
	re.resize(n + 1);


	for (int i = 0; i < m; i++) {

		int a, b; in >> a >> b;
		arr[a].push_back(b);
		re[b].push_back(a);
	}


	memset(visited, -1, sizeof(visited));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		
		if (visited[i] == -1) {
			visited[i] = 0;
			dfs(i);

			memset(finish, -1, sizeof(finish));
			
			while (!st.empty()) {

				int k = st.top();
				st.pop();


				if (finish[k] == -1) {
					finish[k] = 0;
					re_dfs(k);
					cnt++;
				}
			}
		}
	}

	out << cnt;
}