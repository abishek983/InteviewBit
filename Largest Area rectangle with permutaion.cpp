//https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/

// fill the rows from 1 to n-1 with values with number of consecutive ones above it

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            A[i][j] = (A[i][j] == 0) ? 0 : A[i-1][j]+1; 
        }
    }
   for(int i=0;i<n;i++){
       sort(A[i].begin(),A[i].end());
   }

    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=0;j<m;j++){
            //cout << A[i][j] << " ";
            if(A[i][j]==0)
                continue;
            else{
                // after reaching this point all other elements would have atleast values
                //greater than the value we have now
                temp = (m-j)*A[i][j];
                ans = max(temp,ans);
            }
        } 
    }    
    return ans;
}
