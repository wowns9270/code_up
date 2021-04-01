#include<bits/stdc++.h>
using namespace std;

ifstream in("area.inp");
ofstream out("area.out");

int test;

struct pp {
	double  x;
	double y;
	double r;
};

vector<pp> arr;
vector<pair< double, double> > point;
vector<pair< double, double> > ret;

void point_compare(pp a, pp b) {


	double r3 = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	double cos_ = ( (a.r * a.r + r3 * r3) - (b.r * b.r)) / (2 * a.r * r3);
	double sin_ = sqrt(1 - ((( (a.r * a.r + r3 * r3) - (b.r * b.r)) / (2 * a.r * r3)) * ( ( (a.r * a.r + r3 * r3) - (b.r * b.r)) / (2 * a.r * r3))) );
	


	double x1 = b.x - a.x;
	double y1 = b.y - a.y;

	double x_1 = (x1 * cos_ - y1 * sin_) * a.r / r3 + a.x;
	double y_1 = (x1 * sin_ + y1 * cos_) * a.r / r3 + a.y;

	double x_2 = (x1 * cos_ + y1 * sin_) * a.r / r3 + a.x;
	double y_2 = (-1 * x1 * sin_ + y1 * cos_) *a.r / r3 + a.y;

	point.push_back({ x_1 , y_1 });
	point.push_back({ x_2 ,y_2 });

	return;
}

double ccw(pair<double, double> a, pair<double, double> b, pair<double, double >c) {


	return b.first * c.second + a.first * b.second + a.second * c.first
		- (b.first * a.second + c.first * b.second + a.first * c.second);
}


double solution() {

	pair<double,double > one = { -3001.0 , -3001.0 };

	double sum = 0;

	for (int i = 0; i < ret.size(); i++) {

		int k = (i + 1) % ret.size();

		sum += ccw(one, ret[i], ret[k]);


	}

	return abs(sum);

}

bool cmp(pair<double, double > x, pair<double, double> y) {

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

int main() {

	out << fixed;

	out.precision(2);

	in >> test;
	while (test--) {

		arr.clear();
		for (int i = 0; i < 3; i++) {
			pp a;

			in >> a.x >> a.y >> a.r;

			arr.push_back(a);
		}

		point.clear();
		ret.clear();

		for (int i = 0; i < 3; i++) {

			int k = (i + 1) % 3;
			point_compare(arr[i], arr[k]);
		}

	

		for (int i = 0; i < 3; i++) {

			double x = arr[i].x;
			double y = arr[i].y;

			double r = arr[i].r;

			for (int j = 0; j < point.size(); j++) {

				double r2 = r * r;

				double temp = ((point[j].first - x) * (point[j].first - x) +
					(point[j].second - y) * (point[j].second - y));


				if (r2 > fabsf(temp)) {

					ret.push_back(point[j]);
				}
			}
		}
		sort(ret.begin(), ret.end(), cmp);
		if (ccw(ret[0], ret[1], ret[2]) < 0) {
			swap(ret[1], ret[2]);
		}

		double ans = fabs(ccw(ret[0] ,ret[1],ret[2])) / 2.0;
		out << ans << "\n";
	}

	return 0;

}