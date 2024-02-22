#include "stdafx.h"
#include"iostream"
#include"conio.h"
#include"fstream"
#include "string"
#include "iomanip"
#include"Windows.h"
using namespace std;
//#include "LOGIN.h"
//#include "Employee.h"

//Employee Header File
//Login header File
class Login {
	string password;
public:
	void SetPassword(string PASSWORD) {
		password = PASSWORD;
	}
	string GetPassword() {
		return password;
	}
	void WriteData();
	void ReadData();
};

void Login::WriteData() {
	ofstream login("LOGIN.txt", ios::binary | ios::out);
	login.write((char*)this, sizeof(*this));
	login.close();
};
void Login::ReadData() {
	ifstream login("LOGIN.txt", ios::binary | ios::in);
	login.read((char*)this, sizeof(*this));
	login.close();
};



class Employee :public Login {
private:
	int Employee_ID = 0;
	int age, attendence = 0, leavesaccepted = 0, leavesrejected = 0;
	string name;
	string address, leavesDate = "", leaveStatus;
	string email;
	int phone;
	int salary = 50000;

	int static r;
public:
	Employee() {
		r++;
		ifstream Employ("Employee.txt", ios::binary);
		if (!Employ) { Employee_ID = Employee_ID + r; }
		else {
			Employ.read((char*)this, sizeof(*this));
			while (!Employ.eof()) {
				Employ.read((char*)this, sizeof(*this));
			}
			Employee_ID = Employee_ID + r;
		}
	};
	void SetName(string NAME) {
		name = NAME;
	};
	void SetAddress(string ADDRESS) {
		address = ADDRESS;
	};
	void SetEmail(string EMAIL) {
		email = EMAIL;
	};
	void SetPhone(int Phone) {
		phone = Phone;
	};
	void SetAge(int AGE) {
		age = AGE;
	};
	void SetLeavesAccepted(int A) {
		leavesaccepted = leavesaccepted + A;
	}
	int GetLeavesaccepted() {
		return leavesaccepted;
	}						  
	void SetLeavesRejected(int R) {
		leavesrejected = leavesrejected + R;
	}						  
	int GetLeavesRejected() { 
		return leavesrejected;
	}						  
	void SetLeaveDate(string L) {
		leavesDate = L;		  
	}
	string GetLeaveDate() {
		return leavesDate;
	}void SetLeaveStatus(string L) {
		leaveStatus = L;
	}
	string GetLeaveStatus() {
		return leaveStatus;
	}
	int GetID();
	Login::SetPassword;
	Login::GetPassword;
	string GetName() {
		return name;
	}
	int GetAttendance() {
		return attendence;
	}
	string GetAddress() {
		return address;
	}
	string GetEmail() {
		return email;
	}
	int GetPhone() {
		return phone;
	}
	int GetAge() {
		return age;
	}
	int GetSalary() {
		return salary;
	}
	void heading() {
		system("cls");
		cout << "ID" << setw(15) << "Name" << setw(15) << "Address" << setw(15) << "Email" << setw(15) << "Phone" << setw(15) << "Age" << setw(15) << "Total Salary" << setw(15) << "Attendance" << setw(15) << "Leave Date" << setw(15) << "Leave Status" << setw(15) << "Leaves" << setw(15) << "Leaves Rejected" << setw(15) << "Leaves Total" << setw(25) << "This month salary\n";
	}
	void heading1() {
		system("cls");
		cout << "ID" << setw(15) << "Name" << setw(15) << "Address" << setw(15) << "Email" << setw(15) << "Phone" << setw(15) << "Age" << setw(15) << "Total Salary" << setw(15) << "Attendance" << setw(15) << "Leaves" << setw(25) << "This month salary\n";
	}
	void SetAttandence() {
		attendence = attendence + 1;
	}
	void MENU();
	void Menu(string l);
	void search();
	void readData();
	void writeData();
	void Delete();
	void update();
	void update2();
};

int Employee::r = 0;
int Employee::GetID() {
	return Employee_ID;
}

