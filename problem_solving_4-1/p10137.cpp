#include<bits/stdc++.h>
using namespace std;


ifstream in("p10137.inp");
ofstream out("p10137.out");

vector<double> arr;

int main() {
	
	out << fixed;
	while(1){
		int a; in >> a;
		if (a == 0) break;

		arr.clear();

		double sum = 0;
		for (int i = 0; i < a; i++) {
			double b; in >> b;
			sum += b * 100;
			arr.push_back(b * 100);
		}

		int r = (int)sum / a; //목
		int m_r = (int)sum % a; // 더내야할 사람 목록


		sort(arr.begin(), arr.end());

		vector<int> arr2;
		for (int i = 0; i < a - m_r; i++) {
			arr2.push_back(r);
		}

		for (int i = 0; i < m_r; i++) {
			arr2.push_back(r + 1);
		}

		double ret = 0;
		for (int i = 0; i < a; i++) {

			if (arr[i] > arr2[i]) {
				ret += arr[i] - arr2[i];
			}
		}

		out.precision(2);
		out << "$" <<  ret/100 <<"\n";
	}

	


	
	return 0;
}