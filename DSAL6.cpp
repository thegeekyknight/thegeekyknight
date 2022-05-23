#include<iostream>
#include<string.h>
using namespace std;

int adj_mat[50][50],visited[50],n;

void DFS(int start,string arr[]){
	cout<<"\n"<<arr[start];
	visited[start] = 1;
	for(int i=0;i<n;i++){
		if(adj_mat[start][i]>0 && !visited[i]){
			DFS(i,arr);
		}
	}
}

void isGraphConnected(string cities[]){
	for(int i=0;i<n;i++){
		visited[i]=0;
	}
	DFS(0,cities);
	bool flag=true;
	for(int i=0;i<n;i++){
		if(visited[i]==0){
			flag=false;
		}
	}
	if(flag) cout<<"\nGraph is connected"<<endl;
	else cout<<"\nGraph is not connected"<<endl;
}

int main(){
	cout<<"Enter the number of cities :";
	cin>>n;
	string cities[n];
	
	for(int i=0;i<n;i++){
			visited[i]=0;
		for(int j=0;j<n;j++){
			adj_mat[i][j] = 0;
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<"Enter the name of the city :";
		cin>>cities[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			cout<<"Enter the time taken to travel from "<<cities[i]<<" to "<<cities[j]<<" ";
			cin>>adj_mat[i][j];
			adj_mat[j][i]=adj_mat[i][j];
		}
	}
	
	for (int i = 0; i < n; i++){
		cout << "\t" << cities[i] << "\t";
	}
	cout<<endl;
	
	for(int i = 0;i < n; i++)
	{
		cout << "\n"<< cities[i];
		for (int j = 0; j < n; j++){
			cout << "\t" << adj_mat[i][j] << "\t";
		}
		cout << endl;
	}
	
	isGraphConnected(cities);
}
