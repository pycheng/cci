#include <iostream>
using namespace std;


class node{
    public:
        int v;
        node *left, *right;
        node(int i):v(i), left(NULL), right(NULL){}
        ~node(){}
};

string n_to_str(node* r)
{
    return (!r)?"N":to_string(r->v);
}

//recusive function
//  base: r == NULL
string bt_to_str(node* r)
{
    string res = n_to_str(r); 

    if(r == NULL){
        return res;
    }

    res += bt_to_str(r->left);
    res += bt_to_str(r->right);

    return res;
}

bool subtree(node* t1, node* t2)
{
    string st1 = bt_to_str(t1);
    string st2 = bt_to_str(t2);

    cout<< "comparing:\n" << st1 << "\n" << st2 << "\n";
    cout<< "output: " << st1.find(st2) << "\n";
    return (st1.find(st2)!=string::npos);
}

//recusive function
//  base: t1 == NULL || t2 == NULL
//  base: t1->v != t2->v
bool tree_match(node *t1, node *t2)
{
    if(t1 == NULL || t2 == NULL){
        return (t1 == NULL && t2 ==NULL);
    }else if(t1->v!=t2->v){ 
        return false;
    }else{
        return tree_match(t1->left, t2->left) && tree_match(t1->right, t2->right);
    }
}

//recusive function
//  base: t1 == NULL
bool st_hlpr(node *t1, node *t2)
{
    //return false: if t1 goes to the leaf->child 
    if(t1 == NULL) return false;
    
    //return true: if t1->v == t2->v and tree match
    if(t1->v == t2->v){
        if (true == tree_match(t1, t2)){
            return true;
        }
    }
    
    //recurisvely find the sub tree
    return (st_hlpr(t1->left, t2) || st_hlpr(t1->right, t2));
}

bool subtree_npkm(node *t1, node*t2)
{
    //t2 == NULL is always a sub tree
    if(t2 == NULL) return true;
    return st_hlpr(t1,t2);
}


int main(){
    node *n, *t1, *t2;
    t1 = t2 = NULL;
    cout << subtree(t1,t2) << "\n"; //true
    cout << subtree_npkm(t1,t2) << "\n"; //true

    t1 = n = new node(4);
    n->left = new node(2);
    n->right = new node(7);
    n = n->left;
    n->left = new node(1);
    n->right = new node(3);
    n = n->left;
    n->left = new node(0);
    t2 = n = t1->right;
    n->left = new node(6);
    n->right = new node(8);
    n = n->left;
    n->left = new node(5);

    cout << subtree(t1,t2) << "\n"; //true
    cout << subtree_npkm(t1,t2) << "\n"; //true

    t2 = n = new node(4);
    n->left = new node(2);

    cout << subtree(t1,t2) << "\n"; //false
    cout << subtree_npkm(t1,t2) << "\n"; //false
    

    return 0;
}
