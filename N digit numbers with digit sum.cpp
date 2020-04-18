// https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/
// using map as a lookup table yields TLE so used dp matrix later.

//map<string,long long int> mp;
long long int dp[1001][1001];
const int mod = 1000000007;
long long int solve1(int digits,int sum){
    if(sum==0)
        return 1;
    if(sum<0 || digits==0)
        return 0;
    /*string temp = to_string(digits);
    temp.push_back(' ');
    temp.append(to_string(sum));
    if(mp.find(temp)!=mp.end())
        return mp[temp];*/
    if(dp[digits][sum]!=-1)
        return dp[digits][sum]; 
    long long int ans = 0;
    for(int i=0;i<=9;i++){
        ans = (ans%mod+solve1(digits-1,sum-i)%mod)%mod;
    }
    dp[digits][sum] = ans%mod;
    return ans%mod;
}


int Solution::solve(int A, int B) {
    for(int i=0;i<1001;i++)
        for(int j=0;j<1001;j++)
            dp[i][j] = -1;
    long long int ans = 0;
    for(int i=1;i<=9;i++){
        ans = (ans%mod+solve1(A-1,B-i)%mod)%mod;
        //cout << A-1 << " " << B-i << endl;
    }
    
    return (int)ans;
}
