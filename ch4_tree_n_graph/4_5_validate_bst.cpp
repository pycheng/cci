#include <iostream>
using namespace std;

class node{
    public:
        int v;
        node *left, *right;
        node(int x): v(x), left(NULL), right(NULL) {}
        ~node(){cout << "del: " << v << "\n";}
};


bool is_bst(node *r){

    if(r== NULL) return true;

    if(r->left && r->left->v > r->v) return false;
    if(r->right && r->right->v <= r->v) return false;

    return is_bst(r->left)&&is_bst(r->right);
}


int main(){
    node *n;
    node *t1, *t2;

    n = new node(4);
    t1 = n;
    n->left = new node(3);
    n->right = new node(6);
    n->left->left = new node(1);
    n->right->left = new node(5);
    n->right->right = new node(9);

    n = new node(4);
    t2 = n;
    n->left = new node(3);
    n->right = new node(6);
    n->left->left = new node(1);
    n->right->left = new node(5);
    n->right->right = new node(4);

    cout << is_bst(t1) << "," << is_bst(t2);
}
