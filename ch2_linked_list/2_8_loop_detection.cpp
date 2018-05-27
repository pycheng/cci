#include <iostream>
using namespace std;


class node{
    public:
        int v;
        node *nxt;
        node (int i): v(i), nxt(NULL) {}
        ~node() {}
};

node *loop_dtc(node *cir){
    node *si = cir, *fi = cir;
    //for each step si++, fi+=2
    //k = # of node before start_loop
    //after move k step si reach start_loop: 
    //    si = k, fi = 2*k
    //    k = m*loopsize + n;  
    //    fi is (loopsize - n) behinde si

    //first collision point
    // si = k + loopsize -n = fi
    do{
        si= si->nxt;
        fi= fi->nxt->nxt;
        cout << "(" << si->v << "," << fi->v <<") , "<<flush;
    }while(si!=fi);

    cout << "\n";

    // move si ahead k step
    // si = k + loopsize - n = m'*loopsize
    // move ptr from head + k ==> 2nd collision point
    // 2nd collision point is the start of the loop
    fi = cir;

    while(si!=fi){
        si= si->nxt;
        fi= fi->nxt;
        cout << "(" << si->v << "," << fi->v <<") , "<<flush;
    }
    return si;
}

int main(){
    node* cir, *n, *inter;
    n = new node(0);
    cir = n;
    n->nxt = new node (1);
    n = n->nxt;
    n->nxt = new node (2);
    n = n->nxt;
    n->nxt = new node (3);
    n = n->nxt;
    n->nxt = new node (4);
    n = n->nxt;
    n->nxt = new node (5);
    n = n->nxt;
    inter = n;
    n->nxt = new node (6);
    n = n->nxt;
    n->nxt = new node (7);
    n = n->nxt;
    n->nxt = new node (8);
    n = n->nxt;
    n->nxt = inter;

    cout << loop_dtc(cir)->v;


    return 0;
}
