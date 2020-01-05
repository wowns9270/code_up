#include<bits/stdc++.h>
using namespace std;
int n;
int inorder[100001];
int postorder[100001];
int position[100001];
void gogo(int in_lo, int in_hi, int po_lo, int po_hi) {
	if (in_lo > in_hi || po_lo > po_hi) return;

	int root = postorder[po_hi];
	cout << root << " ";
	int idx = position[root];

	int left = idx - in_lo;

	gogo(in_lo, idx - 1, po_lo, po_lo + left - 1);
	gogo(idx + 1, in_hi, po_lo + left, po_hi - 1);

}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> inorder[i];
	for (int i = 0; i < n; i++) cin >> postorder[i];

	for (int i = 0; i < n; i++) {
		position[inorder[i]] = i;
	}
	gogo(0, n - 1, 0, n - 1);
}