//https://www.interviewbit.com/problems/count-and-say/
/*
    1
    11
    21
    1211
    111221
*/
string Solution::countAndSay(int A) {
    string s = "1";
    for(int i=1;i<A;i++){
        string temp_s = "";
        int count = 1; char temp= s[0];
        for(int j=1;j<s.length();j++){
            if(s[j]==temp)
                count++;
            else{
                temp_s += to_string(count);
                temp_s.push_back(temp);
                temp = s[j];
                count = 1;
            }
        }
        temp_s += to_string(count);
        temp_s.push_back(temp);
        s = temp_s;
    }
    return s;
}
