#include <memory.h>
using namespace std;
template <typename V>
class Tree {
private:
	struct Node {
		Node(V v, shared_ptr<Node>& l, shared_ptr<Node>Node& r) :
			value(v), left(l), right(r) {}
		V value;
		shared_ptr<Node>left;
		shared_ptr<Node>right;
	};
	explicit Tree(shared_ptr<Node>& node) : root(node) {}
	shared_ptr<Node> root;
public:
	Tree() {}
	Tree(Tree const& lft, V value, Tree const& rgt) :
		root(Node(val, lft->root, rgt->root)) {}
	bool Tree::isEmpty() const {
		return !root;
	}
	V Tree::root() const {
		return root->val;
	}
	Tree& Tree::left() const {
		return Tree(root->left);
	};
	Tree& Tree::right() const {
		return Tree(root-> right);
	}
	bool Tree::member(V x)const {
		if (isEmpty())
			return false;
		V y = root();
		if (x < y)
			return left().member(x);
		else if (y < x)
			return right().member(x);
		else
			return true;
	}
};
