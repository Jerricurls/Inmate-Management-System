
#include <bits/stdc++.h>
using namespace std;


class Inmate 
{
	public:
	int exnum;
	int TDCJ;
	int age;
	string date;
	string lastName;
	string firstName;
	string race;
	string county;

};


// Function to insert record into file 
void Insert_Record(int exnum,int TDCJ,int age, string date, string lastName, string firstName, string race, string county)
{

	{
		ofstream outfile;  

		outfile.open("inmate-records.txt",ios::app);  //opening the file to output to

		if (outfile.is_open())
		{
			outfile<< "\n" << exnum << "," << lastName << "," << firstName << "," << TDCJ << "," << age << "," << date << "," << race << "," << county<< endl; // Enters the information separated by commas.

			outfile.close(); //close file
		}
    	cout << "Record Inserted "
    		<< "Successfully\n";
    }
}


// Function to search the file for the record 
void Search_Record(string lastName, string firstName, string Lname, string Fname)
{

string search;
ifstream inFile;
string line;
string input;
string y;

inFile.open("inmate-records.txt");

if(!inFile){
cout << "Unable to open file" << endl; // If the file is not/ unable to be opened an error message is shown.
exit(1);
}
	cout << "Enter last name of the inmate to be searched.\n";
	cin >> Lname;
	cout << "Enter first name of the inmate to be searched.\n";
	cin >> Fname;


size_t pos;
size_t pos2;
while(inFile.good())   //while the file is open the user input will be taken to search for the line wanted by the user
  {
      getline(inFile,line); // get line from file
      pos=line.find(Lname); // search ( ordered search tree)
      pos2=line.find(Fname);
      if((pos!=string::npos) && (pos2!=string::npos)) // string::npos is returned if string is not found
        {
            cout <<"Found!\n";
			cout<<"\n"<<line<<endl; // if found  the line of the file will be pulled up
            break;
        } 
  }
  
	
}


//This Function tkes the First and Last name of the inmate and searches the file to delete the line
int Delete_Record()
{   
    size_t pos;
    size_t pos2;
    string line, first,last;
    
    ifstream inFile;
    ofstream temp;
    temp.open("temp.txt"); // temp file for the deleted record
    
    
    inFile.open("inmate-records.txt");
    if(inFile.is_open())
    {

        cout<<" Enter last name to delete Record. \n ";
        cin>> last;
        cout<<"Enter first name to delete record. \n ";
        cin>>first;
    }
    
    
    while (getline(inFile,line))
    {
         pos=line.find(last); // search
         pos2=line.find(first);
        if((pos!=string::npos) && (pos2!=string::npos)) // string::npos is returned if string is not found
		{
			temp<<line<<endl;
			cout<< "record successfully deleted";	
		}
    }
        temp.close();
        inFile.close();
        remove("inmate-records.txt"); //part of linked list data structue "list::"
        rename("temp.txt","inmate-records.txt"); 
        return 0;

}

// Function to display the Student's
// Record
void Show_Record()
{
	{
		fstream newfile;
		newfile.open("inmate-records.cpp",ios::out);
		
		newfile<<"Failed to open \n";
		newfile.close();
	
		newfile.open("inmate-records.txt",ios::in);
		
		{
			string Inmate;

	        while(getline(newfile, Inmate))
	        {
	        	cout<< Inmate << "\n";
	        }
	        newfile.close();
		}

	}
}
// Driver code
#include <fstream>
#include <string>
int main()
{
	string lastName,firstName,race,county,Lname,Fname,date;
	int exnum, TDCJ, age;
	int Choice;


	// Menu-driven program
	while (true) {
		 cout<<"\n----------------------------"
                "\n\tInmate Management "
                "\n----------------------------"
                "\n1. Add New Inmate "
                "\n2. Delete Inmate "
                "\n3. Search Inmate "
                "\n4. Display all Inmates"
                "\n5. Web search"
            	"\n0. exit"
                "\n Enter Your Choice : ";
                cin>>Choice;
		
		 if (Choice == 1 )
        {	cout<<"Enter Inmate's execution number"<<endl;
            cin>>exnum;
            cout<<"Enter Inmate's Last name"<<endl;
            cin>>lastName;
            cout<<"Enter Inmate's First name"<<endl;
            cin>>firstName;
            cout<<"Enter Inmate's TDCJ Number"<<endl;
            cin>>TDCJ;
            cout<<"Enter Inmate's Age"<< endl;
            cin>> age;
            cout<<"Enter Date of Execution"<<endl;
            cin>>date;
            cout<<"Enter Inmate's Race"<<endl;
            cin>>race;
            cout<<"Enter county"<<endl;
            cin>>county;
			Insert_Record(exnum, TDCJ,age, date,lastName, firstName, race, county);
		}
		else if (Choice == 2) {
		Delete_Record();
			
		}
		else if (Choice == 3) {
			
			Search_Record(lastName, firstName, Lname, Fname);
		}
		else if (Choice == 4) 
		{
			Show_Record();
		}
		else if(Choice == 5)
		{
			system("cmd/c start https://www.tdcj.texas.gov/death_row/dr_executed_offenders.html"); // if 5 is pressed then the user can see the database

		}
		else if (Choice == 0) {
			exit(0);
		}
		else {
			cout << "Invalid Choice "
				<< "Try Again\n";
		}	
}
	return 0;
}