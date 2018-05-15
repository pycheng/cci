#include <iostream>
#include <stack>
using namespace std;

class tower{
    private:
        stack<int> s;
        string name;
    public:
        tower(int ndisk, string a){
            for(int i=ndisk;i>0;i--){
                s.push(i);
                //cout << s.top();
            }
            name = a;
        }
        void add(int v){
            if(s.empty()||v < s.top()){
                s.push(v);
            }else{
                cout << "violate hanoi rule("
                     << v << "," << s.top() << ")"
                     << "\n";
            }
        }
        void moveone(tower& t){
            int i = s.top();
            s.pop();
            t.add(i);   
        }
        int top(){ return s.top();}
        void pop(){ return s.pop();}
        bool empty(){ return s.empty();}
        int size(){ return s.size();}
        void print(){
            string sep = "";
            cout << name << "tower content[" ;
            for(stack<int> i=s; !i.empty(); i.pop())
            {
                cout << sep << i.top();
                sep = ",";
            }
            cout << "]\n";
                
        }
        void moveto(int n, tower& t, tower& buf){
                //cout << "mt\n";
                //cout << n << "," << &t <<"\n" << &buf <<"\n"<< &aa<<"\n";
               if(n>0){
                   moveto(n-1, buf, t);
                   moveone(t);
                   buf.moveto(n-1,t,*this);
               }
        }
        
};


int main(){
   tower t1(5, "t1"); 
   tower t2(0, "t2"); 
   tower t3(0, "t3");
   t1.print();
   t3.print();
   cout << "moving\n";
   t1.moveto(5,t3,t2);
   t1.print();
   t3.print();
}
