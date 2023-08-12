#include<bits/stdc++.h>
using namespace std;
void bubble(vector<int> arr){
    int n=arr.size();
    double start,endg;
    start=clock();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    endg=clock();
    cout<<"time taken by bubble sort is "<<((endg-start)/CLOCKS_PER_SEC)<<"sec"<<endl;
}
void insertion(vector<int> arr){
    int n=arr.size();
    double start,endg;
    start=clock();
       for(int i=1;i<n;i++){
           int j=i-1;
          int temp=arr[i];
           while(j>=0 && arr[i]<arr[j]){
               arr[j+1]=arr[j];
               j--;
           }
           arr[j+1]=temp;
       }
    endg=clock();
    cout<<"time taken by bubble sort is "<<((endg-start)/CLOCKS_PER_SEC)<<"sec"<<endl;
}
int main(){
    
    int n;
    cout<<"Enter the size of arr\n";
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        int a=rand()%(INT_MAX);
        arr[i]=a;
       
    }
    bubble(arr);
    
    insertion(arr);
}
