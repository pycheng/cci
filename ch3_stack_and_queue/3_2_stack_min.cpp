//#stack 
#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;


class MinStack{
    public:
        class item{
            public:
            int v;
            int cur_min;
            item(int x, int m): v(x), cur_min(0) { cur_min=min(m,x);}
            ~item(){}
        };
        stack<item> _minstack;
        MinStack(){
        }
        void push(int x){
            int min_v = _minstack.empty()?x:_minstack.top().cur_min;
            item *pi = new item(x,min_v);
            _minstack.push(*pi);
			delete pi;
        }
        void pop(){
            _minstack.pop();
        }
        int top(){
            return _minstack.top().v;
        }
        int getMin(){
            return _minstack.top().cur_min;
        }
};
#if 0
#endif
int main(){
    MinStack s;

s.push(-10);
s.push(14);
cout << s.getMin() << "\n";
cout << s.getMin() << "\n";
s.push(-20);
cout << s.getMin() << "\n";
cout << s.getMin() << "\n";
cout << s.top() << "\n";
cout << s.getMin() << "\n";
s.pop();
s.push(10);
s.push(-7);
cout << s.getMin() << "\n";
s.push(-7);
s.pop();
cout << s.top() << "\n";
cout << s.getMin() << "\n";
s.pop();

#if 0
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << "\n";
    s.pop();
    cout << s.top() << "\n";
    cout << s.getMin() << "\n";
#endif
}
