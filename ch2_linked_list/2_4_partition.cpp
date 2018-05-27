#include <iostream>
using namespace std;

class node{
    public:
        int v;
        class node *nxt;
        node(int i){ v=i; nxt=NULL; }
};

void partition(node* h, int x){
    node *cur = h;
    node *lt_h  = NULL, *lt_t = NULL;
    node *ge_h  = NULL, *ge_t = NULL;

    while(cur!=NULL){
        if(cur->v >= x){
            if(ge_h==NULL){
                ge_h = cur;
                ge_t = cur;
                cur  = cur->nxt;
                ge_h->nxt = NULL;
            }else{
                ge_t->nxt = cur;
                cur = cur->nxt;
                ge_t = ge_t->nxt;
                ge_t->nxt = NULL;
            }
        }else if(cur->v < x){ //v<x
            if(lt_h==NULL){
                lt_h = cur;
                lt_t = cur;
                cur  = cur->nxt;
                lt_h->nxt = NULL;
            }else{
                lt_t->nxt = cur;
                cur = cur->nxt;
                lt_t = lt_t->nxt;
                lt_t->nxt = NULL;
            }
        }
    }
    //mrege the list lt, ge
    lt_t->nxt = ge_h;
    h = lt_h;
}

int main(){
    node *ll;
    node *n;
    
    n=new node(3);
    ll = n;
    n->nxt=new node(5);
    n=n->nxt;
    n->nxt=new node(8);
    n=n->nxt;
    n->nxt=new node(5);
    n=n->nxt;
    n->nxt=new node(10);
    n=n->nxt;
    n->nxt=new node(2);
    n=n->nxt;
    n->nxt=new node(1);
    n=n->nxt;

    n = ll;
    while(ll!=NULL){
        cout << ll->v  << ",";
        ll= ll->nxt;
    }
    cout << "\n";
    ll= n;

    partition(ll, 5);

    while(ll!=NULL){
        cout << ll->v  << ",";
        ll= ll->nxt;
    }
}


