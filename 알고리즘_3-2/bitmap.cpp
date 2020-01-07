#include<bits/stdc++.h>
using namespace std;
ifstream in("bitmap.inp");
ofstream out("bitmap.out");
int ruuu, kkk, ee, cnt2, soso;
char arr[201][201], a;
string k[10000], b, c;
bool check(int x_from, int x_to, int y_from, int y_to) {
	char ret = arr[x_from][y_from];
	for (int i = x_from; i <= x_to; i++) {
		for (int j = y_from; j <= y_to; j++) {
			if (ret != arr[i][j]) return false;
		}
	}
	return true;
}
void gogo(int x_from, int x_to, int y_from, int y_to) {
	if (x_from > x_to || y_from > y_to) return;
	if (check(x_from, x_to, y_from, y_to)) {
		out << arr[x_from][y_from];
		ruuu++;
		if (ruuu == 50) { out << "\n"; ruuu = 0; }
		return;
	}
	out << "D";
	ruuu++;
	if (ruuu == 50) { out << "\n"; ruuu = 0; }
	int x_mid = (x_from + x_to) / 2;
	int y_mid = (y_from + y_to) / 2;

	gogo(x_from, x_mid, y_from, y_mid);
	gogo(x_from, x_mid, y_mid + 1, y_to);
	gogo(x_mid + 1, x_to, y_from, y_mid);
	gogo(x_mid + 1, x_to, y_mid + 1, y_to);
	return;
}
void gogo1(int x_from, int x_to, int y_from, int y_to, string qq[]) {
	if (x_from > x_to || y_from > y_to) return;
	int x_mid = (x_from + x_to) / 2;
	int y_mid = (y_from + y_to) / 2;
	if (qq[ee][kkk] == 'D') {
		kkk++;
		if (kkk == 50) { ee++; kkk = 0; }
		gogo1(x_from, x_mid, y_from, y_mid, qq);
		gogo1(x_from, x_mid, y_mid + 1, y_to, qq);
		gogo1(x_mid + 1, x_to, y_from, y_mid, qq);
		gogo1(x_mid + 1, x_to, y_mid + 1, y_to, qq);
	}
	else {
		for (int i = x_from; i <= x_to; i++) {
			for (int j = y_from; j <= y_to; j++) {
				arr[i][j] = qq[ee][kkk];
			}
		}
		kkk++;
		if (kkk == 50) { ee++; kkk = 0; }
	}
	return;
}

int main() {

	while (1) {
		if (soso == 0) {
			in >> a >> b >> c;
		}
		else {
			in >> b >> c;
			soso = 0;
		}
		if (a == '#') break;

		kkk = 0; ee = 0; cnt2 = 0; ruuu = 0;
		if (a == 'B') {
			int b_a = atoi(b.c_str());
			int c_a = atoi(c.c_str());
			int t = 0;
			string k; in >> k;
			for (int i = 0; i < b_a; i++) {
				for (int j = 0; j < c_a; j++) {
					if (t < 50)
						arr[i][j] = k[t++];
					else {
						t = 0;
						j--;
						in.ignore();
						in >> k;
					}
				}
			}
			out << "D";
			if (b.size() == 1)out << "   ";
			else if (b.size() == 2)out << "  ";
			else out << " ";
			out << b_a;
			if (c.size() == 1)out << "   ";
			else if (c.size() == 2)out << "  ";
			else out << " ";
			out << c_a << "\n";
			gogo(0, b_a - 1, 0, c_a - 1);
			if (ruuu != 0)out << "\n";
			ruuu = 0;
		}
		else {
			int b_a = atoi(b.c_str());
			int c_a = atoi(c.c_str());
			int xx = 0;
			for (int i = 0; ; i++) {
				if (xx == 0)
					in >> k[i];
				else if (xx == 1) {
					in >> k[i];
					if (k[i].size() == 1) {
						if (k[i][0] == 'D' || k[i][0] == 'B' || k[i][0] == '#') {
							soso = 1;
							a = k[i][0];
							break;
						}
					}
					xx = 0;
				}
				if (k[i].size() < 50)break;
				else if (k[i].size() == 50) { xx = 1; }
			}
			out << "B";
			if (b.size() == 1)out << "   ";
			else if (b.size() == 2)out << "  ";
			else out << " ";
			out << b_a;
			if (c.size() == 1)out << "   ";
			else if (c.size() == 2)out << "  ";
			else out << " ";
			out << c_a << "\n";
			gogo1(0, b_a - 1, 0, c_a - 1, k);
			cnt2 = 0;
			for (int i = 0; i < b_a; i++) {
				for (int j = 0; j < c_a; j++) {
					out << arr[i][j];
					cnt2++;
					if (cnt2 == 50) { out << "\n"; cnt2 = 0; }
				}
			}
			if (cnt2 != 0)out << "\n";
		}
	}
	return 0;
}