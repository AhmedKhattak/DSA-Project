/*

DSA LAB PROJECT     : STUDENT MANAGMENT SYSTEM
CLASS               : BSCS 4-B
GROUP MEMBERS       : AHMED SIDIQUI, ADNAN JAMEEL, AHMED RAFIULLAH
PROGRAM DESCRIPTION : This program allows student details to be  managed in a flat file system the student data is manipulated in this program
and saved to the hardisk in a .txt file

*/
# include<iostream>
# include<conio.h>
# include<string>
# include<fstream>
# include<iomanip>          
using namespace std;
// Snode class contains all student data
class Snode
{
public:
	string Enrollment;
	string Name;
	int Regno;
	string Class;
	string Program;
	Snode *next;
	Snode *prev;
	// constructor for the Snode class
	Snode()
	{
		Enrollment = "null";
		Name = "null";
		Regno = 0;
		Class = "null";
		Program = "null";

	}
};
class Managment
{
public:
	int width;
	Snode *first;
	Snode *last;
	Managment()
	{
		width = 20;
		first = NULL;
		last = NULL;
	}
	// function to add student
	void AddStudent(string name, string enroll, string cls, int regno, string prg)
	{


		Snode *temp;
		temp = new Snode;
		temp->Name = name;

		temp->Enrollment = enroll;

		temp->Class = cls;

		temp->Regno = regno;

		temp->Program = prg;
		temp->next = NULL;
		temp->prev = NULL;
		if (first == NULL)
		{
			first = temp;
		}
		else
		{
			last->next = temp;
			temp->prev = last;
		}
		last = temp;

	}
	void ViewStudent()
	{
		cout << endl << endl << endl;
		cout << left << setw(width) << setfill(' ') << "enroll"; cout << left << setw(width) << setfill(' ') << "name"; cout << left << setw(width) << setfill(' ') << "class"; cout << left << setw(width) << setfill(' ') << "regno"; cout << left << setw(width) << setfill(' ') << "prog" << endl;
		Snode *temp;
		temp = first;
		while (temp != NULL)
		{

			cout << left << setw(width) << setfill(' ') << temp->Enrollment; cout << left << setw(width) << setfill(' ') << revert(temp->Name);; cout << left << setw(width) << setfill(' ') << temp->Class; cout << left << setw(width) << setfill(' ') << temp->Regno; cout << left << setw(width) << setfill(' ') << temp->Program << endl;
			temp = temp->next;
		}
	}
	void WriteToDisk()
	{

		ofstream myfile;
		myfile.open("StudentData.txt"); //no ios append so file is overidden
		if (myfile.good())

		{

			Snode* temp;
			temp = first;
			while (temp != NULL)
			{
				temp->Name = convert(temp->Name);
				myfile << left << setw(width) << setfill(' ') << temp->Enrollment; myfile << left << setw(width) << setfill(' ') << temp->Name; myfile << left << setw(width) << setfill(' ') << temp->Class; myfile << left << setw(width) << setfill(' ') << temp->Regno; myfile << left << setw(width) << setfill(' ') << temp->Program << endl;
				temp = temp->next;
			}
		}
	}
	string convert(string conv)
	{
		int lenght;
		bool flag = true;
		while (flag == true)
		{
			lenght = conv.find(' ');
			if (lenght != string::npos)
			{
				conv.replace(lenght, 1, "-");
			}
			else
				flag = false;
		}
		conv = conv;
		return conv;
	}
	string revert(string rev)
	{
		int lenght;
		bool flag = true;
		while (flag == true)
		{
			lenght = rev.find('-');
			if (lenght != string::npos)
			{
				rev.replace(lenght, 1, " ");

			}
			else
				flag = false;
		}
		rev = rev;
		return rev;
	}


