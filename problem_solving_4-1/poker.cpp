#include<bits/stdc++.h>
using namespace std;

ifstream in("poker.inp");
ofstream out("poker.out");

int card[] = { 0,0,0,0 }, n;
int number[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

vector<pair<int, int> > llist;
bool Straight_Flush() {
	int cnt = 1;
	for (int i = 1; i < llist.size(); i++) {
		if (llist[i - 1].first == llist[i].first) {
			if (llist[i - 1].second + 1 == llist[i].second) {
				cnt++;
			}
			else cnt = 1;
		}
		else cnt = 1;
		if (cnt == 5) return true;
	}
	return false;
}
bool four_card() {
	for (int i = 1; i <= 13; i++) {
		if (number[i] >= 4) return true;
	}
	return false;
}
bool Full_House() {
	int triple = -1;
	for (int i = 1; i <= 13; i++) {
		if (number[i] >= 3) {
			triple = i;
			break;
		}
	}
	if (triple == -1) return false;
	for (int i = 1; i <= 13; i++) {
		if (triple != i && number[i] >=2 ) {
			return true;
		}
	}
	return false;
}
bool Flush() {
	for (int i = 0; i < 4; i++) {
		if (card[i] >= 5) return true;
	}
	return false;
}
bool Straight() {
	int r = 0;
	for (int i = 1; i <= 14; i++) {
		if (number[i] > 0) r++;
		else r = 0;
		if (r >= 5) return true;
	}
	return false;
}
bool Triple() {
	for (int i = 1; i <= 13; i++) {
		if (number[i] == 3) return true;
	}
	return false;
}
bool pair_2() {
	int one_pair = -1;
	for (int i = 1; i <= 13; i++) {
		if (number[i] >= 2) {
			one_pair = i;
			break;
		}
	}
	if (one_pair == -1) return false;
	for (int i = 1; i <= 13; i++) {
		if (one_pair != i && number[i] >= 2) {
			return true;
		}
	}
	return false;
}
bool pair_1() {
	for (int i = 1; i <= 13; i++) {
		if (number[i] == 2) return true;
	}
	return false;
}
int main() {
	in >> n;
	while (n--) {
		memset(card, 0, sizeof(card));
		memset(number, 0, sizeof(number));
		llist.clear();
		for (int i = 0; i < 7; i++) {
			string k; in >> k;
			int a, b;
			if (k[0] == 'S')  a = 0;
			else if (k[0] == 'D')  a = 1;
			else if (k[0] == 'H')  a = 2;
			else a = 3;

			if (k[1] >= '0' && k[1] <= '9') b = k[1] - '0';
			else {
				if (k[1] == 'T')  b = 10;
				else if (k[1] == 'J') b = 11;
				else if (k[1] == 'Q') b = 12;
				else if (k[1] == 'K') b = 13;
				else b = 1;
			}
			llist.push_back({ a,b });
			card[a]++;
			number[b]++;
			if (b == 1) {
				number[14]++;
				llist.push_back({ a, 14});
			}
		}
		sort(llist.begin(), llist.end());

		if (Straight_Flush()) { out << "Straight Flush\n"; }
		else if (four_card()) { out << "Four Card\n"; }
		else if (Full_House()) { out << "Full House\n"; }
		else if (Flush()) { out << "Flush\n"; }
		else if (Straight()) { out << "Straight\n"; }
		else if (Triple()) { out << "Triple\n"; }
		else if (pair_2()) { out << "Two Pair\n"; }
		else if (pair_1()) { out << "One Pair\n"; }
		else { out << "Top\n"; }
	}
	return 0;
}