#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student{
	int roll_no;
	char name[20],div[10],address[20];
	public:
	void accept(int);
	void display();
	int search(int);
};
int student::search(int key){
	if(roll_no==key)
		return 1;
	else
		return 0;
}

void student::accept(int key){
	roll_no=key;
	cout<<"Enter the name of the student: ";
	cin>>name;
	cout<<"Enter the division: ";
	cin>>div;
	cout<<"Enter the address: ";
	cin>>address;
}
void student::display(){
	cout<<roll_no<<"\t"<<name<<"\t"<<div<<"\t"<<address<<"\n";
}
int main(){
	fstream f,f1;
	student s;
	int key,t,ch1;
	char ch='y',a[]="abc.txt",b[]="temp.txt";
	do{
		cout<<"1.Create a new database\n2.Insert information of a new student\n3.Display the database\n4.Search for a student\n5.Delete a student\n6.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch1;
		t=0;
		switch(ch1){
			case 1:
				f.open("abc.txt",ios::out);
				if(!f){
					cout<<"ERROR";
				}
				while(ch=='y'||ch=='Y'){
					cout<<"\nEnter the roll number: ";
					cin>>key;
					s.accept(key);
					f.write((char*)&s,sizeof(s));
					cout<<"Do you want to add another student: y/n\n";
					cin>>ch;
				}
				f.close();
				break;
			case 2:
				f.open("abc.txt",ios::out|ios::in);
				cout<<"\nEnter the roll number: ";
				cin>>key;
				while(f.read((char*)&s,sizeof(s))){
					t=s.search(key);
					if(t==1){
						cout<<"Roll number already exists\n";
						break;
					}
				}
				f.close();
				f.open("abc.txt",ios::out|ios::app);
				if(t!=1){
					s.accept(key);
					f.write((char*)&s,sizeof(s));
				}
                
				f.close();
				break;
			case 3:
				cout<<"Roll no\tName\tDivision\tAddress\n";
				f.open("abc.txt",ios::in);
				while(f.read((char*)&s,sizeof(s))){
					s.display();
				}
				f.close();
				break;
			case 4:
				cout<<"Enter the roll number to be searched: ";
				cin>>key;
				f.open("abc.txt",ios::in);
				while(f.read((char*)&s,sizeof(s))){
					t=s.search(key);
					if(t==1){
						cout<<"Roll number found!\n";
						s.display();
						break;
					}
				}
				if(t==0)
					cout<<"Roll number not found!\n";
				f.close();
				break;
			case 5:
				f.open("abc.txt",ios::in|ios::out);
				f1.open("temp.txt",ios::out);
				cout<<"Enter the roll number to be deleted: ";
				cin>>key;
				while(f.read((char*)&s,sizeof(s))){
					t=s.search(key);
					if(t==0){
						f1.write((char*)&s,sizeof(s));
					}
				}
				f.close();
				f1.close();
				rename(b,a);
				cout<<"\nAfter deletion the contents of database are: \n";
				cout<<"Roll no\tName\tDivision\tAddress\n";
				f.open("abc.txt",ios::in);
				while(f.read((char*)&s,sizeof(s))){
					s.display();
				}
				f.close();
		}
	}while(ch1!=6);
	return(0);
}