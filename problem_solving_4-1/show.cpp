#include<bits/stdc++.h>
using namespace std;

ifstream in("show.inp");
ofstream out("show.out");
int test, k, n;

int visited[10002];
int scc[10002], check;
bool check2;
stack<int> st;


//�� ������ 2���� ���¸� ������ �ְ�
vector<pair<int, char> > users;
vector<vector<int> > node;
vector<vector<int> > re_node;


void edge_add(vector<pair<int, char>>& users) {

	pair<int, char> A = users[0];
	pair<int, char> B = users[1];
	pair<int, char> C = users[2];
	//������ ������ ��� �����ؾ� ����� ���踦 �ȴ�?
	//ex 1�������� B�̴�.

	//��A -> B
	node[A.first * 2 + (A.second == 'B' ? 0 : -1)].push_back(B.first * 2 + (B.second == 'R' ? 0 : -1));
	//��B -> A
	node[B.first * 2 + (B.second == 'B' ? 0 : -1)].push_back(A.first * 2 + (A.second == 'R' ? 0 : -1));

	//��B -> C
	node[B.first * 2 + (B.second == 'B' ? 0 : -1)].push_back(C.first * 2 + (C.second == 'R' ? 0 : -1));
	//��C -> B
	node[C.first * 2 + (C.second == 'B' ? 0 : -1)].push_back(B.first * 2 + (B.second == 'R' ? 0 : -1));

	//��C -> A
	node[C.first * 2 + (C.second == 'B' ? 0 : -1)].push_back(A.first * 2 + (A.second == 'R' ? 0 : -1));
	//��A -> C
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

		//������ �� , ������ ��
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
			// conjuctive normal form�� ���� ������ ����
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