#include<bits/stdc++.h>
using namespace std;

ifstream in("show.inp");
ofstream out("show.out");
int test, k, n;

int visited[10002];
int scc[10002], check;
bool check2;
stack<int> st;


//각 정점은 2개의 상태를 가지고 있고
vector<pair<int, char> > users;
vector<vector<int> > node;
vector<vector<int> > re_node;


void edge_add(vector<pair<int, char>>& users) {

	pair<int, char> A = users[0];
	pair<int, char> B = users[1];
	pair<int, char> C = users[2];
	//양쪽의 간선을 모두 연결해야 모순의 관계를 안다?
	//ex 1번전구는 B이다.

	//ㄱA -> B
	node[A.first * 2 + (A.second == 'B' ? 0 : -1)].push_back(B.first * 2 + (B.second == 'R' ? 0 : -1));
	//ㄱB -> A
	node[B.first * 2 + (B.second == 'B' ? 0 : -1)].push_back(A.first * 2 + (A.second == 'R' ? 0 : -1));

	//ㄱB -> C
	node[B.first * 2 + (B.second == 'B' ? 0 : -1)].push_back(C.first * 2 + (C.second == 'R' ? 0 : -1));
	//ㄱC -> B
	node[C.first * 2 + (C.second == 'B' ? 0 : -1)].push_back(B.first * 2 + (B.second == 'R' ? 0 : -1));

	//ㄱC -> A
	node[C.first * 2 + (C.second == 'B' ? 0 : -1)].push_back(A.first * 2 + (A.second == 'R' ? 0 : -1));
	//ㄱA -> C
	node[A.first * 2 + (A.second == 'B' ? 0 : -1)].push_back(C.first * 2 + (C.second == 'R' ? 0 : -1));


	/// reverse

	//B -> ~A
	re_node[B.first * 2 + (B.second == 'R' ? 0 : -1)].push_back(A.first * 2 + (A.second == 'B' ? 0 : -1));
	//A -> ~B
	re_node[A.first * 2 + (A.second == 'R' ? 0 : -1)].push_back(B.first * 2 + (B.second == 'B' ? 0 : -1));

	re_node[C.first * 2 + (C.second == 'R' ? 0 : -1)].push_back(B.first * 2 + (B.second == 'B' ? 0 : -1));
	re_node[B.first * 2 + (B.second == 'R' ? 0 : -1)].push_back(C.first * 2 + (C.second == 'B' ? 0 : -1));

	re_node[A.first * 2 + (A.second == 'R' ? 0 : -1)].push_back(C.first * 2 + (C.second == 'B' ? 0 : -1));
	re_node[C.first * 2 + (C.second == 'R' ? 0 : -1)].push_back(A.first * 2 + (A.second == 'B' ? 0 : -1));
}


void dfs(int x) {

	visited[x] = 1;

	for (int i = 0; i < node[x].size(); i++) {
		if (visited[node[x][i]] == 0) {
			dfs(node[x][i]);
		}
	}

	st.push(x);
}

void dfs2(int x) {

	visited[x] = 1;
	scc[x] = check;

	for (int i = 0; i < re_node[x].size(); i++) {

		if (visited[re_node[x][i]] == 0) {
			dfs2(re_node[x][i]);
		}
	}

}


int main() {

	in >> test;

	while (test--) {

		//전구의 수 , 참가자 수
		in >> k >> n;

		node.clear();
		re_node.clear();

		node.resize(2 * (k + 1));
		re_node.resize(2 * (k + 1));

		for (int i = 0; i < n; i++) {

			users.clear();
			for (int j = 0; j < 3; j++) {
				int a;
				char b;
				in >> a >> b;
				users.push_back({ a,b });
			}
			// conjuctive normal form에 따라 간선을 연결
			edge_add(users);
		}

		memset(visited, 0, sizeof(visited));

		for (int i = 1; i <= k * 2; i++) {

			if (visited[i] == 0) {
				dfs(i);
			}
		}

		memset(visited, 0, sizeof(visited));

		check = 1;
		while (!st.empty()) {

			int k = st.top();
			st.pop();

			if (visited[k] == 0) {
				dfs2(k);
				check++;
			}
		}


		check2 = false;
		for (int i = 1; i <= 2 * k; i += 2) {

			if (scc[i] == scc[i + 1]) {
				out << "-1\n";
				check2 = true;
				break;
			}
		}

		if(check2 == false)
		out << "1\n";
	}

	return 0;

}