	void ReadFromDisk()
	{
		ifstream myfile;
		myfile.open("StudentData.txt");
		string enroll, name, program, Class;
		int regno;
		destructor(); //necessary to overide list
		while (!myfile.eof())
		{

			while (myfile >> enroll >> name >> Class >> regno >> program)
			{

				AddStudent(name, enroll, Class, regno, program);

			}
		}


	}
	void SortFileBy()
	{
		Snode *iterator1;
		Snode *iterator2;
		Snode *temp;
		Snode *iterator3 = first;
		temp = new Snode;
		for (iterator1 = first; iterator1 != NULL; iterator1 = iterator1->next)    // same  as selection sort same logic
		{
			for (iterator2 = iterator3; iterator2 != NULL; iterator2 = iterator2->next)
			{
				if (iterator1->Regno > iterator2->Regno)
				{
					//swap regno
					temp->Regno = iterator1->Regno;
					iterator1->Regno = iterator2->Regno;
					iterator2->Regno = temp->Regno;
					//swap name
					temp->Name = iterator1->Name;
					iterator1->Name = iterator2->Name;
					iterator2->Name = temp->Name;
					//swap class
					temp->Class = iterator1->Class;
					iterator1->Class = iterator2->Class;
					iterator2->Class = temp->Class;
					//swap prog
					temp->Program = iterator1->Program;
					iterator1->Program = iterator2->Program;
					iterator2->Program = temp->Program;
					//swap enrollment
					temp->Enrollment = iterator1->Enrollment;
					iterator1->Enrollment = iterator2->Enrollment;
					iterator2->Enrollment = temp->Enrollment;


				}
			}
			iterator3 = iterator3->next;
		}







	}
	void search()
	{
		Snode *temp;
		temp = first;
		string search;
		cout << "enter enrollment number or name to search for student";
		cin >> search;
		search = convert(search);
		cout << left << setw(width) << setfill(' ') << "enroll"; cout << left << setw(width) << setfill(' ') << "name"; cout << left << setw(width) << setfill(' ') << "class"; cout << left << setw(width) << setfill(' ') << "regno"; cout << left << setw(width) << setfill(' ') << "prog" << endl;
		while (temp != NULL)
		{

			if (search == temp->Enrollment || search == temp->Name)
			{


				cout << left << setw(width) << setfill(' ') << temp->Enrollment; cout << left << setw(width) << setfill(' ') << temp->Name; cout << left << setw(width) << setfill(' ') << temp->Class; cout << left << setw(width) << setfill(' ') << temp->Regno; cout << left << setw(width) << setfill(' ') << temp->Program << endl;

			}
			temp = temp->next;
		}

	}
	void Dsearch(string search)
	{
		Snode *temp;
		temp = first;
		string searcher;
		searcher = convert(search);
		while (temp != NULL)
		{

			if (searcher == temp->Enrollment || searcher == temp->Name || searcher == temp->Class || searcher == temp->Program)
			{


				cout << left << setw(width) << setfill(' ') << temp->Enrollment; cout << left << setw(width) << setfill(' ') << revert(temp->Name); cout << left << setw(width) << setfill(' ') << temp->Class; cout << left << setw(width) << setfill(' ') << temp->Regno; cout << left << setw(width) << setfill(' ') << temp->Program << endl;

			}
			else if (searcher == "\0")
			{

				cout << left << setw(width) << setfill(' ') << temp->Enrollment; cout << left << setw(width) << setfill(' ') << revert(temp->Name); cout << left << setw(width) << setfill(' ') << temp->Class; cout << left << setw(width) << setfill(' ') << temp->Regno; cout << left << setw(width) << setfill(' ') << temp->Program << endl;
			}
			temp = temp->next;
		}





	}



	void delete_entry(string searchterm)
	{
		// 1.sequence of delete entry operation
		// 2.load file into list
		// 3.delete entry
		// 4.write list onto file
		// 5.load file to update view


		Snode *temp1;
		Snode *temp2;
		Snode *temp3;
		temp1 = new Snode;
		temp2 = new Snode;
		temp3 = new Snode;
		Snode *iterator1;
		for (iterator1 = first; iterator1 != NULL; iterator1 = iterator1->next)
		{
			if (iterator1->Enrollment == searchterm && iterator1->next != NULL && iterator1->prev != NULL)
			{
				cout << "\ndeleted enrollment :" << iterator1->Enrollment;
				temp3 = iterator1;
				temp1 = iterator1->prev;
				temp2 = iterator1->next;
				temp1->next = temp2;
				temp2->prev = temp1;
				delete temp3;
				break;
			}
			else if (iterator1->Enrollment == searchterm && iterator1->prev == NULL)
			{

				cout << "\ndeleted enrollment :" << iterator1->Enrollment;
				first = iterator1->next;
				first->prev = NULL;
				temp3 = iterator1;
				delete temp3;
				break;
			}
			else if (iterator1->Enrollment == searchterm && iterator1->next == NULL)
			{
				cout << "\ndeleted enrollment : " << iterator1->Enrollment;
				last = iterator1->prev;
				last->next = NULL;
				temp3 = iterator1;
				delete temp3;
				break;

			}
		}
	}




