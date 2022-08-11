class Solution {
public:
    vector<int> NSL(vector<int> h, int n){
        stack<pair<int,int>> s;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s.empty()){
                v.push_back(-1);
                s.push({h[i],i});
            }
            else{
                if(s.top().first<h[i]){
                    v.push_back(s.top().second);
                    s.push({h[i],i});
                }
                else{
                    while(s.size()>0 && s.top().first>=h[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        v.push_back(-1);
                        s.push({h[i],i});                        
                    }
                    else{
                        v.push_back(s.top().second);
                        s.push({h[i],i});                        
                    }
                }
            }
        }
        return v;
    };
    vector<int> NSR(vector<int> h, int n){
        stack<pair<int,int>> s;
        vector<int> v;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                v.push_back(n);
                s.push({h[i],i});
            }
            else{
                if(s.top().first<h[i]){
                    v.push_back(s.top().second);
                    s.push({h[i],i});
                }
                else{
                    while(s.size()>0 && s.top().first>=h[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        v.push_back(n);
                        s.push({h[i],i});                        
                    }
                    else{
                        v.push_back(s.top().second);
                        s.push({h[i],i});                        
                    }
                }
            }
        }
        reverse(v.begin(),v.end());
        return v;
    };
    
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> nsr=NSR(heights,n);
        vector<int> nsl=NSL(heights,n);
        vector<int> width(n);
        vector<int> area(n);
        for(int i=0;i<n;i++){
            width[i]=nsr[i]-nsl[i]-1;
            area[i]=width[i]*heights[i];
        }
        return *max_element(area.begin(), area.end());
        
    }
};
