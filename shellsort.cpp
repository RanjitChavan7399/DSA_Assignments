#include<iostream>
using namespace std;

void sort(int a[], int n){
    int gap;
    for(gap = n/2; gap > 0; gap /= 2){
        int temp,i;
        for(i = gap; i < n; i++){
            temp = a[i];
            int j = i-1;
            while(j >= 0 && a[j] > temp){
                a[j+gap] = a[j];
                j--;
            }
            a[j+1]=temp;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the value of n :";
    cin>>n;

    int a[n];
    for(int i = 0; i < n; i++){
        cout<<"Enter the "<<i+1<<" element of array :";
        cin>>a[i];
    }

    cout<<"Unsorted array :"<<endl;
    for(int i = 0; i < n; i++){
        cout<<a[i]<<"\t";
    }

    sort(a,n);

    cout<<"\nSorted array :"<<endl;
    for(int i = 0; i < n; i++){
        cout<<a[i]<<"\t";
    }

    return 0;
}