#include<bits/stdc++.h>
using namespace std;


ifstream in("crt.inp");
ofstream out("crt.out");

long long test , n;

vector<pair<long long, long long> > arr;


long long gcd(long long a, long long b) {

	if (b == 0) return a;

	return gcd(b, a % b);

}

long long gcd_extend(long long a, long long b, long long r1, long long r2, long long c1, long long c2) {


	if (b == 0) return r1;

	long long k = a / b;
	long long r = a % b;

	long long t1 = r1 - r2 * k;
	long long t2 = c1 - c2 * k;

	return gcd_extend(b, r, r2, t1, c2, t2);

}


pair<long long, long long> gogo(long long a, long long b, long long c, long long d) {

	// b의 상수를 c로 이항

	c -= b;

	c = c % d;
	if (c < 0) {
		c += d;
	}

	//a    c      d

	long long r1 = gcd(a, d);
	long long r2 = gcd(r1, c);

	a /= r2, c /= r2, d /= r2;

	//확장 유클리드

	long long reverse_check = gcd(a, d);

	if (reverse_check != 1) return { -1, -1 };

	long long reverse_1 = gcd_extend(a, d, 1, 0, 0, 1);

	reverse_1 %= d;

	if (reverse_1 < 0) reverse_1 += d;

	c *= reverse_1;
	c %= d;


	return { d , c };

}

int main() {


	in >> test;

	while (test--) {
		arr.clear();
		in >> n;

		for (int i = 0; i < n; i++) {
			long long a, b;  in >> a >> b;
			arr.push_back({ a,b });
		}


		long long a = arr[0].first; //1
		long long b = arr[0].second; //8

		for (int i = 1; i < n; i++) {

			pair<long long, long long> r = gogo(b, a, arr[i].first, arr[i].second);//5 2


			if (r.first == -1 && r.second == -1) {
				a = -1;
				break;
			}
			// t = 5 k + 2
			// x = 8 t + 1

			long long r1 = b * r.first;
			long long r2 = b * r.second + a;

			b = r1;
			a = r2;

		}
		out << a <<"\n"; 
	}





}