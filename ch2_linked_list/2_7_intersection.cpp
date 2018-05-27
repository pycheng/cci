#include <iostream>
using namespace std;

class node{
    public:
        int v;
        node *nxt;
        node(int i): v(i), nxt(NULL) {}
        ~node() {}
};

node* padding_zero(node *h, int n){
    for(int i=0; i<n; i++){
        node *p = new node(0);
        p->nxt = h;
        h = p;
    }
    return h;
}

node *intersection(node *l1, node *l2){
    int len_l1 = 0;
    int len_l2 = 0;
    node* pl1 = l1;
    node *pl2 = l2;

    while(pl1!=NULL && pl2!=NULL){
        if(pl1!=NULL){len_l1++; pl1=pl1->nxt;}
        if(pl2!=NULL){len_l2++; pl2=pl2->nxt;}
    }

    if(len_l1 > len_l2){ 
        padding_zero(l2, len_l1-len_l2);
    }else{
        padding_zero(l1, len_l2-len_l1);
    }

    for(int i = 0; i < max(len_l1, len_l2); i++){
        if(l1 == l2) { return l1; }
        l1 = l1->nxt;
        l2 = l2->nxt;
    }

    return NULL;
}


int main()
{
    node *l1, *l2, *n, *inter;
    n = new node(0);
    l1 = n;
    n->nxt = new node(1);
    n = n->nxt;
    n->nxt = new node(2);
    n = n->nxt;
    n->nxt = new node(3);
    n = n->nxt;
    inter = n;
    n->nxt = new node(4);
    n = n->nxt;

    n = new node(10);
    l2 = n;
    n->nxt = new node(11);
    n = n->nxt;
    n->nxt = new node(12);
    n = n->nxt;
    n->nxt = inter;

    n = intersection(l1, l2);

    cout << n->v;

    return 0;
}
