class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            code here 
            int i=n-1; // last elemet of arr1
            int j=0; // first element of arr2
            
            while(i>=0 && j<m){
                if(arr1[i]>=arr2[j]){
                    swap(arr1[i],arr2[j]);
                    j++;i--;
                }
                else{
                    break;
                }
            }
            
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
};
