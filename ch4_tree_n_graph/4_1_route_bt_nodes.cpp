#include <iostream>
#include <vector>
#include <queue>
using namespace std;

enum N_VISIT{
    NOTVISIT = 0,
    VISITING = 1,
    VISITED  = 2,
};
class node{
    public:
        int v;
        int visited;
        vector<node *> nbr;
        node(int i): v(i),visited(NOTVISIT){}
};
class graph{
    public:
        vector<node *> n;
        ~graph(){
            cout << "dcon\n" ;
            for(auto i:n) delete i;
        }
};


bool isapath(node *a, node *b){
    queue<node *> q;
    q.push(a);

    while(!q.empty()){
        node *n = q.front(); q.pop();
        n->visited = VISITED;
        for(auto i: n->nbr){
            if(i->visited == NOTVISIT){
                i->visited = VISITING;
                q.push(i);
            }
        }
    }

    return (b->visited==VISITED);
}



void init_graph(graph &g){
    g.n.resize(6);
    g.n[0] = new node(0);
    g.n[1] = new node(1);
    g.n[2] = new node(2);
    g.n[3] = new node(3);
    g.n[4] = new node(4);
    g.n[5] = new node(5);

    g.n[0]->nbr.push_back(g.n[1]);
    g.n[0]->nbr.push_back(g.n[5]);
    g.n[0]->nbr.push_back(g.n[4]);
    g.n[1]->nbr.push_back(g.n[4]);
    g.n[1]->nbr.push_back(g.n[3]);
    g.n[2]->nbr.push_back(g.n[1]);
    g.n[3]->nbr.push_back(g.n[2]);
    g.n[3]->nbr.push_back(g.n[4]);
}


int main(){
    graph g;
    init_graph(g);
    cout << isapath(g.n[0], g.n[3])  << "\n";
    graph g1;
    init_graph(g1);
    cout << isapath(g1.n[3], g1.n[0])  << "\n";
}
