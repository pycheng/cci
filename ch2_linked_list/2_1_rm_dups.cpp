#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class node{
    public: 
        int v;
        class node *next;

        node(int i){
            v=i;
            next=NULL;
        };

        ~node(){
            cout << "del node:" << v << "\n";
        }
};

void clist(node *n){
    node *cur=n;
    node *m = new node(3);
    cur->next = m;
    cur = m;
    m = new node(3);
    cur->next = m;
    cur = m;
    m = new node(5);
    cur->next = m;
    cur = m;
    m = new node(3);
    cur->next = m;
    cur = m;
    m = new node(3);
    cur->next = m;
    cur = m;
}


void rmdup(node *h){
    node* cur = h;
    node* prv = NULL;
    unordered_map<int,int> hash;

    while(cur!=NULL){
        if(hash.count(cur->v) > 0){
            //remove from list
            prv->next = cur->next;
            delete cur;
            cur = prv->next;
        }else{
            hash[cur->v]++;
            prv = cur;
            cur = cur->next;
        }
    }
}



int main(){
    node *ll = new node(0);

    //create list (0,3,3,5,3,3);
    clist(ll);
    rmdup(ll);

    node *c=ll;
    while(c!=NULL){
        cout << c->v << ",";
        c=c->next;
    }
}



