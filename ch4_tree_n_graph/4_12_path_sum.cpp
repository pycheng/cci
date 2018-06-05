#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

class node{
    public:
        int v;
        node *left, *right;
        node(int i): v(i), left(NULL), right(NULL) {}
        ~node() {}
};
// recursion 
//      base case: r == NULL
//      return: no of path
//      intermediate data: hash<running sum, count>
//              10,  5,  3,  3,  2 
// runningsum   10, 15, 18, 21, 23
// rsum-tsum     2,  7, 10, 13, 15
//target = 8
int path_sum_helper(node *r, int target, int rsum, unordered_map<int, int> &rsum_hash){
    int res_cnt = 0;

    if(r==NULL) return 0;
    rsum += r->v;
    if(rsum == target) res_cnt++;

    if(rsum_hash.count(rsum-target)>0){
        res_cnt += rsum_hash.count(rsum-target);
    }

    rsum_hash[rsum]+=1;
    res_cnt += path_sum_helper(r->left, target, rsum, rsum_hash);
    res_cnt += path_sum_helper(r->right,target, rsum, rsum_hash);
    rsum_hash[rsum]-=1;

    return res_cnt;
}

int path_sum(node *r, int target){
    unordered_map<int, int> rsum_hash;
    return path_sum_helper(r, target, 0, rsum_hash);
}

int main(){
    node *n, *t;
    t = n = new node(10);
    n->left  = new node(5);
    n->right = new node(-3);
    n = n->left;
    n->left  = new node(3);
    n->right = new node(1);
    n = n->left;
    n->left  = new node(3);
    n->right = new node(-2);
    n = t->left->right;
    n->right = new node(2);
    n = t->right;
    n->right = new node(11);

    cout << path_sum(t, 8);
    return 0;
}
