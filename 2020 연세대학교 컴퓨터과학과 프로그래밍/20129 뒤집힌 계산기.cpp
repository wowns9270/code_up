#include<bits/stdc++.h>
using namespace std;

vector<pair<char, long long> > ch(4);

bool cmp(pair<char, long long> x, pair<char, long long> y) {

	if (x.second > y.second) return true;
	return false;

}

struct ee {
	bool type;
	long long a;
	char b;
};



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);


	long long a, b, c, d; cin >> a >> b >> c >> d;

	ch[0] = { '+', a },
		ch[1] = { '-', b },
		ch[2] = { '*', c },
		ch[3] = { '/', d };

	string k; cin >> k;

	vector<ee> llist;

	long long temp = 0;
	for (int i = 0; i < k.size(); i++) {

		if (k[i] == '+' || k[i] == '-' || k[i] == '*' || k[i] == '/') {
			llist.push_back({ 0 , temp , 0 });
			llist.push_back({ 1, 0, k[i] });
			temp = 0;
		}
		else {
			temp = temp * 10 + char(k[i] - '0');
		}
	}
	llist.push_back( {0, temp, 0});

	vector<ee> llist2;
	sort(ch.begin(), ch.end(), cmp);

	for (int i = 0; i < ch.size(); i++) {
		llist2.clear();
		char op = ch[i].first;

		for (int j = llist.size()-1; j >= 0; j--) {

			//문자면 일단 넣는다.
			if (llist[j].type == 1) llist2.push_back(llist[j]);
			//숫자일 때 비어있거나 op랑 틀리면
			else if (llist2.empty() || llist2.back().b != op) {
				llist2.push_back(llist[j]);
			}
			else {

				llist2.pop_back();

				long long k = llist2.back().a;
				llist2.pop_back();

				if (op == '+') {
					llist[j].a = k + llist[j].a;
				}
				else if (op == '-') {
					llist[j].a = k - llist[j].a;
				}
				else if (op == '*') {
					llist[j].a = k * llist[j].a;
				}
				else if (op == '/') {
					llist[j].a = k / llist[j].a;
				}

				llist2.push_back(llist[j]);
			}
		}
		reverse(llist2.begin(), llist2.end());

		llist = llist2;
	}

	cout<< llist[0].a;

	return 0;
}