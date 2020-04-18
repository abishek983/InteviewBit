// https://www.interviewbit.com/problems/scramble-string/


map<string,int> mp;
int solve(string s1,string s2){
    if(s1.compare(s2)==0)
        return 1;
    if(s1.length()<=1)
        return 0;
    string temp = s1 + " " + s2;
    if(mp.find(temp)!=mp.end())
        return mp[temp];
    int flag = 0;
    int n = s1.length();
    for(int i=1;i<n;i++){
        int left = solve(s1.substr(0,i),s2.substr(s2.length()-i)) && solve(s1.substr(i),s2.substr(0,s2.length()-i));
        int right = solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i),s2.substr(i));
        if(left || right){
            flag = 1;
            break;
        }
        
    }
    mp[temp] = flag;
    return flag;
}


int Solution::isScramble(const string A, const string B) {
    if(A.length()!=B.length())
        return 0;
    return solve(A,B);
}
