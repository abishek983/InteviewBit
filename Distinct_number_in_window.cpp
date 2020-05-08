//https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    int i=-1,j=0;
    int n = A.size();
    if(B>n)
        return ans;
    map<int,int> mp;
    while(j<n){
        mp[A[j]]++;
        if(j>=B-1){
            if(i!=-1){
                mp[A[i]]--;
                if(mp[A[i]]==0){
                    mp.erase(A[i]);
                }
            }
            ans.push_back(mp.size());
            i++;
        }
        j++;
    }
    return ans;
}
