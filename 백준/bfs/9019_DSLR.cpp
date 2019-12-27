#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<queue>
using namespace std;

int test;



char how_arr[10000]; //어떠케
int where_arr[10000]; //어디서
bool visit_arr[10000]; //방문했음?

void bfs(int start) {
	//시작은 방문체크 어디서는 x
	queue<int>q;
	q.push(start);
	visit_arr[start] = true;
	where_arr[start] = -1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int nx = (x * 2) % 10000;
		//D로 이동하면서 어디서 왔는지 어떻케 왔는지 배열에 저장
		//어디서를 통해 역으로 HOW를 찾음
		if (visit_arr[nx] == false) {
			visit_arr[nx] = true;
			where_arr[nx] = x;
			how_arr[nx] = 'D';
			q.push(nx);
		}
		nx = (x - 1);
		if (nx == -1) nx = 9999;

		if (visit_arr[nx] == false) {
			visit_arr[nx] = true;
			where_arr[nx] = x;
			how_arr[nx] = 'S';
			q.push(nx);
		}
		nx = (x % 1000) * 10 + x / 1000;

		if (visit_arr[nx] == false) {
			visit_arr[nx] = true;
			where_arr[nx] = x;
			how_arr[nx] = 'L';
			q.push(nx);
		}
		nx = (x / 10) + (x % 10) * 1000;

		if (visit_arr[nx] == false) {
			visit_arr[nx] = true;
			where_arr[nx] = x;
			how_arr[nx] = 'R';
			q.push(nx);
		}
	}
}


//bfs를통하여 결과에 다다르면 그 결과가 나온 과정까지 뽑아내는 문제
//어디서왔는지와 어떻게 왔는지를 통해서 역으로 찾는 풀이
int main() {
	cin >> test;

	while (test--) {
		memset(visit_arr, false, sizeof(visit_arr));
		memset(where_arr, 0, sizeof(where_arr));
		int a, b;
		cin >> a >> b;


		//bfs 시작
		bfs(a);

		//끝나고 나면 PATH에 경로를 저장한다,

		string path;

		//도착점이 어디서 왔을까?
		int k = where_arr[b]; //where_arr[b]에서 왔다.
		char c = how_arr[b];  //어떻게 왔을까 DSLR 중에

		while (1) {

			//C를 추가해준다. 
			path += c;
			//where_arr[k] 가 시작점이면 즉 -1이면 모든 경로 완성
			if (where_arr[k] == -1)break;

			//k는 또 어ㅎ게 왔나
			c = how_arr[k];
			//뒤로 계속 가보자
			k = where_arr[k];
		}
		//순서를 역순으로 바꿔준다.
		reverse(path.begin(), path.end());
		cout << path << "\n";
	}
	return 0;
}