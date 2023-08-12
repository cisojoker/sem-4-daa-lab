#include<bits/stdc++.h>
using namespace std;

int quick(vector<int>&a,int si,int ei){
      int pi=(si+ei)/2;
      int pivot=a[pi];
      swap(a[si],a[pi]);
      int low=si+1;
      while(ei>=low){
          while(low<=ei && a[low]<=pivot){
              low++;
          }
           while(low<=ei && a[ei]>pivot){
              ei--;
          }
          if(low<ei){
              swap(a[low],a[ei]);
          }
      }
      swap(a[ei],a[si]);
      return ei;
}
void quicksort(vector<int>&a,int si,int ei){
    if(si>=ei)return ;
    int c=quick(a,si,ei);
    quicksort(a,si,c-1);
    quicksort(a,c+1,ei);
}

int main(){
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
     vector<int>arr(n);
    for(int i=0;i<n;i++){
        int a=rand()%(INT_MAX);
        arr[i]=a;
    }
    double ss1=clock();
    quicksort(arr,0,n-1);
    double ss2=clock();
    cout<<"time taken by the quicksort algorithm is "<<((ss2-ss1)/CLOCKS_PER_SEC)<<endl;
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}
    
