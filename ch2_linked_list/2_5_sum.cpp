#include <iostream>
#include <stack>
using namespace std;

class node{
    public:
        int v;
        class node *nxt;
        node(int i){ v=i; nxt=NULL; cout << "new:" << v << "\n";}
};

node *suml(node *l1, node*l2){
    node * res = NULL;
    node * res_t = NULL;
    int sum=0;
    while(l1!=NULL || l2!=NULL){
        sum += (l1!=NULL)?l1->v:0;
        sum += (l2!=NULL)?l2->v:0;
        node *cur = new node(sum%10);
        if(res == NULL){ 
            res = res_t = cur;
        }else{
            res_t->nxt = cur;
            res_t = res_t->nxt;
        }
        sum /=10;

        if(l1!=NULL)l1=l1->nxt;
        if(l2!=NULL)l2=l2->nxt;
    }
    
    if(sum!=0){ res_t->nxt = new node(sum%10); }

    return res;
}

node * sumlinv(node * l1, node *l2){
    stack<int> s1, s2;

    while(l1!=NULL || l2!=NULL){
        if(l1!=NULL){
            s1.push(l1->v);
            l1= l1->nxt;
        }
        if(l2!=NULL){
            s2.push(l2->v);
            l2= l2->nxt;
        }
    }

    int sum = 0;
    node* res = NULL;
    node* res_t = NULL;
    while(!s1.empty()||!s2.empty()){
        if(!s1.empty()){
            sum += s1.top(); 
            s1.pop(); 
        }
        if(!s2.empty()){
            sum += s2.top(); 
            s2.pop(); 
        }

        node *n = new node(sum%10);
        sum /= 10;
        
        if(res_t == NULL){
            res_t=n;
        }else{
            n->nxt=res_t;
            res_t = n;
        }
    }
    if(sum!=0){
        res = new node(sum%10);
        res->nxt = res_t;
    }else{
        res=res_t;
    }

    return res;
}


int main(){
    node *l1, *l2;
    node *n;
    n = new node(7);
    l1 = n;
    n->nxt = new node(1);
    n = n->nxt;
    n->nxt = new node(7);
    n = n->nxt;
    n->nxt = new node(1);

    n = new node(5);
    l2 = n;
    n->nxt = new node(9);
    n = n->nxt;
    n->nxt = new node(2);

    cout << "\n\n";

    n = suml(l1, l2);
    
    while(n!=NULL){
        cout << n->v << "\n";
        n=n->nxt;
    }
    cout << "\n";

    n = sumlinv(l1, l2);
    
    while(n!=NULL){
        cout << n->v << "\n";
        n=n->nxt;
    }
    cout << "\n";
}
