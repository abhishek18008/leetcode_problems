class Solution {
public:
    bool ispossible(vector<int> quantities,int mini,int n){
        int personreq=0;
        for(auto it:quantities){
            personreq+=ceil((double)it/mini);
        }
        if(personreq<=n)
        return true;
        return false;
    }




    int minimizedMaximum(int n, vector<int>& quantities) {
        //try binary serach on ans
        int l=1;
        int r=*max_element(quantities.begin(),quantities.end());
        while(l<r){
            int mid=l+(r-l)/2;
            if(!ispossible(quantities,mid,n)){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
};