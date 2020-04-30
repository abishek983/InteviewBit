// https://www.interviewbit.com/problems/tushars-birthday-party/

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    long long int dp[1001][1001];
    int max_size = 0;
    for(int i=0;i<A.size();i++)
        max_size = max(max_size,A[i]);
        
    for(int i=0;i<=B.size();i++){
        for(int j=0;j<=max_size;j++){
            if(j==0)
                dp[i][j] = 0;
            else if(i==0)
                dp[i][j] = INT_MAX;
            else if(j>=B[i-1]){
                dp[i][j] = min(C[i-1]+dp[i][j-B[i-1]],dp[i-1][j]);
                //cout << j << " " << B[i-1] << " " << dp[i][j] << endl;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int total = 0;
    for(int i=0;i<A.size();i++){
        total += dp[B.size()][A[i]];
    }
    return total;
    
}
