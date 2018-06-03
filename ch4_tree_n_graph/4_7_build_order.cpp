#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

struct node_data{
    int in_deg;
    vector<string> dependencies;
};

vector<string> build_order(vector<string> prjs, vector<pair<string, string>> in){
    unordered_map<string, struct node_data> prj_graph;
    vector<string> res;
    queue<string> q;
    
    for(auto i:prjs){
        prj_graph[i].in_deg = 0;
        prj_graph[i].dependencies.clear();
    }

    for(auto i:in){
        prj_graph[i.first].dependencies.push_back(i.second);
        prj_graph[i.second].in_deg++;
    }


    for(auto i:prj_graph){
        if(i.second.in_deg == 0){
            q.push(i.first);
            res.push_back(i.first);
        }
    }

    while(!q.empty()){
        string cur = q.front();
        q.pop();

        for(auto i:prj_graph[cur].dependencies){
            if((--prj_graph[i].in_deg) == 0){
                q.push(i);
                res.push_back(i);
            }
        }
    }

    if(res.size() != prjs.size())
        res.clear();

    return res;
}

int main(){
    vector<pair<string, string>> in;
    in.push_back(make_pair("a","d"));
    in.push_back(make_pair("f","b"));
    in.push_back(make_pair("b","d"));
    in.push_back(make_pair("f","a"));
    in.push_back(make_pair("d","c"));
    //in.push_back(make_pair("c","a"));

    vector<string>res;
    res = build_order({"a","b","c","d","e","f","haha"},in);
    if(res.size()==0) cout << "not valid input";
    else{
        for(auto i:res){
            cout << i << ",";
        }
    }
}

