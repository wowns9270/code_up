#include<bits/stdc++.h>
using namespace std;

ifstream in("hull.inp");
ofstream out("hull.out");

int n;

vector<pair<int, int> > arr;

bool cmp(pair<int, int> a, pair<int, int> b) {


	if (a.first < b.first) {
		return true;
	}
	else if (a.first == b.first) {

		if (a.second < b.second) {
			return true;
		}
	}
	return false;
}

double ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {

	return b.first * c.second + a.first * b.second + a.second * c.first -
		(a.second * b.first + b.second * c.first + a.first * c.second);

}

bool cmp2(pair<int, int> a, pair<int, int> b) {

	if (ccw(arr[0] , a ,b ) != 0) {
		if (ccw(arr[0], a, b) > 0) return true;
		else return false;
	}
	else {

		if (a.first + a.second < b.first + b.second) {
			return true;
		}

	}

	return false;

}

int main() {

	in >> n;

	for (int i = 0; i < n; i++) {
		int a, b; in >> a >> b;
		arr.push_back({ a,b });
	}

	sort(arr.begin() , arr.end() , cmp);
	sort(arr.begin() + 1, arr.end(), cmp2);

	stack<pair<int, int> > st;

	st.push(arr[0]);
	st.push(arr[1]);

	for (int i = 2; i < arr.size(); i++) {

		while (st.size() >= 2) {

			pair<int,int> x = st.top();
			st.pop();
			pair<int, int> y = st.top();


			if (ccw(y, x, arr[i]) > 0) {
				st.push(x);
				break;
			}
		}
		st.push(arr[i]);
	}
	vector<pair<int, int> > d;
	while (!st.empty()) {
		d.push_back(st.top());
		st.pop();
	}

	reverse(d.begin(), d.end());
	out << d.size() << "\n";

	for (int i = 0; i < d.size(); i++) {
		out << d[i].first << " " << d[i].second <<"\n";
	}

	return 0;


}