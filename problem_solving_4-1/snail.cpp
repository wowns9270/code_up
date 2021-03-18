#include<bits/stdc++.h>
using namespace std;

ifstream in("snail.inp");
ofstream out("snail.out");

int main() {

	while (1) {
		long  double a, b, c, d; in >> a >> b >> c >> d;
		if (a == 0) break;
		int day = 0;

		long  double decrese = b*(d* 0.01);
		long  double h = 0;

		int check = 0;
		while (1) {
			day++;

			h = h + b ;
			if (h > a) { check = 2; break; }

			h = h - c;
			if (h <= 0) { check = 1; break; }

			b -= decrese;
			b < 0 ? b = 0 : b;
		}
		if (check == 2) {
			out << "success on day " << day << "\n";
		}
		else {
			out << "failure on day " << day << "\n";
		}
	}
}