void Employee::MENU() {
	int ch = 0;
	do {
		int opt;
		string NAME;
		string ADDRESS;
		string EMAIL;
		int PHONE;
		int AGE;
		string PASSWORD;
		system("cls");
		cout << "0.Check notification.\n";
		cout << "\n\t***************MENU****************""\n\t*                                 *""\n\t*         1. Enter Employe        *""\n\t*         2. Show Record          *""\n\t*         3. Delete Record        *""\n\t*         4. Update Record        *""\n\t*         5. Search Record        *""\n\t*         6. Exit                 *""\n\t*                                 *""\n\t***********************************"; "\n\t  Please choose an option\t";
		cin >> opt;
		switch (opt) {
		case 1:
			system("cls");
			cout << "\n\t************Enter Data*************" << "\n\t*                                 *" << "\n\t*      Enter Employe Password         *" << "\n\t*                                 *" << "\n\t***********************************\n";
			cin >> PASSWORD;
			SetPassword(PASSWORD);
			cout << "\n\t************Enter Data*************" << "\n\t*                                 *" << "\n\t*      Enter Employe Name         *" << "\n\t*                                 *" << "\n\t***********************************\n";
			cin.ignore();
			getline(cin, NAME);
			SetName(NAME);	system("cls");
			cout << "\n\t************Enter Data*************""\n\t*                                 *""\n\t*     Enter Employe Address       *""\n\t*                                 *""\n\t***********************************\n";
			getline(cin, ADDRESS);
			SetAddress(ADDRESS); system("cls");
			cout << "\n\t************Enter Data*************""\n\t*                                 *""\n\t*      Enter Employe Email        *""\n\t*                                 *""\n\t***********************************\n";
			getline(cin, EMAIL);
			SetEmail(EMAIL); system("cls");
			cout << "\n\t************Enter Data*************""\n\t*                                 *""\n\t*      Enter Employe Phone        *""\n\t*                                 *""\n\t***********************************\n";
			cin >> PHONE;
			SetPhone(PHONE); system("cls");
			cout << "\n\t************Enter Data*************""\n\t*                                 *""\n\t*      Enter Employe Age          *""\n\t*                                 *""\n\t***********************************\n";
			cin >> AGE;
			SetAge(AGE);
			writeData();
			break;
		case 2:
			heading1();
			readData();
			break;
		case 3:
			Delete();
			break;
		case 4:
			update();
			break;
		case 5:
			search();
			break;
		case 6:
			exit(0);
			break;
		case 0:
			int op;
			ifstream Employ("Employee.txt", ios::binary);
			Employ.read((char*)this, sizeof(*this));
			cout << "ID\t\tRequest for Leave\n";
			while (!Employ.eof()) {
				cout << GetID() << "\t\t" << GetLeaveDate() << endl;
				Employ.read((char*)this, sizeof(*this));
			}
			Employ.close();
			cout << "\n0-For response : ";
			cin >> op;
			if (op == 0) {
				cout << "Goto Leave update for Response :\n";
				update();
			}
		}
		cout << "\nPress 1 for coninue.\n";
		cin >> ch;
	} while (ch == 1);
}
void Employee::Menu(string l) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 0;
	heading();
	cout << GetID() << setw(15) << GetName() << setw(15) << GetAddress() << setw(15) << GetEmail() << setw(15) << GetPhone() << setw(15) << GetAge() << setw(15) << GetSalary() << setw(15) << GetAttendance() << setw(15) << GetLeaveDate();
	if (l == "Accepted") {
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		cout << setw(15) << GetLeaveStatus();
	}
	else if (l == "Rejected") {
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << setw(15) << GetLeaveStatus();
	}
	else if (l == "Pending") {
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);
		cout << setw(15) << GetLeaveStatus();
	}
	else {
		cout << setw(15) << GetLeaveStatus();
	}
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << setw(15) << GetLeavesaccepted() << setw(15) << GetLeavesRejected() << setw(15) << GetLeavesaccepted() + GetLeavesRejected() << setw(15) << GetSalary() / 30 * (GetAttendance() + (GetLeavesaccepted() / 2)) << endl;
	cout << "\n\t***********************************""\n\t*                                 *""\n\t*    Do you Want to Update press  *\n\t*         YES(1)  No(2)           *""\n\t*                                 *""\n\t***********************************\n";
	cin >> i;
	if (i == 1) { update2(); }
	else { exit(0); }
}
void Employee::writeData() {
	attendence = 0;
	ofstream Employ("Employee.txt", ios::binary | ios::app);
	Employ.write((char*)this, sizeof(*this));
	Employ.close();
}
void Employee::readData() {
	ifstream Employ("Employee.txt", ios::binary);
	Employ.read((char*)this, sizeof(*this));
	while (!Employ.eof()) {
		cout << GetID() << setw(15) << GetName() << setw(15) << GetAddress() << setw(15) << GetEmail() << setw(15) << GetPhone() << setw(15) << GetAge() << setw(15) << GetSalary() << setw(15) << GetAttendance() << setw(15) << GetSalary() / 30 * GetAttendance() << endl;
		Employ.read((char*)this, sizeof(*this));
	}
	Employ.close();
}
void Employee::Delete() {
	ifstream Employ("Employee.txt", ios::binary | ios::in);
	ofstream T("temp.txt", ios::binary | ios::app);
	int ID, I = 0;
	cout << "Enter ID you want to Delete.\n";
	cin >> ID;
	Employ.read((char*)this, sizeof(*this));
	while (!Employ.eof()) {
		if (this->GetID() == ID) {
			I = 1;
		}
		else { T.write((char*)this, sizeof(*this)); }
		Employ.read((char*)this, sizeof(*this));
	}
	if (I == 1) { cout << "Record of ID : " << ID << " Deleted."; }
	else { cout << "Record not Found"; }
	Employ.close();
	T.close();
	remove("Employee.txt");
	rename("temp.txt", "Employee.txt");
}
void Employee::update2() {

	int count = 0, ch, I = 5;
	string NAME;
	string ADDRESS;
	string EMAIL;
	int PHONE = 0, AGE;
	string Pass;
	char CH;
	fstream Employ("Employee.txt", ios::binary | ios::in | ios::out | ios::ate);
	Employ.seekg(0, ios::beg);
	system("cls");
	cout << "\n\t***********************************""\n\t*                                 *""\n\t*   Enter Password for Update     *""\n\t*                                 *""\n\t***********************************\n";
	while (true) {
		CH = _getch();
		if (CH == 13) {
			break;
		}
		else if (CH == '\b') {
			Pass.pop_back();
		}
		else {
			Pass.push_back(CH);
		}
		cout << "*";
	}
	Employ.read((char*)this, sizeof(*this));
	while (!Employ.eof()) {
		count++;
		if (this->GetPassword() == Pass) {
			int postion((count - 1) * sizeof(*this));
			Employ.seekp(postion);
			system("cls");
			cout << "\n\t*************Update****************""\n\t*                                 *""\n\t*         1. Update Address       *""\n\t*         2. Update Phone         *""\n\t*         3. Update Email         *""\n\t*         4. Update Date of birth *""\n\t*         5. Update Password      *""\n\t*                                 *""\n\t***********************************"; "\n\t  Please choose an option\t";
			cout << "6. Apply for Leave.\n";
			cin >> ch;
			switch (ch) {

			case 1:
				cout << "Enter Address.\n";
				cin.ignore();
				getline(cin, ADDRESS);
				SetAddress(ADDRESS);
				break;
			case 2:
				cout << "Enter Phone.\n";
				cin >> PHONE;
				SetPhone(PHONE);
				break;
			case 3:
				cout << "Enter Email.\n";
				cin.ignore();
				getline(cin, EMAIL);
				SetEmail(EMAIL);
				break;
			case 4:
				cout << "Enter Date of Birth.\n";
				cin >> AGE;
				SetAge(AGE);
				break;
			case 5:
				cout << "Enter New Password.\n";
				cin >> Pass;
				Login::SetPassword(Pass);
				break;
			case 6:
				string Lve;
				cout << "Enter Date For Leave.\n";
				cin >> Lve;
				SetLeaveDate(Lve);
				SetLeaveStatus("Pending");
				break;
			}
			Employ.write((char*)this, sizeof(*this));
			I = 1;
			break;
		}
		Employ.read((char*)this, sizeof(*this));

	}
	if (I == 1) {
		cout << "Record is Updated.";
	}
	Employ.close();
}
void Employee::update() {
	int uid = 0, count = 0, ch, I = 5;
	string NAME, pass;
	string ADDRESS;
	string EMAIL;
	int PHONE;
	int AGE;
	fstream Employ("Employee.txt", ios::binary | ios::in | ios::out | ios::ate);
	Employ.seekg(0, ios::beg);
	cout << "Enter ID you want to Update.\n";
	cin >> uid;
	Employ.read((char*)this, sizeof(*this));
	while (!Employ.eof()) {
		count++;
		if (this->GetID() == uid) {
			int postion((count - 1) * sizeof(*this));
			Employ.seekp(postion);
			system("cls");
			cout << "\n\t*************Update****************""\n\t*                                 *""\n\t*         1. Update Name          *""\n\t*         2. Update Address       *""\n\t*         3. Update Phone         *""\n\t*         4. Update Email         *""\n\t*         5. Update Date of birth *""\n\t*         6. Attendance           *""\n\t*                                 *""\n\t***********************************"; "\n\t  Please choose an option\t";
			cout << "0-Leaves Update";
			cin >> ch;
			switch (ch) {
			case 1:
				cout << "Enter Employe Name.\n";
				cin.ignore();
				getline(cin, NAME);
				SetName(NAME);
				break;
			case 2:
				cout << "Enter Employe Address.\n";
				cin.ignore();
				getline(cin, ADDRESS);
				SetAddress(ADDRESS);
				break;
			case 3:
				cout << "Enter Employe Phone.\n";
				cin >> PHONE;
				SetPhone(PHONE);
				break;
			case 4:
				cout << "Enter Employe Email.\n";
				cin.ignore();
				getline(cin, EMAIL);
				SetEmail(EMAIL);
				break;
			case 5:
				cout << "Enter Employe Date of Birth.\n";
				cin >> AGE;
				SetAge(AGE);
				break;
			case 6:
				SetAttandence();
				break;
			case 7:
				cout << "Enter Employe Password .\n";
				cin >> pass;
				SetPassword(pass);
				break;
			case 8:
				exit(0);
				break;
			case 0:
				int ch4;
				cout << "1-For Accept\t\t2-For Reject";
				cin >> ch4;
				if (ch4 == 1) {
					SetLeaveStatus("Accepted");
					SetLeaveDate("");
					SetLeavesAccepted(1);
				}
				if (ch4 == 2) {
					SetLeaveStatus("Rejected");
					SetLeaveDate("");
					SetLeavesRejected(1);
				}
				break;
			}
			Employ.write((char*)this, sizeof(*this));
			I = 1;
			break;
		}
		Employ.read((char*)this, sizeof(*this));

	}
	if (I == 1) {
		cout << "Record of ID : " << uid << " Updated.";
	}
	else {
		cout << "Record not Found";
	}
	Employ.close();
}
void Employee::search() {
	int sid;
	ifstream Employ("Employee.txt", ios::binary | ios::in);
	cout << "Enter ID you want to Search";
	cin >> sid;
	Employ.read((char*)this, sizeof(*this));
	while (!Employ.eof()) {
		if (sid == this->GetID()) {
			heading1();
			cout << GetID() << setw(15) << GetName() << setw(15) << GetAddress() << setw(15) << GetEmail() << setw(15) << GetPhone() << setw(15) << GetAge() << setw(15) << GetSalary() << setw(15) << GetAttendance() << setw(15) << (float)GetSalary() / 30 * GetAttendance() << endl;			break;
		}
		Employ.read((char*)this, sizeof(*this));
	}
	Employ.close();
}


















































