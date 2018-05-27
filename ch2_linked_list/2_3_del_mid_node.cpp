#include <iostream>
#include <string>
using namespace std;

class node{
    public:
        char c;
        class node* nxt;
        node (char i) {c=i; nxt=NULL;}
        ~node(){}
};

void del_mid_node(node* h, char c){
    node* cur = h;
    node* prv = NULL;
    
    if(h->c == c) return;

    while(cur !=NULL){
        if(cur->c == c){
            prv->nxt = cur->nxt;
            cur = prv->nxt;
        }else{
            prv = cur;
            cur = cur->nxt;
        }
    }

}

int main(){
    node * ll = new node('a');
    node * n = new node('b');
    ll->nxt = n;
    n->nxt = new node('c');
    n = n->nxt;
    n->nxt = new node('c');
    n = n->nxt;
    n->nxt = new node('d');
    n = n->nxt;
    n->nxt = new node('e');
    n = n->nxt;
    n->nxt = new node('f');
    n = n->nxt;
    n->nxt = new node('c');
    n = n->nxt;

    n = ll;
    while(ll!=NULL){
        cout << ll->c << ",";
        ll=ll->nxt;
    }
    cout << "\n";
    ll = n;
    del_mid_node(ll, 'c');

    while(ll!=NULL){
        cout << ll->c << ",";
        ll=ll->nxt;
    }

    return 0;
}

