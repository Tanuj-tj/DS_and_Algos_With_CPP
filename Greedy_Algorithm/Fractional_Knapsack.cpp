class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    
    // Comparator function
    static bool comp(Item a,Item b){
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)a.value/(double)a.weight;
        
        return r1>r2;
    }
    
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //Sort the given array in descending
        sort(arr,arr+n,comp);
        
        int currWeight = 0;
        double finalValue = 0.0;
        
        for(int i=0;i<n;i++){
            
            if(currWeight+arr[i].weight <= W){
                currWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            else{
                int rem = W - currWeight;
                finalValue += (arr[i].value / (double)arr[i].weight) * (double)rem;
                break;
            }
            
        }
        
        return finalValue;
        
    }
        
};