int main()
{
	Employee E;
	Login L;
	
	int CH;
	cout << "\n\t**************LOGIN****************""\n\t*                                 *""\n\t*        1. Enter as Admin        *""\n\t*        2. Enter as Employee     *""\n\t*                                 *""\n\t***********************************";"\n\t  please choose an option\t";
	cin >> CH;
	if (CH == 1) {
		char op = 0;
		do {
			string PASSWORD;
			char ch;
		ifstream login("LOGIN.txt", ios::binary | ios::in);
		login.read((char*)&L, sizeof(L));
		if (!login) {
			system("cls");
			system("cls");
			cout << "\n\t**********Sigup As Admin***********""\n\t*                                 *""\n\t*        Enter Password           *""\n\t*                                 *""\n\t***********************************\n";
			while (true) {
				ch = _getch();
				if (ch == 13) {
					break;
				}
				else if (ch == '\b') {
					PASSWORD.pop_back();
				}
				else {
					PASSWORD.push_back(ch);
				}
				cout << "*";
			}
			L.SetPassword(PASSWORD);
			L.WriteData();
		}
		else {
			
				
				
				system("cls");
				cout << "\n\t**********Login As Admin***********""\n\t*                                 *""\n\t*        Enter Password           *""\n\t*                                 *""\n\t***********************************\n";
				while (true) {
					ch = _getch();
					if (ch == 13) {
						break;
					}
					else if (ch == '\b') {
						PASSWORD.pop_back();
					}
					else {
						PASSWORD.push_back(ch);
					}
					cout << "*";
				}	
				if (L.GetPassword() == PASSWORD) {
					
					E.MENU();
				}
				else {
					system("cls");
					cout << "\n\t*********Invalid Password**********""\n\t*                                 *""\n\t*      DO you want to continue    *""\n\t*         YES(y)  No(N)           *""\n\t*                                 *""\n\t***********************************\n";
				}
				cin >> op;
			} 
		}while (op == 'Y'|| op == 'y');
	}
	if (CH == 2) {
		string PASSWORD;
		char ch;
		int count = 0;
		ifstream Employ("Employee.txt", ios::binary);
		if (Employ) {
			system("cls");
			cout << "\n\t*******Login As Employee***********""\n\t*                                 *""\n\t*        Enter Password           *""\n\t*                                 *""\n\t***********************************\n";
			while (true) {
				ch = _getch();
				if (ch == 13) {
					break;
				}
				else if (ch == '\b') {
					PASSWORD.pop_back();
				}
				else {
					PASSWORD.push_back(ch);
				}
				cout << "*";
			}
			Employ.read((char*)&E, sizeof(E));
			while (!Employ.eof()) {
				count++;
				if (PASSWORD == E.GetPassword()) {
					system("cls");
					E.Menu(E.GetLeaveStatus());
					break;
				}
				Employ.read((char*)&E, sizeof(E));
			}
			Employ.close();
		}
		else {
			cout << "Employees not exist";
		}


		
	}
	_getch();
	return 0;
}
