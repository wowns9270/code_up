#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<queue>
using namespace std;

int test;



char how_arr[10000]; //���
int where_arr[10000]; //���
bool visit_arr[10000]; //�湮����?

void bfs(int start) {
	//������ �湮üũ ��𼭴� x
	queue<int>q;
	q.push(start);
	visit_arr[start] = true;
	where_arr[start] = -1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int nx = (x * 2) % 10000;
		//D�� �̵��ϸ鼭 ��� �Դ��� ��� �Դ��� �迭�� ����
		//��𼭸� ���� ������ HOW�� ã��
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


//bfs�����Ͽ� ����� �ٴٸ��� �� ����� ���� �������� �̾Ƴ��� ����
//��𼭿Դ����� ��� �Դ����� ���ؼ� ������ ã�� Ǯ��
int main() {
	cin >> test;

	while (test--) {
		memset(visit_arr, false, sizeof(visit_arr));
		memset(where_arr, 0, sizeof(where_arr));
		int a, b;
		cin >> a >> b;


		//bfs ����
		bfs(a);

		//������ ���� PATH�� ��θ� �����Ѵ�,

		string path;

		//�������� ��� ������?
		int k = where_arr[b]; //where_arr[b]���� �Դ�.
		char c = how_arr[b];  //��� ������ DSLR �߿�

		while (1) {

			//C�� �߰����ش�. 
			path += c;
			//where_arr[k] �� �������̸� �� -1�̸� ��� ��� �ϼ�
			if (where_arr[k] == -1)break;

			//k�� �� ��� �Գ�
			c = how_arr[k];
			//�ڷ� ��� ������
			k = where_arr[k];
		}
		//������ �������� �ٲ��ش�.
		reverse(path.begin(), path.end());
		cout << path << "\n";
	}
	return 0;
}