	void dynamicview()
	{

		string fak;
		string temp;
		cout << "Enter search term : ";
		bool flag = true;
		do
		{
			temp = _getch();
			if (temp == "\r")
				flag = false;
			else if (temp == "\b")
			{
				if (fak != "\0")
				{
					system("cls");
					cout << "Enter search term : ";
					cout << fak;
					cout << "\b" << " " << "\b";
					cout << endl << endl;
					fak.erase(fak.end() - 1);
					cout << left << setw(width) << setfill(' ') << "enroll"; cout << left << setw(width) << setfill(' ') << "name"; cout << left << setw(width) << setfill(' ') << "class"; cout << left << setw(width) << setfill(' ') << "regno"; cout << left << setw(width) << setfill(' ') << "prog" << endl << endl;
					Dsearch(fak);

				}
				else
				{
					system("cls");
					cout << "Enter search term : ";
					cout << "null";
					cout << endl << endl;
					cout << left << setw(width) << setfill(' ') << "enroll"; cout << left << setw(width) << setfill(' ') << "name"; cout << left << setw(width) << setfill(' ') << "class"; cout << left << setw(width) << setfill(' ') << "regno"; cout << left << setw(width) << setfill(' ') << "prog" << endl << endl;
					Dsearch(fak);

				}


			}
			else
			{
				system("cls");
				cout << "\b" << " " << "\b";
				fak.append(temp);
				cout << "Enter search term : ";
				cout << fak;
				cout << endl << endl;
				cout << "\b" << " " << "\b";
				cout << left << setw(width) << setfill(' ') << "enroll"; cout << left << setw(width) << setfill(' ') << "name"; cout << left << setw(width) << setfill(' ') << "class"; cout << left << setw(width) << setfill(' ') << "regno"; cout << left << setw(width) << setfill(' ') << "prog" << endl << endl;
				Dsearch(fak);
			}

		} while (flag == true);






	}
	//destroys the linked list 
	void destructor()
	{
		Snode * temp;
		temp = first;
		Snode *del;
		while (temp != NULL)
		{
			del = temp;
			temp = temp->next;
			delete del;

		}

		first = last = NULL;
		delete temp;
	}


