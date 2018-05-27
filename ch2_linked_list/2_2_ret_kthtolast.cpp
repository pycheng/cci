#include <iostream>
using namespace std;


class node{
    public:
        int v;
        class node * nxt;
        node(int i){v=i;nxt=NULL;}
        ~node(){ cout<<"del node:"<<v<<"\n";}
};

void cll(node *h){
    node *n, *cur;
    cur = h;
    for(int i = 1; i<20; i++){
        n = new node(i);
        cur->nxt = n;
        cur=n;
    }
}

//node *ktl_helper(node *n, int k, int &

node *ktolast_helper(node *n, int k, int &tolast){
    node * res;

    if(n==NULL) {
        tolast = 0;
        return NULL;
    }
    res = ktolast_helper(n->nxt, k, tolast);
    tolast++;
    if(tolast==k){
        res=n;
    }

    return res;
}

node *ktolast(node *n, int k){
    int i = 0;
    return ktolast_helper(n, k, i);
}

int main(){
    node *ll = new node(0);
    node *a;
    cll(ll);
    a = ktolast(ll, 5);
    cout << a->v;
}
