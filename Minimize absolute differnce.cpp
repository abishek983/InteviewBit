// https://www.interviewbit.com/problems/minimize-the-absolute-difference/?ref=similar_problems

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = A.size()-1;
    int j = B.size()-1;
    int k = C.size()-1;
    int ans = INT_MAX;
    while(i!=-1 && j!=-1 && k!=-1){
        int maxx = max(A[i],max(B[j],C[k]));
        int minn = min(A[i],min(B[j],C[k]));
        int curr = abs(maxx - minn); 
        if(ans>curr)
            ans = curr;
        if(maxx == A[i])
            i--;
        else if(maxx == B[j])
            j--;
        else
            k--;
    }
    return ans;
}
