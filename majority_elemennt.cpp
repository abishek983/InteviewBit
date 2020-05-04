//https://www.interviewbit.com/problems/majority-element/
/*
    Moore's voting algorithm to find the maximum element.
    This algorithm assumes that their exist an element which occurs
    nore than half the size of the elements.
    
    Basic idea of the algorithm is that if each occurrence of an element e 
    can be cancelled with all the other elements that are different from e 
    then e will exist till end if it is a majority element.

*/


int Solution::majorityElement(const vector<int> &A) {
    int count = 1; int ele = A[0];
    for(int i=1;i<A.size();i++){
        if(A[i]==ele){
            count ++;
        }
        else{
            count--;
            if(count==0){
                count = 1;
                ele = A[i];
            }
        }
    }
    return ele;
}
