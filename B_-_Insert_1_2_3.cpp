#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int countGeneratableSubsequences(const vector<int>& A) {
    int count = 0;
    stack<int> st; 

    for (int i = 0; i < A.size(); ++i) {
        while (!st.empty() && A[i] > A[st.top()]) {
            int prevIdx = st.top();
            st.pop();
            int prevBelowIdx = st.empty() ? -1 : st.top();
            count += (i - prevIdx) * (prevIdx - prevBelowIdx);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int prevIdx = st.top();
        st.pop();
        int prevBelowIdx = st.empty() ? -1 : st.top();
        count += (A.size() - prevIdx) * (prevIdx - prevBelowIdx);
    }

    return count;
}

int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    
  
    int result = countGeneratableSubsequences(A);
    cout << result << endl; 

    return 0;
}
