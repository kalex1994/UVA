#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<bitset>
#include<map>
#include<set>
#include<limits>
#include<sstream>
#include<stack>
#include<vector>
#include<algorithm>
#include<list>
#include<iomanip>
#include<queue>

using namespace std;

struct Employee
{
	string departmentName, title, firstName, lastName, streetAdress, homePhone, workPhone, campusMailbox;

	Employee(string _departmentName, string raw_data)
	{
		departmentName = _departmentName;

		char *data = (char *)raw_data.c_str();
		title = strtok(data, ",");
		firstName = strtok(NULL, ",");
		lastName = strtok(NULL, ",");
		streetAdress = strtok(NULL, ",");
		homePhone = strtok(NULL, ",");
		workPhone = strtok(NULL, ",");
		campusMailbox = strtok(NULL, ",");
	}
};

vector<Employee> employees;
const string dash = "----------------------------------------";

bool cmpEmployees(const Employee &a, const Employee &b)
{
	return a.lastName < b.lastName;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	string line, departmentName;
	int departments;

	cin >> departments;
	cin.ignore(100,'\n');

	while(departments--)
	{
		getline(cin, departmentName);
		while (getline(cin, line) && line.size() != 0)
			employees.push_back(Employee(departmentName, line));
	}
	
	sort(employees.begin(), employees.end(), cmpEmployees);

	for(int i = 0; i < (int)employees.size(); ++i)
	{
		cout << dash << endl;
		cout << employees[i].title << " " << employees[i].firstName << " " << employees[i].lastName << endl;
		cout << employees[i].streetAdress << endl;
		cout << "Department: " << employees[i].departmentName << endl;
		cout << "Home Phone: " << employees[i].homePhone << endl;
		cout << "Work Phone: " << employees[i].workPhone << endl;
		cout << "Campus Box: " << employees[i].campusMailbox << endl;
	}
	return 0;
}




