void countsort(int arr[],int n,int place){
        int i,freq[range]={0}; 
        int output[n];
        for(i=0;i<n;i++)
                freq[(arr[i]/place)%range]++;
        for(i=1;i<range;i++)
                freq[i]+=freq[i-1];
        for(i=n-1;i>=0;i--) {
                output[freq[(arr[i]/place)%range]-1]=arr[i];
                freq[(arr[i]/place)%range]--;
        }
        for(i=0;i<n;i++)
                arr[i]=output[i];
}
void radixsort(ll arr[],int n,int max){
        int mul=1;
        while(max){
                countsort(arr,n,mul);
                mul*=10;
                max/=10;
        }
}
