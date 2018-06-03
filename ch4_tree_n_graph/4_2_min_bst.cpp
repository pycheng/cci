#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
    public:
        int v;
        node *left, *right;
        node(int i): v(i), left(NULL), right(NULL) {}
        ~node(){};
};
node * create_min_bst_helper(vector<int> arr, int start, int end)
{
    int mid = (start+end)/2;
    if(start > end) return NULL;

    node *n = new node(arr[mid]);
    n->left = create_min_bst_helper(arr, start, mid-1);
    n->right = create_min_bst_helper(arr, mid+1, end);

    return n;
}
node * create_min_bst(vector<int> arr)
{
    return create_min_bst_helper(arr, 0, arr.size()-1);
}

string sep = "";
void bfs(node *n)
{
    queue<node *> q;

    q.push(n);
    while(!q.empty()){
        node *n1 = q.front(); q.pop();
        if(n1 == NULL){
            cout << sep << "NULL"; sep = ",";
        }else{
            cout << sep << n1->v; sep = ",";
            q.push(n1->left); q.push(n1->right);
        }
    }

}

int main(){
    vector<int> t0 = {1,2,3,4,5,6,7,8,9,55};
    node *r = create_min_bst(t0);
    bfs(r);
}
