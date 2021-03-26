#include<bits/stdc++.h>
using namespace std;

ifstream in("tangent.inp");
ofstream out("tangent.out");


struct pp {
	long long int x;
	long long int y;
	int check;
	int idx;
	int turn;
	int turn_idx;

};

int test, n;

vector<pp> a;
vector<pp> b;
vector<pp> c;


int a_s, b_d;
int b_s, a_d;

long double ccw(pp a, pp b, pp c) {

	return a.x * b.y + b.x * c.y + c.x * a.y
		- (a.y * b.x + b.y * c.x + c.y * a.x);
}

bool cmp(pp a, pp b) {

	if (a.x < b.x) {
		return true;
	}
	else if (a.x == b.x) {

		if (a.y < b.y) {
			return true;
		}
	}
	return false;
}

bool cmp2(pp a, pp b) {

	long long int cc = ccw(c[0], a, b);

	if (cc != 0) {
		if (cc > 0) return true;
		else return false;
	}
	else {

		if (a.x + a.y < b.x + b.y) {
			return true;
		}

	}

	return false;
}

long long int culc(vector<pp>& temp) {

	pp x = { 60000,60000 };

	long long int ret = 0;

	for (int i = 0; i < temp.size(); i++) {

		int k = (i + 1) % temp.size();

		ret += ccw(x, temp[i], temp[k]);
	}

	return abs(ret);

}

vector<pp> solution() {

	int k = -1;
	vector<pp> llist;

	for (int i = 0; i < a.size(); i++) {
		if (a[i].turn == 1) {
			llist.push_back(a[i]);
			k = i;
			break;
		}
	}

	int k2 = a[k].turn_idx;

	llist.push_back(b[k2]);

	while (1) {

		if (b[k2].turn == 1) break;
		k2 = (k2 + 1) % b.size();
		llist.push_back(b[k2]);
	}

	int k3 = b[k2].turn_idx;
	llist.push_back(a[k3]);

	while (1) {
		k3 = (k3 + 1) % a.size();
		if (a[k3].turn == 1) break;
		llist.push_back(a[k3]);
	}

	return llist;
}

long long dist(pp a, pp b) {

	return (b.x - a.x)* (b.x - a.x) + (b.y - a.y) * (b.y - a.y);

}

void gogo() {

	// 에이에서 b 먼저

	for (int i = 0; i < b.size(); i++) {
		
		if (b_d != i) {

			if (ccw(a[a_s], b[b_d], b[i]) == 0) { //일직선에 있다.

				if (dist(a[a_s], b[b_d]) > dist(a[a_s], b[i])) {
					b_d = i;
				}
			}
		}
	}

	for (int i = 0; i < a.size(); i++) {

		if (a_s != i) {
			if (ccw(a[a_s], b[b_d], a[i]) == 0) { //일직선에 있다.

				if (dist(a[a_s], b[b_d]) > dist(a[i], b[b_d])) {
					a_s = i;
				}
			}
		}
	}

	for (int i = 0; i < a.size(); i++) {

		if (a_d != i) {

			if (ccw(b[b_s], a[a_d], a[i]) == 0) { //일직선에 있다.

				if (dist(b[b_s], a[a_d]) > dist(b[b_s], a[i])) {
					a_d = i;
				}
			}
		}
	}

	for (int i = 0; i < b.size(); i++) {

		if (a_d != i) {
			if (ccw(a[a_d], b[b_s], b[i]) == 0) { //일직선에 있다.

				if (dist(a[a_d], b[b_s]) > dist(a[a_d], b[i])) {
					b_s = i;
				}
			}
		}
	}

	a[a_s].turn = 1;
	a[a_s].turn_idx = b_d;

	b[b_s].turn = 1;
	b[b_s].turn_idx = a_d;
}



int main() {
	out << fixed;
	out.precision(1);

	in >> test;
	while (test--) {

		a.clear();
		b.clear();
		c.clear();

		in >> n;


		for (int i = 0; i < n; i++) {
			long long int x, y; in >> x >> y;

			a.push_back({ x,y,1,i,0,0 });
			c.push_back({ x,y,1,i,0,0 });
		}

		in >> n;

		for (int i = 0; i < n; i++) {
			long long int x, y; in >> x >> y;
			b.push_back({ x,y,2,i,0,0 });
			c.push_back({ x,y,2,i,0,0 });
		}


		//c를 통해 오목 다각형을 만들고 넓이를 구하고
		sort(c.begin(), c.end(), cmp);
		sort(c.begin() + 1, c.end(), cmp2);

		stack<pp> st;

		st.push(c[0]);
		st.push(c[1]);

		for (int i = 2; i < c.size(); i++) {
			while (st.size() >= 2) {

				pp x = st.top();
				st.pop();
				pp y = st.top();

				if (ccw(y, x, c[i]) > 0) {
					st.push(x);


					break;
				}
			}
			st.push(c[i]);
		}

		vector<pp> d;

		while (!st.empty()) {
			d.push_back(st.top());
			st.pop();
		}
		reverse(d.begin(), d.end());

		vector<pp> e;
		
		//a-> b
		a_s = -1, b_d = -1;
		b_s = -1, a_d = -1;
		
		//b->a


		for (int i = 0; i < d.size(); i++) {

			int k = (i + 1) % d.size();

			if (d[i].check == 1 && d[k].check == 2) {

				a_s = d[i].idx;
				b_d = d[k].idx;

			}
			else if (d[i].check == 2 && d[k].check == 1) {
				b_s = d[i].idx;
				a_d = d[k].idx;;
			}
		}

		// 거리 줄이기

		gogo();



		vector<pp> qq = solution();

		double total_ = culc(qq) / 2.0;
		double a_ = culc(a) / 2.0;
		double b_ = culc(b) / 2.0;



		out << total_ - (a_ + b_) << "\n";

	}
}