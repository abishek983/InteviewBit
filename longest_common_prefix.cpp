//https://www.interviewbit.com/problems/longest-common-prefix/

string helper(string s1,string s2){
    int i;
    int len = min(s1.length(),s2.length());
    for(i=0;i<len;i++){
        if(s1[i]!=s2[i])
            break;
    }
    string temp = "";
    if(i==0)
        return temp;
    return s1.substr(0,i);
}

string Solution::longestCommonPrefix(vector<string> &A) {
    string s = A[0];
    for(int i=1;i<A.size();i++){
        s = helper(s,A[i]);
    }
    return s;
}
