#include<bits/stdc++.h>
using namespace std;

ifstream in("rbt.inp");
ofstream out("rbt.out");

//킹갓 제너럴 박대이 소스참고

class Node {
public:
	int num;
	char color;
	Node* left;
	Node* right; 
	Node* parent;

	Node() {
		num = -1;
		color = 'b';
		parent = nullptr;
		left = right = NULL;
	}

	Node(int val) : num(val) {
		color = 'r';
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

	Node* search_node(int n) {
		Node* x = root;
		Node* temp= NULL;

		while (x != leaf) {
			temp = x;
			if (x->num == n) {
				break;
			}
			if( n < x->num) {
				x = x->left;
			}
			else {
				x = x->right;
			}
		}
		return temp;
	}


	void insert(int n) {
		Node* temp = new Node(n);
		temp->left = leaf;
		temp->right = leaf;
		

		Node* y = search_node(n);
		temp->parent = y;

		if (y == NULL) { temp->color = 'b', root = temp; }
		else if (n < y->num) { y->left = temp; }
		else y->right = temp;
	
		in_fix(temp);
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

	//x�� ����
	void in_fix(Node* x) {

		if (x->color == 'b') return;

		Node* y;
		while (x != root && x->parent->color == 'r') {
			if (x->parent == x->parent->parent->right) {
				y = x->parent->parent->left;
				if (y->color == 'r') {
					y->color = 'b';
					x->parent->color = 'b';
					x->parent->parent->color = 'r';
					x = x->parent->parent;
				}
				else {
					if (x == x->parent->left) {
						x = x->parent;
						rightRotate(x);
					}
					x->parent->color = 'b';
					x->parent->parent->color = 'r';
					leftRotate(x->parent->parent);
				}
			}
			else {
				y = x->parent->parent->right;

				if (y->color == 'r') {
					y->color = 'b';
					x->parent->color = 'b';
					x->parent->parent->color = 'r';
					x = x->parent->parent;
				}
				else {
					if (x == x->parent->right) {
						x = x->parent;
						leftRotate(x);
					}
					x->parent->color = 'b';
					x->parent->parent->color = 'r';
					rightRotate(x->parent->parent);
				}
			}
		}
		root->color = 'b';
	}

	void de_fix(Node* p) {
		Node* uncle;
		while (p != root && p->color == 'b') {

			if (p == p->parent->left) {
				uncle = p->parent->right;
				if (uncle->color == 'r') {
					uncle->color = 'b';
					p->parent->color = 'r';
					leftRotate(p->parent);
					uncle = p->parent->right;
				}
				else {
					if ( (uncle->left->color == 'b') && (uncle->right->color == 'b')) {
						uncle->color = 'r';
						p = p->parent;
					}
					else {
						if (uncle->right->color == 'b') {
							uncle->left->color = 'b';
							uncle->color = 'r';
							rightRotate(uncle);
							uncle = p->parent->right;
						}

						uncle->color = p->parent->color;
						p->parent->color = 'b';
						uncle->right->color = 'b';
						leftRotate(p->parent);
						break;
					}
				}
			}
			else {
				uncle = p->parent->left;
				if (uncle->color == 'r') {
					uncle->color = 'b';
					p->parent->color = 'r';
					rightRotate(p->parent);
					uncle = p->parent->left;
				}
				else {
					if (( uncle->left->color == 'b') && ( uncle->right->color == 'b')) {
						uncle->color = 'r';
						p = p->parent;
					}
					else {
						if ( uncle->left->color == 'b') {
							uncle->right->color = 'b';
							uncle->color = 'r';
							leftRotate(uncle);
							uncle = p->parent->left;
						}

						uncle->color = p->parent->color;
						p->parent->color = 'b';
						uncle->left->color = 'b';
						rightRotate(p->parent);
						break;
					}
				}
			}
		}
		p->color = 'b';
	}

	void deletee(int k) {

		Node* z = search_node(k);
		Node* x;
		Node* y = z;
		Node* node = root;
		
		char replace = y->color;

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
			replace = y->color;
			x = y->right;
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
			y->color = z->color;
		}
		if (replace == 'b') de_fix(x);
	}
};

int main() {
	RBTree tree;
	while (1) {
		char a; int b;
		in >> a >> b;

		if (b == -1) break;
		if (a == 'i') {
			tree.insert(b);
		}
		else if (a == 'c') {
			Node* p = tree.search_node(b);
			if (p->color == 'r') {
				out << "color(" << p->num << "): RED\n";
			}
			else {
				out << "color(" << p->num << "): BLACK\n";
			}
		}
		else {
			tree.deletee(b);
		}
	}
	return 0;
}
