#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int si,int mid,int ei){
    int n1=mid-si+1;
    int n2=ei-mid;
    int left[n1];
    int right[n2];
    int i=0;
    int j=0;
    int l=si;
    for(int po=0;po<n1;po++){
        left[po]=arr[po+si];
    }
     for(int po=0;po<n2;po++){
        right[po]=arr[po+mid+1];
    }
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[l]=left[i];
            i++;
        }
        else{
            arr[l]=right[j];
            j++;
        }
        l++;
    }
    while(i<n1){
          arr[l]=left[i];
            i++;l++;
    }
    while(j<n2){
         arr[l]=right[j];
            j++;l++;
    }
}

void mergesort(vector<int>& arr,int si ,int ei){
    if(si>=ei)return ;
    int mid =(si+ei)/2;
    mergesort(arr,si,mid);
    mergesort(arr,mid+1,ei);
    merge(arr,si,mid,ei);
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
    double s1=clock();
    mergesort(arr,0,n-1);
    double s2=clock();
    cout<<"time taken by the mergesort algorithm is "<<((s2-s1)/CLOCKS_PER_SEC)<<endl;
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}
