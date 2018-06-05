#include <iostream>
using namespace std;

class node{
    public:
        int v;
        node *left, *right;
        node(int i): v(i), left(NULL), right(NULL){}
        ~node() {}
};
// carry the ans parameter to identify the different of case 1 and case 4
node * ca_helper(node* r, node* p, node* q, bool &ans){
    ans = false;
    //base cases
    if(r == NULL){ return r; }
    if(r == p && r == q){
        ans = true;
        return r;
    }
    
    //recursively trace left and right subtree
    bool l_ans = false;
    node* l_n = ca_helper(r->left, p, q, l_ans);

    bool r_ans = false;
    node* r_n = ca_helper(r->right, p, q, r_ans);

    if(l_ans == true || r_ans == true){
        //case 1 answer is found in sub tree
        ans = true;
        return (l_ans)?l_n:r_n;
    }else if(l_n != NULL && r_n != NULL){
        //case 2 left/right subtree contains different node
        ans = true;
        return r;
    }else if(r == p || r == q){
        //case 3 found one node as root
        //checking if the other node is found at sub-tree
        ans = (l_n!=NULL || r_n!=NULL);
        return r;
    }else{
        //case 4 return the node found in subtree if any
        ans = false;
        return (l_n)?l_n:r_n;
    }
}

node * common_ancestor(node* r, node* p, node* q){
    bool res = false;
    node * n = ca_helper(r, p, q, res);
    return (res == true)?n:NULL;
}

int main(){
    node *n; 
    node *t1;
    node *n0, *n1, *n2, *n3, *n4, *n5, *n6;
    n0 = t1 = n = new node(10);
    n1 = n->left  = new node(1);
    n2 = n->right = new node(2);
    n=n->left;
    n3 = n->left  = new node(3);
    n4 = n->right = new node(4);
    n=n->right;
    n5 = n->right = new node(5);
    n=t1->right;
    n6 = n->right = new node(6);
    n = new node(23);
    cout << common_ancestor(t1, n3, n5)->v << "\n"; //1
    cout << common_ancestor(t1, n1, n5)->v << "\n"; //1
    cout << common_ancestor(t1, n6, n3)->v << "\n"; //10
    cout << common_ancestor(t1, n1, n) << "\n";
}
