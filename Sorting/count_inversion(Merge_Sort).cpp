class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],int l,int mid,int r){
        long long inv = 0;
        int n1 = mid-l+1;
        int n2 = r - mid;
        
        long long a[n1],b[n2];
        
        for(int i=0;i<n1;i++){
            a[i] = arr[l+i];
        }
        for(int i=0;i<n2;i++){
            b[i] = arr[mid+i+1];
        }
        int i=0,j=0,k=l;
        while(i<n1 and j<n2){
            if(a[i]<=b[j]){
                arr[k]=a[i];
                k++;i++;
            }
            else{
                arr[k]=b[j];
                inv += n1 - i;
                k++;j++;
            }
        }
        while(i<n1){
            arr[k] = a[i];
            k++;i++;
        }
        while(j<n2){
            arr[k] = b[j];
            k++;j++;
        }
        return inv;
    }
    long long mergeSort(long long arr[],int l,int r){
        long long inv = 0;
        if(l<r){
            int mid = (l+r)/2;
            inv += mergeSort(arr,l,mid);
            inv += mergeSort(arr,mid+1,r);
            inv += merge(arr,l,mid,r);
        }
        return inv;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        
        int l = 0,r=N-1;
        mergeSort(arr,l,r);
        
        
    }

};