	//login screen to allow user to edit the database
	bool Login()
	{
		cout << "\n\n";
		cout << "Student Managment System" << endl << endl;
		cout << "LOGIN :" << endl << endl;
		string lockpass = "12345";
		string name;
		string temp1;
		string getpass;
		cout << "Enter user name: ";
		cin >> name;
		bool flag = true;

		cout << "Enter pass : ";
		do
		{
			temp1 = _getch();
			if (temp1 == "\r")
				flag = false;
			else if (temp1 == "\b")
			{
				if (getpass != "\0")
				{
					getpass.erase(getpass.end() - 1);
					cout << "\b" << " " << "\b";
				}
				else
				{


				}


			}
			else
			{
				getpass.append(temp1);
				cout << '*';
			}

		} while (flag == true);

		if (getpass == lockpass)
		{
			cout << endl;
			cout << "login successfull" << endl;
			_getch();
			return true;

		}
		else

			return false;




	}
	void editstudent(string enroll)
	{
		Snode *temp;
		temp = first;
		string search;
		string prg;
		string enrollment;
		string name;
		string clss;
		int regno;
		cout << "\n\nenter enrollment number to search for student :";
		cin >> search;
		search = convert(search);



		cout << left << setw(width) << setfill(' ') << "enroll"; cout << left << setw(width) << setfill(' ') << "name"; cout << left << setw(width) << setfill(' ') << "class"; cout << left << setw(width) << setfill(' ') << "regno"; cout << left << setw(width) << setfill(' ') << "prog" << endl;
		while (temp != NULL)
		{

			if (search == temp->Enrollment || search == temp->Name)
			{


				cout << left << setw(width) << setfill(' ') << temp->Enrollment; cout << left << setw(width) << setfill(' ') << temp->Name; cout << left << setw(width) << setfill(' ') << temp->Class; cout << left << setw(width) << setfill(' ') << temp->Regno; cout << left << setw(width) << setfill(' ') << temp->Program << endl;
				cout << "\n found ! \n";
				cin.ignore();
				cout << "enter name : ";
				getline(cin, name);
				cout << "enter enrollment : ";
				cin >> enrollment;
				cout << "enter class : ";
				cin >> clss;
				cout << "enter program : ";
				cin >> prg;
				cout << "enter registration number : ";
				cin >> regno;
				if (regno != 0)
				{
					temp->Regno = regno;
				}
				if (enrollment != "null")
				{
					temp->Enrollment = enrollment;
				}
				if (prg != "null")
				{
					temp->Program = prg;
				}
				if (name != "null")
				{
					temp->Name = name;
				}
				if (clss != "null")
				{
					temp->Class = clss;
				}
				cout << "edited : \n";
				cout << left << setw(width) << setfill(' ') << temp->Enrollment; cout << left << setw(width) << setfill(' ') << temp->Name; cout << left << setw(width) << setfill(' ') << temp->Class; cout << left << setw(width) << setfill(' ') << temp->Regno; cout << left << setw(width) << setfill(' ') << temp->Program << endl;
				break;


			}
			temp = temp->next;
		}




	}

	void check()
	{

		ifstream file;
		ofstream x;
		file.open("StudentData.txt");
		if (file.good())
		{

		}
		else
		{

			x.open("StudentData.txt");
			cout << "problem";
		}
		file.close();
		x.close();


	}





};







void main()
{
	Managment x;
	bool allow;
	allow = x.Login();
	if (allow == true)
	{

		string deleteentry;
		string name;
		string enroll;
		string prog;
		string clss;
		int regno;
		char select;
		do
		{
		start:
			system("cls");
			x.check();
			cout << "Student Managment System\n\n\n";
			cout << "1)Add Student\n2)Delete Student\n3)Edit Student\n4)View Student\n5)Search records\n6)Sort records\n7)Exit\n\n";
			cout << "enter option number :";
			cin >> select;
			switch (select)
			{
			case '1':
				cin.ignore();
				cout << "enter name : ";
				getline(cin, name);
				cout << "enter enrollment : ";
				cin >> enroll;
				cout << "enter class : ";
				cin >> clss;
				cout << "enter program : ";
				cin >> prog;
				cout << "enter registration number : ";
				cin >> regno;
				x.ReadFromDisk();
				x.AddStudent(x.convert(name), enroll, clss, regno, prog);
				x.WriteToDisk();
				x.ReadFromDisk();

				break;

			case '2':

				cout << "enter a rollnumber to delete from the list :";
				cin >> enroll;
				x.ReadFromDisk();
				x.delete_entry(enroll);
				x.WriteToDisk();
				x.ReadFromDisk();
				break;


			case '3':
				cout << "\nenter details to edit (when regno=0 it does no change ,when any other value=null it does not change  \n";
				x.ReadFromDisk();
				x.editstudent(enroll);
				x.WriteToDisk();
				x.ReadFromDisk();




			case '4':
				x.ReadFromDisk();
				x.ViewStudent();
				break;
				goto start;

			case '5':
				x.ReadFromDisk();
				x.dynamicview();
				break;

			case '6':
				x.ReadFromDisk();
				x.SortFileBy();
				x.WriteToDisk();
				break;
			case '7':
				exit(0);
				break;

			}


			cout << "\n\ndo you want to continue :";
			cin >> select;

		} while (select == 'y');



	}
	else
	{
		cout << "\nwrong password entered\n";
		cout << "\nprogram is exiting .....";
	}


	cout << "exiting program .....";
	_getch();
}
