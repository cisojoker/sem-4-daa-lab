#include <bits/stdc++.h>
using namespace std;

int binarysearch(int a[],int low,int high,int key){
    while(high>=low){
        int mid=(low+high)/2;
        if(a[mid]==key)
        return mid;
      else  if(a[mid]>key)
       high=mid-1;
        else if (a[mid]<key)
         low=mid+1;
    }
    return -1;
}

int linsear(int a[], int s, int key) {
    for (int i = 0; i < s; i++) {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cout << "Enter the key to search: ";
    cin >> k;

    clock_t start1 = clock();
    int ans = linsear(a, n, k);
    clock_t end1 = clock();
    cout << "Time taken by linear search: " << (double)(end1 - start1) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Found at index: " << ans << endl;

    clock_t start2 = clock();
    int aaa = binarysearch(a, 0, n - 1, k);
    clock_t end2 = clock();
    cout << "Time taken by binary search: " << (double)(end2 - start2) / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Found at index: " << aaa << endl;

    return 0;
}
