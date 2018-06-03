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

vector<vector<node *>> lod_helper(node *r, int level)
{
    vector<vector<node*>> res;
    vector<node *> *cur = new vector<node *>;
    vector<node *> *next = cur;
    cur->push_back(r);
    res.push_back(*cur);

    while(cur->size()!=0){
        next = new vector<node *>;
        for(auto i:*cur){
            if(i->left) next->push_back(i->left);
            if(i->right) next->push_back(i->right);
        }
        cur = next;
        if(cur->size()!=0) res.push_back(*cur);
    }
    
    return res;
}
vector<vector<node *>> list_of_depth(node *r)
{
    return lod_helper(r, 0);

}

int main(){
    vector<int> t0 = {1,2,3,4,5,6,7,8,9,55};
    node *r = create_min_bst(t0);
    vector<vector<node*>> l = list_of_depth(r);
    for(auto i:l){
        for(auto j:i){
            cout << j->v << ",";
        }
        cout << "\n";
    }
}
