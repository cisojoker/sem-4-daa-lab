#include <bits/stdc++.h>
using namespace std;

int quick(int a[],int si,int ei){
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
void quicksort(int a[],int si,int ei){
    if(si>=ei)return ;
    int c=quick(a,si,ei);
    quicksort(a,si,c-1);
    quicksort(a,c+1,ei);
}
int main(){
    cout<<"enter the size of array"<<endl;
    int n;cin>>n;int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"array before sorting"<<endl;
    for (auto x:a){
        cout<<x;
    }
    clock_t start=clock();
    quicksort(a,0,n-1);
    clock_t end=clock();
       cout<<"array after sorting"<<endl;
    for (auto x:a){
        cout<<x;
    }
    cout<<endl<<"time take by this algorithm is "<<end-start/CLOCKS_PER_SEC<<"SECONDS"<<endl;
    return 0;
}
