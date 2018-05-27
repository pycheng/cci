#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
	public:
		stack<int> s1, s2;

	    /** Initialize your data structure here. */
	    MyQueue() {
			s1.clear();
			s2.clear();	 	       
	    }
	    
	    /** Push element x to the back of queue. */
	    void push(int x) {
	       	s1.push(x); 
	    }
	   
        void move_s1_to_s2(){
            //move everything in s1 to s2
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
	    /** Removes the element from in front of queue and returns that element. */
	    int pop() {
	       	if(s2.empty()){
                move_s1_to_s2();
			}
			int res = s2.top();
            s2.pop();
            return res;
	    }
	    
	    /** Get the front element. */
	    int peek() {
	       	if(s2.empty()){
                move_s1_to_s2();
			}
            return s2.top();
	    }
	    
	    /** Returns whether the queue is empty. */
	    bool empty() {
	        return (s1.empty()&&s2.empty());
	    }
};
