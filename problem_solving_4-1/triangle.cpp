#include<bits/stdc++.h>
using namespace std;


int n;

ifstream in("triangle.inp");
ofstream out("triangle.out");


vector<pair<long long , long long > > A;
vector<pair<long long , long long > > B;
vector<pair<long long , long long > > C;

long long  ccw(pair<long long , long long > x, pair<long long , long long > y, pair<long long , long long > z) {

	long long  a = y.first * z.second + x.first * y.second + x.second * z.first
		- (x.second * y.first + y.second * z.first + x.first * z.second);

	return a;

}


bool gogo() {



	//한직선에서 ccw의 곱이 음수이고 반대 직선에서 ccw의 곱이 음수이면
	//교차한다.


	for (int i = 0; i < 3; i++) {
		long long  k1 = (i + 1) % 3;


		for (int j = 0; j < 3; j++) {
			long long  k2 = (j + 1) % 3;

			long long  a1 = ccw(A[i], A[k1], B[j]);
			long long  a2 = ccw(A[i], A[k1], B[k2]);

			long long  b1 = ccw(B[j], B[k2], A[i]);
			long long  b2 = ccw(B[j], B[k2], A[k1]);


			if ( ((a1 < 0 && a2 >0 ) && (b1 >0 && b2 <0))  ||
				((a1 < 0 && a2 >0) && (b1 < 0 && b2 > 0)) ||
				((a1 > 0 && a2 < 0) && (b1 > 0 && b2 < 0)) ||
				((a1 > 0 && a2 < 0) && (b1 < 0 && b2 > 0))
				) {
				return true;
			}

		}
	}

	return false;
}

long long  gogo2() {

	for (int i = 0; i < 3; i++) {
		long long  k1 = (i + 1) % 3;


		for (int j = 0; j < 3; j++) {
			
			if (
				(min(A[i].first, A[k1].first) <= B[j].first && max(A[i].first, A[k1].first) >= B[j].first)
				&&
				(min(A[i].second, A[k1].second) <= B[j].second && max(A[i].second, A[k1].second) >= B[j].second)
				)
			{
				long long  r = ccw(A[i], A[k1], B[j]);

				if (r == 0) return 1;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		long long  k1 = (i + 1) % 3;


		for (int j = 0; j < 3; j++) {

			if (
				(min(B[i].first, B[k1].first) <= A[j].first && max(B[i].first, B[k1].first) >=A[j].first)
				&&
				(min(B[i].second, B[k1].second) <= A[j].second && max(B[i].second, B[k1].second) >= A[j].second)
				)
			{
				long long  r = ccw(B[i], B[k1], A[j]);

				if (r == 0) return 1;
			}
		}
	}

	return 0;
}


bool cmp(pair<long long , long long > x, pair<long long , long long > y) {

	if (x.first < y.first) {
		return true;
	}
	else if (x.first == y.first) {

		if (x.second < y.second) {
			return true;
		}
	}
	return false;
}

bool cmp2(pair<long long , long long > x, pair<long long , long long > y) {

	long long int  ccw1 = ccw(C[0], x, y);

	if (ccw1 != 0) {
		if (ccw1 > 0) return true;
		else return false;
	}
	else {
		if (x.first + x.second < y.first + y.second)
			return true;
	}
	return false;
}

long long  convechull() {
	sort(C.begin(), C.end(), cmp);
	sort(C.begin() + 1, C.end(), cmp2);

	stack<pair<long long , long long > > st;

	st.push(C[0]);
	st.push(C[1]);


	for (int i = 2; i < C.size(); i++) {


		while (st.size() >= 2) {

			pair<long long , long long > x = st.top();
			st.pop();
			pair<long long , long long > y = st.top();


			if (ccw(y, x, C[i]) > 0) {
				st.push(x);
				break;
			}
		}
		st.push(C[i]);
	}

	return st.size();
}

long long  gogo3() {
	
	
	bool check1 = false;
	for (int i = 0; i < 3; i++) {
	

		bool check2 = false;
		int r = -1;

		for (int j = 0; j < 3; j++) {

			int k1 = (j + 1) % 3;

			if (ccw(B[j], B[k1], A[i]) == 0) continue;

			if (ccw(B[j], B[k1], A[i]) < 0) {

				if (r == 2) {
					check2 = true;
					break;
				}
				r = 1;

			}
			else {

				if (r == 1) {
					check2 = true;
					break;
				}
				r = 2;
			}
		}

		if (check2 == true) {
			check1 = true;
			break;
		}
	}

	if (check1 == false) return 2;

	check1 = false;

	for (int i = 0; i < 3; i++) {


		bool check2 = false;
		int r = -1;

		for (int j = 0; j < 3; j++) {

			long long  k1 = (j + 1) % 3;

			if (ccw(A[j], A[k1], B[i]) == 0) continue;

			if (ccw(A[j], A[k1], B[i]) < 0) {

				if (r == 2) {
					check2 = true;
					break;
				}
				r = 1;

			}
			else {

				if (r == 1) {
					check2 = true;
					break;
				}
				r = 2;
			}
		}

		if (check2 == true) {
			check1 = true;
			break;
		}
	}

	if (check1 == false) return 2;

	return 0;
}


int main() {
	in >> n;
	

	for (int i = 0; i < n; i++) {

		A.clear();
		B.clear();
		C.clear();

		long long  a, b, c, d, e, f;

		in >> a >> b >> c >> d >> e >> f;

		A.push_back({ a,b }),A.push_back({ c,d }),A.push_back({ e,f });
		C.push_back({ a,b }), C.push_back({ c,d }), C.push_back({ e,f });

		in >> a >> b >> c >> d >> e >> f;

		B.push_back({ a,b }),B.push_back({ c,d }),B.push_back({ e,f });
		C.push_back({ a,b }), C.push_back({ c,d }), C.push_back({ e,f });

		

		//두직선이 교차하는 것이 존재하는가 
		long long  ret1 = gogo();
	
		if (ret1 == true) {
			out << "2" <<"\n";
		}
		else {

			long long  r = convechull();

			if (r == 3) {
				//out << gogo3() << "\n";

				if (gogo3() == 2) {
					out << "2" << "\n";
				}
				else {

					long long r3 = gogo2();

					if (r3 == 1) out << "3" << "\n";
					else {
						out << "1" << "\n";
					}

				}

			}
			else {
				long long  r2 = gogo2();

				if (r2 == 1) out << "3" << "\n";
				else {
					out << "1" << "\n";
				}
			}
		}
	}

	return 0;

}
