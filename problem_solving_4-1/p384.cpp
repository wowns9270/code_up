//slimp  slump slurfy
#include<bits/stdc++.h>
using namespace std;

ifstream in("p384.inp");
ofstream out("p384.out");
int n;

string a;
int slump(int idx ) {

	if ( (a[idx] != 'E' && a[idx] != 'D') || idx > a.size()-1) {
		return -1;
	}

	idx++;
	if (a[idx] != 'F') return -1;

	while (a[idx] == 'F') {
		idx++;
	}

	if (a[idx] == 'G') {
		return idx;
	}
	return slump(idx); 
}

int slimp(int idx ) {
	
	if (a[idx] != 'A') return -1;
	idx++;

	if (a[idx] == 'H') {
		return idx;
	}
	else if (a[idx] == 'B') {
		int r = slimp(idx + 1);
		if (r != -1 && a[r + 1] == 'C') {
			return r + 1;
		}
		else return -1;
	}
	else {
		int r = slump(idx);
		if (r != -1 && a[r + 1] == 'C') {
			return r + 1;
		}
		else return -1;
	}
}


int gogo(int idx) {

	if (a[idx] != 'A') {
		return -1;
	}

	int k = slimp(idx); // slimp 시작

	if (k == -1) {
		return -1;
	}

	int k2 = slump(k+1); // slimp 로 반환된 곳부터 slump

	if (k2 == -1 || k2 != a.size()-1) {
		return -1;
	}
	
	return 1;

}

int main() {
	in >> n;
	out << "SLURPYS OUTPUT\n";
	while (n--) {
		in >> a;

		int r = gogo(0);

		if (r == 1) out << "YES\n";
		else {
			out << "NO\n";
		}
	}
	out << "END OF OUTPUT\n";

}