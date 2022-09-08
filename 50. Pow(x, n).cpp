//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

class Solution {
public:
    
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n>0){
            double output=myPow(x,n/2);
            if( n%2==0 ) return output*output;
            else return x* output*output;
        }
        double output=myPow(x,n/2);
        if( n%2==0 ) return output*output;
        else return (1/x)* output*output;
        
    }
};