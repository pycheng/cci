#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
        int v;
        node *left, *right;
        node(int i): v(i), left(NULL), right(NULL) {}
        ~node() {}
};
void dump_vec(vector<vector<int>> res){
    for(auto i:res){
        for(auto j:i)
            cout << j << ",";
        cout << "\n";
    }
}
//recursive with 
//      base case left.size()==0 || right.size()==0
//      <out> void
void weave(vector<int> left, vector<int> right, vector<vector<int>> &res, vector<int> prefix)
{
    if(left.size() == 0 || right.size() == 0){
        prefix.insert(prefix.end(), left.begin(),  left.end());
        prefix.insert(prefix.end(), right.begin(), right.end());
        res.push_back(prefix);
        return;
    }

    //move left.begin to prefix.end and recursion
    prefix.push_back(*left.begin());
    left.erase(left.begin());
    weave(left, right, res, prefix);
    left.insert(left.begin(), *(prefix.end()-1));
    prefix.erase(prefix.end()-1);

   //move right.begin to prefix.end and recursion
    prefix.push_back(*right.begin());
    right.erase(right.begin());
    weave(left, right, res, prefix);
    right.insert(right.begin(), *prefix.end());
    prefix.erase(prefix.end());
}
//recursive with 
//      base case <in> root == NULL
//      <out> sequence
vector<vector<int>> bst_seq(node *r){
    if(r==NULL){
        //note we must have res.size()!=0
        return *(new vector<vector<int>>(1, vector<int>(0)));
    }
    vector<int> prefix = {r->v};
    vector<vector<int>> result;

    vector<vector<int>> left  = bst_seq(r->left);
    vector<vector<int>> right = bst_seq(r->right);
   
    //if res.size() == 0, result won't perform
    for(auto i: left){
        for(auto j:right){
            weave(i, j, result, prefix);
        }
    }

    return result;
}
int main(){
    node *n, *t;
    t = n = new node(3);
    n->left = new node(1);
    n->right = new node(5);

    vector<vector<int>> res = bst_seq(t);

    dump_vec(res);
    return 0;
}
