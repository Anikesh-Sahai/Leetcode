// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<char> ch;
        stack<int> index;
        index.push(-1);
        int maxL=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                ch.push('(');
                index.push(i);
            }
            else{               //closing bracket
                if(!ch.empty() && ch.top()=='('){      // checking for the stack to cmplete ()
                    ch.pop();
                    index.pop();
                    maxL=max(maxL,i-index.top());
                }
                else{           //i stack dont have any (
                    index.push(i);
                }
            }
        }
        return maxL;
        
    }
};  