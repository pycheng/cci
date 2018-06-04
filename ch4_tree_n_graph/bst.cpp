#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node{
    public:
        int v;
        node *left, *right, *parent;
        node(int x): v(x), left(NULL), right(NULL), parent(NULL){}
        node(int x, node* p): v(x), left(NULL), right(NULL), parent(p){}
        ~node(){}
};

class bst{
    public:
        node *root;
        bst():root(NULL) {}
        /* ins, del, find */
        void ins(int key){
            cout << "add: " << key << "\n";
            if(!root){
                root = new node(key);
                return;
            }
            /* search all the way until the position == null */ 
            node *cur = root;
            node *pre = NULL;
            while(cur != NULL){
                pre = cur;
                cur = (key<=cur->v)?cur->left:cur->right;
            }
            if(key <= pre->v){ 
                pre->left = new node(key, pre);
            }else{
                pre->right = new node(key, pre);
            }
            return;
        }
        node *find(int key){
            node *n = root;
            while(n!=NULL && n->v!=key){
                n = (key<=n->v)?n->left:n->right;
            }
            return n;
        }
        void del_n(node *n){
            if(n==NULL) return;
            //case 1: n has no child. delete directly;
            if(n->left == NULL && n->right == NULL){
                if(n->parent->left == n){
                    n->parent->left = NULL;
                }else{
                    n->parent->right = NULL;
                }
                delete n;
                return;
            }

            //case 2: n has 1  child. connect the child to parent;
            if(n->left == NULL|| n->right == NULL){
                node* child = (n->left==NULL)? n->right: n->left;
                if(n->parent->left == n){
                    n->parent->left = child;
                    child->parent = n->parent;
                }else{
                    n->parent->right = child;
                    child->parent = n->parent;
                }
                delete n;
                return;
            }
            //case 3: n has 2  child. connect the successor to parent;
            // the successor is the min value of the right tree
            node* succ = n->right;
            while(succ->left!=NULL){
                succ = succ->left;
            }
            n->v = succ->v;
            //connect succ->right;
            if(succ == n->right){
                n->right = succ->right;
                if(succ->right) succ->right->parent = n;
            }else{
                succ->parent->left = succ->right;
                if(succ->left) succ->right->parent = succ->parent;
            }
             delete succ;
        } 

        //delete by key
        void del(int key){            
            cout << "del: " << key << "\n";
            return del_n(find(key));
        }

        void dump(){
            int level = 0;
            queue<pair<node *, int>> q;
           
            cout << "\n";
            q.push(make_pair(root, level));
            while(!q.empty()){
                int q_level = q.front().second;
                node *n = q.front().first;
                q.pop();

                if(q_level != level){ 
                    cout << "\n";
                    level = q_level;
                }
                if(n==NULL) cout << "n, ";
                else cout << n->v << ", ";
               
                if(n){
                    q.push(make_pair(n->left, level+1));
                    q.push(make_pair(n->right, level+1));
                }
            }
            cout <<"\n";
        }
};

void build_bst_helper(vector<int> n, bst &t, int s, int e)
{
    cout << s << "," << e <<"\n";
    int mid = (s+e)/2;
    if(s > e) return;
    t.ins(n[mid]);
    build_bst_helper(n, t, s, mid-1);
    build_bst_helper(n, t, mid+1, e);
}

void build_bst(vector<int> n, bst &t)
{
    build_bst_helper(n, t, 0, n.size()-1);
}

int main(){
    vector<int> num = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    bst t;
    build_bst(num, t);
    t.dump();
    t.del(12);
    t.dump();
    t.del(14);
    t.dump();
    t.del(15);
    t.dump();
}
