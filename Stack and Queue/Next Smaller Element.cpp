class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        // Your code goes here
        int n= arr.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()>=arr[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};
