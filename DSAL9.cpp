#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    int i,j,gap,temp,arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(gap =n/2; gap >=1; gap =gap/2){
        for(j = gap; j<n; j++){
            for(i = j-gap; i>=0;i= i-gap){
                if(arr[i+gap] > arr[i] ){
                    break;
                }
                else{
                    swap(arr[i+gap] , arr[i]);
                }
            }
        }
    }
    
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
