#include <iostream>
#include <fstream>
#include<stdio.h>
using namespace std;
class cattle {
public:
    string name;
    int price;
    int quantity;
    void Add_Record() {
    cout<<"\n\n\t\t\tAdd Animal Record\n";
    cout << "Enter Name of Animals" << endl;
    cin >> name;
    cout << "Enter Price of Animals" << endl;
    cin >> price;
    cout << "Enter number(Quantity) of  Animals:" << endl;
    cin >> quantity;
    ofstream MyFile("Cattle.txt", ios::out|ios::app);
    MyFile <<" "<<name<<endl;
    MyFile <<" "<<price<<endl;
    MyFile <<" "<<quantity<<endl;
    MyFile.close();
   }
    void Display_Record() 
	{
	system("cls");
	cout<<"\n\n\t\t\tShow the Animals Information\n";
    ifstream MyFile;
    MyFile.open("Cattle.txt",ios::in);
    if(!MyFile)
    cout<<"File Opening Error \n";
    else
    {
    MyFile>>name>>price>>quantity;
	
 while (!MyFile.eof())
 {
    cout<<"Name Of Animal:"<<name<<"\n"<<"Price of Animal:"<<price<<"\n"<<"Quantity :"<<quantity<<"\n";
   MyFile>>name>>price>>quantity;
    }
    system("pause");
    MyFile.close();
    }
}
void Search_record()
{
	string c_name;
	ifstream MyFile;
    MyFile.open("Cattle.txt",ios::in);
    if(!MyFile)
    cout<<"File Opening Error \n";
    else
    {
    cout<<"\nSearch Animal Thorugh There Name :";
    cin>>c_name;
   MyFile>>name>>price>>quantity;
   while(!MyFile.eof()) 
   {
   	if(c_name==name)
   	{
    cout<<"Name Of Animal:"<<name<<"\n"<<"Price of Animal:"<<price<<"\n"<<"Quantity :"<<quantity<<"\n";		
    }  
   MyFile>>name>>price>>quantity; 
   }	
   if(c_name!=name)
   cout<<"\nAnimal Record not match";
   system("pause");
   MyFile.close();
	}
	
	}
 void Modify_record() 
 {
    string new_name;
    string c_name;
    int new_a_price;
    int new_a_qunatity;
    ifstream MyFile;
    ofstream temp;
	temp.open("Cattle1.txt",ios::out|ios::app);
	MyFile.open("Cattle.txt",ios::in);
	if(!MyFile)
	cout<<"\nFile OPening error ";
	else
	{
	cout<<"Enter the name of animal do you want to update :";
	cin.ignore();
	getline(cin,c_name);
	MyFile>>name>>price>>quantity; 
	while(!MyFile.eof())
	{ 
	if(c_name==name)
    {
    cout<<"Enter new Name :";
	getline(cin,new_name);
	cout<<"Enter New Price :";
	cin>>new_a_price;
	cout<<"Enter new quantity :";
	cin>>new_a_qunatity;
	temp<<" "<<new_name<<" "<<new_a_price<<" "<<new_a_qunatity<<"\n";
	}	
	else
	temp<<" "<<name<<" "<<price<<" "<<quantity<<"\n";
    MyFile>>name>>price>>quantity;	 		
	}
	if(c_name!=name)
	cout<<"\nAnimal Name Not Match ";
	system("pause");
	MyFile.close();
	temp.close();
	rename("Cattle1.txt","Cattle.txt");
	remove("Cattle.txt");
 
	}
	}
void Delete_Record()
{
	cout<<"\n\n\t\t\tDelete Record\n";
	string c_name;
	ifstream MyFile;
	ofstream temp;
	temp.open("Cattle1.txt",ios::out|ios::app);
	MyFile.open("Cattle.txt",ios::in);
	if(!MyFile)
	cout<<"\nFile Opening Error ";
	else
	{
    cout<<"Enter name of Animal you sold :";
	cin.ignore();
	getline(cin,c_name);
	MyFile>>name>>price>>quantity;
	while(!MyFile.eof())
	{
	if(c_name==name)
	{
	cout<<"\nAnimal sold successfully\n";
	}
	else
	temp<<" "<<name<<" "<<price<<" "<<quantity<<"\n";
	MyFile>>name>>price>>quantity;
	}
	if(c_name!=name)
	cout<<"\nAnimal name Not Match\n";
	system("pause");
	MyFile.close();
	temp.close();
	remove("Cattle.txt");
	rename("Cattle1.txt","Cattle.txt");	
	}
}
         
};
int main()
{   
    int option;
    char choice='y';
    cattle caller;
    do {
    system("cls");
    cout << "===========E-Cattle System===========" << endl;
    cout << endl;
    cout << "Options" << endl;
    cout << endl;
    cout << "1. Enter the New  Animals Information" << endl;
    cout << "2. Show the Animals Information" << endl;
    cout << "3. Search the Animals By Name  " << endl;
    cout << "4. update  Animal " << endl;
    cout << "5. selled Animals  " << endl;
    cout << "6. Close the  E-Cattle System" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
    system("cls");
    caller.Add_Record();
    break;
    case 2:
    // system("cls");
    caller.Display_Record();
    break;
    case 3:
    system("cls");
    caller.Search_record();
    break;
    case 4:
    system("cls");
    caller.Modify_record();
    break;
    case 5:
    system("cls");
    caller.Delete_Record();
  break;
    case 6:
    exit(0);
    break;
    default:
    cout << "Invalid Option"<<endl;
    break;
    }
    cout << "Do you want to Continue (y/n)" << endl;
    cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

