//https://www.interviewbit.com/problems/single-number-ii/

int Solution::singleNumber(const vector<int> &A) {
    int arr[32] = {};
    for(int i=0;i<A.size();i++){
        for(int j=0;j<31;j++){
            long long int val = 1<<j;
            if(A[i]&val)
                arr[j]++;
        }
    }
    for(int i=0;i<32;i++){
        arr[i] = arr[i]%3;
        //cout << arr[i] << " " ;
    }

    int ans=0; 
    for(int i=0;i<32;i++){
        int x = 1;
        x = x<<i;
        //cout << x << endl;
        if(arr[i])
            ans += x;
    }
    return ans;
}
