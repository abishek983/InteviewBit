// https://www.interviewbit.com/problems/3-sum/

int Solution::threeSumClosest(vector<int> &A, int B) {
    long long int ans = INT_MAX;
    int n = A.size();
    sort(A.begin(),A.end());
    for(int i=0;i<n-2;i++){
        int ptr1 = i+1 , ptr2 = n-1;
        int curr_sum = 0;
        while(ptr1<ptr2){
            long long int sum = A[i] + A[ptr1] + A[ptr2];
            if(abs(1LL*B-sum)<abs(1LL*B-ans))
                ans = sum;
            //increment the left pointer if sum < B
            if(sum<B)
                ptr1++;
            else
                ptr2--;
        }
    }
    return (int)ans;
}
