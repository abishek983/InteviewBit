//https://www.interviewbit.com/problems/min-xor-value/

//the xor value of two numbers are minimum when they are close to each other
// so sorting and finding the xor between i and i+1 elements gives us the correct result

int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int ans = INT_MAX;
    for(int i=0;i<A.size()-1;i++){
        if((A[i]^A[i+1])<ans)
            ans = A[i]^A[i+1];
    }
    return ans;
}
