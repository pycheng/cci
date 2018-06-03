#include <iostream>
#include <vector>
#include <limits.h>
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

#define NOT_BALANCE INT_MIN

int check_height(node *r){
    int h_l, h_r;

    if(r == NULL) return 0;

    h_l = check_height(r->left);
    if(h_l == NOT_BALANCE) return h_l;
    h_r = check_height(r->right);
    if(h_r == NOT_BALANCE) return h_r;

    if(abs(h_l - h_r) <= 1) return max(h_l, h_r)+1;
    else return NOT_BALANCE;
    
}

bool check_balanced(node * r){
    return (check_height(r) != NOT_BALANCE)?true:false;
}


int main(){
    vector<int> t0 = {1,2,3,4,5,6,7,8,9,55};
    node *r = create_min_bst(t0);
    cout << check_balanced(r);
}
