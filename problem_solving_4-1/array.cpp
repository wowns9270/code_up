#include<bits/stdc++.h>
#define INF 1000000007
#define inf2 -9999999999
using namespace std;

ifstream in("array.inp");
ofstream out("array.out");
long long n, m;
vector<long long> arr;

class Node {
public:
	long long num;
	long long idx;
	long long size;
	Node* left;
	Node* right;
	Node* parent;

	Node() {
		num = inf2;
		parent = nullptr;
		left = right = NULL;
	}

	Node(long long val , long long idx) : num(val ) , idx(idx) {
		parent = NULL;
	}
};

class RBTree {

	Node* root;
	Node* leaf;

public:

	RBTree() {
		leaf = new Node();
		root = leaf;
	}

	Node* search_node(long long n) {
		Node* x = root;
		Node* temp = NULL;

		while (x != leaf) {
			temp = x;
			if (x->num == n) {
				break;
			}
			if (n < x->num) {
				x = x->left;
			}
			else {
				x = x->right;
			}
		}
		return temp;
	}


	void insert(long long n, long long  idx) {
		Node* temp = new Node(n , idx);
		temp->left = leaf;
		temp->right = leaf;
		temp->size = 1;


		Node* y = search_node(n);
		Node* temp1 = y;

		temp->parent = y;

		if (y == NULL) { root = temp; }
		else if (n < y->num) { y->left = temp; }
		else y->right = temp;


		while (temp1 != NULL) {
			temp1->size += 1;
			temp1= temp1->parent;
		}

	}

	void leftRotate(Node* x) {
		Node* y = x->right;
		x->right = y->left;

		if (x->right != leaf)x->right->parent = x;
		y->parent = x->parent;

		if (x->parent == NULL) root = y;
		else if (x == x->parent->left) x->parent->left = y;
		else    x->parent->right = y;

		y->left = x;
		x->parent = y;
	}

	void rightRotate(Node* x) {
		Node* y = x->left;
		x->left = y->right;

		if (y->right != leaf) y->right->parent = x;
		y->parent = x->parent;

		if (y->parent == NULL) root = y;
		else if (x == x->parent->left) x->parent->left = y;
		else x->parent->right = y;

		y->right = x;
		x->parent = y;
	}

	Node* successor(Node* p) {
		p = p->right;
		while (p->left != leaf) {
			p = p->left;
		}
		return p;
	}
	
	void deletee(long long k) {

		Node* z = search_node(k);
		Node* temp = z;
		Node* x;
		Node* y = z;
		Node* node = root;

		while (temp != NULL) {
			temp->size -= 1;
			temp = temp->parent;
		}


		if (z->left == leaf && z->right == leaf) {

			if (z == root) root = leaf, x = root;
			else {
				if (z == z->parent->left) z->parent->left = leaf, x = z->parent->left;
				else z->parent->right = leaf, x = z->parent->right;
				x->parent = z->parent;
			}
		}
		else if (z->left == leaf) {
			x = z->right;

			if (z->parent == NULL) { root = z->right; }
			else if (z == z->parent->right) { z->parent->right = z->right; }
			else z->parent->left = z->right;

			z->right->parent = z->parent;

		}
		else if (z->right == leaf) {
			x = z->left;

			if (z->parent == NULL) { root = z->left; }
			else if (z == z->parent->right) { z->parent->right = z->left; }
			else z->parent->left = z->left;

			z->left->parent = z->parent;


		}
		else {
			y = successor(z);
			x = y->right;

			y->size = z->size;

			Node* qq = y ->parent;

			while (qq != z) {
				qq->size -= 1;

				qq = qq->parent;
			}



			if (y->parent == z) x->parent = y;
			else {

				if (y == y->parent->right) { y->parent->right = x; }
				else {
					y->parent->left = x;
				}
				x->parent = y->parent;

				y->right = z->right;
				y->right->parent = y;
			}

			if (z->parent == NULL) root = y;
			else if (z == z->parent->right) z->parent->right = y;
			else z->parent->left = y;

			y->parent = z->parent;


			y->left = z->left;
			y->left->parent = y;
		}







	}

	void gogo() {
		size_update(root);
	}
	
	long long  size_update(Node* p) {


		if (p == NULL || p->num == inf2) {
			return 0;
		}

		long long r1 = size_update(p->left);
		long long r2 = size_update(p->right);

		p->size = r1 + r2 + 1;

		return p->size;
	}

	long long gogo2(long long k ) {

		Node* node = root;

		while (1) {

			long long r = 0;

			if (node->left == NULL || node->left->num == inf2) {
				r = 0;
			}
			else {
				r = node->left->size;
			}

			if (k > r + 1) {

				k -= r + 1;
				node = node->right;
			}
			else if (k == r + 1) {
				return node->idx;
			}
			else {
				node = node->left;
			}



			
		}
	}

	long long gogo3(long long k) {

		Node* node = root;
		long long ans = 0;
		

		while (1) {

			if (node == NULL || node->num ==inf2) break;

			if (node->num < k) {
				
				if (node->left == NULL || node->left->num == inf2) {
					ans += 1;
				}
				else
				ans += node->left->size + 1;

				node = node->right;
			}
			else if (node->num > k) {
				node = node->left;
			}
			else {

				ans += node->left->size;

				return ans;
			}


		}
		return ans;
	}

	long long gogo4(long long r) {

		Node* z = search_node(r);
		return z->idx;

	}



};

int main() {

	in >> n >> m;
	RBTree tree;

	for (int i = 0; i < n; i++) {
		long long a; in >> a;


		tree.insert(a, i);
		arr.push_back(a);
	}


	
	long long ret = 0;
	while (m--) {

		char a; in >> a;

		if (a == 'c') { //특정 위치값을 지정한것으로 바꿈

			long long b, c; in >> b >> c;
			long long r = arr[b];
			arr[b] = c;

			tree.deletee(r);
			tree.insert(c, b);
		}
		else if (a == 'w') { //k번째 작은 값이 저장된 인덱스 출력
			long long k; in >> k;

			long long r = tree.gogo2(k);
			//cout << tree.gogo2(k) << "\n";
			ret += r;
			ret %= INF;
		}
		else if (a == 'a') { //보다 작은값의 개수
			long long v; in >> v;

			long long r = tree.gogo3(v);

			//cout << tree.gogo3(v) << "\n";
			ret += r;
			ret %= INF;
		}
		else { // f 가 저장된 위치의 인덱스 출력
			long long f; in >> f;

			long long r = tree.gogo4(f);
			//cout << tree.gogo4(f) << "\n";

			ret += r;
			ret %= INF;
		}
	}

	out << ret;
	return 0;

}