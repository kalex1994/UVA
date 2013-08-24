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

const string binary[] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};

int hashHexaDigit(char val)
{
	if (val >= '0' && val <= '9') return val - '0';
	return val - 'A' + 10;
}

string valueOf(string b)
{
	int v = 0;
	reverse(b.begin(), b.end());
	for(int i = 0; i < (int)b.size(); ++i)
		v += (b[i] == '1' ? (int)pow(2.0,(double)i) : 0);
	ostringstream oss;
	oss << v;
	return oss.str();
}

string formatValue(string mode1, string op1, string mode2 = "", string op2 = "", string mode3 = "", string op3 = "")
{
	string s1 = "", s2 = "", s3 = "";
	if (mode1 == "00") s1 += "R";
	else if (mode1 == "01") s1 += "$";
	else if (mode1 == "10") s1 += "PC+";
	s1 += valueOf(op1);

	if (mode2 == "") return s1;

	if (mode2 == "00") s2 += "R";
	else if (mode2 == "01") s2 += "$";
	else if (mode2 == "10") s2 += "PC+";
	s2 += valueOf(op2);

	if (mode3 == "") return s1 + "," + s2;

	if (mode3 == "00") s3 += "R";
	else if (mode3 == "01") s3 += "$";
	else if (mode3 == "10") s3 += "PC+";
	s3 += valueOf(op3);
	return s1 + "," + s2 + "," + s3;
}

void oneOperandInstruction(string name)
{
	string op = "";
	char ch;
	for(int i = 0; i < 4; ++i)
	{
		cin >> ch;
		op += binary[ hashHexaDigit(ch) ];
	}
	cout << name << " " << formatValue(op.substr(0,2),op.substr(2)) << endl;
}

void twoOperandInstruction(string name)
{
	string op1 = "", op2 = "";
	char ch;
	for(int i = 0; i < 4; ++i)
	{
		cin >> ch;
		op1 += binary[ hashHexaDigit(ch) ];
	}
	for(int i = 0; i < 4; ++i)
	{
		cin >> ch;
		op2 += binary[ hashHexaDigit(ch) ];
	}
	cout << name << " " << formatValue(op1.substr(0,2),op1.substr(2),op2.substr(0,2),op2.substr(2)) << endl;
}

void threeOperandInstruction(string name)
{
	string op1 = "", op2 = "", op3 = "";
	char ch;
	for(int i = 0; i < 4; ++i)
	{
		cin >> ch;
		op1 += binary[ hashHexaDigit(ch) ];
	}
	for(int i = 0; i < 4; ++i)
	{
		cin >> ch;
		op2 += binary[ hashHexaDigit(ch) ];
	}
	for(int i = 0; i < 4; ++i)
	{
		cin >> ch;
		op3 += binary[ hashHexaDigit(ch)];
	}
	cout << name << " " << formatValue(op1.substr(0,2),op1.substr(2),op2.substr(0,2),op2.substr(2),op3.substr(0,2),op3.substr(2)) << endl;
}

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);

	char ch;
	while(cin >> ch)
	{
		switch(ch)
		{
		case '0':
			twoOperandInstruction("ADD");
			break;
		case '1':
			twoOperandInstruction("SUB");
			break;
		case '2':
			twoOperandInstruction("MUL");
			break;
		case '3':
			twoOperandInstruction("DIV");
			break;
		case '4':
			twoOperandInstruction("MOV");
			break;
		case '5':
			oneOperandInstruction("BREQ");
			break;
		case '6':
			oneOperandInstruction("BRLE");
			break;
		case '7':
			oneOperandInstruction("BRLS");
			break;
		case '8':
			oneOperandInstruction("BRGE");
			break;
		case '9':
			oneOperandInstruction("BRGR");
			break;
		case 'A':
			oneOperandInstruction("BRNE");
			break;
		case 'B':
			oneOperandInstruction("BR");
			break;
		case 'C':
			threeOperandInstruction("AND");
			break;
		case 'D':
			threeOperandInstruction("OR");
			break;
		case 'E':
			threeOperandInstruction("XOR");
			break;
		case 'F':
			oneOperandInstruction("NOT");
			break;
		}
	}	
	return 0;
}


