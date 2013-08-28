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
#include<cfloat>

using namespace std;

struct Book
{
	string author, title;
	bool isBorrowed;

	Book(string _author, string _title)
	{
		this->author = _author;
		this->title = _title;
		this->isBorrowed = false;
	}
};

bool operator<(const Book &a, const Book &b)
{
	if (a.author != b.author) return a.author < b.author;
	return a.title < b.title;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	string line;
	vector<Book> books, returned;

	while(getline(cin, line) && line != "END")
	{
		int pos = line.find_last_of('"');
		string title(line, 0, pos + 1);
		string author(line, pos + 5);
		books.push_back( Book(author, title) );
	}

	sort(books.begin(), books.end());

	while(getline(cin, line) && line != "END")
	{
		string command(line, 0, 6);

		if (command == "SHELVE")
		{
			sort(returned.rbegin(), returned.rend());
			while(!returned.empty())
			{
				int pos = -1;
				for(int i = 0; i < (int)books.size(); ++i)
					if (books[i].isBorrowed == false && books[i] < returned.back())
						pos = i;
					
				if (pos == -1)
					cout << "Put " << returned.back().title << " first" << endl;
				else
					cout << "Put " << returned.back().title << " after " << books[pos].title << endl;

				for(int i = 0; i < (int)books.size(); ++i)
					if (books[i].title == returned.back().title)
						books[i].isBorrowed = false;
				returned.pop_back();
			}
			cout << "END" << endl;
		}
		else
		{
			string title(line, 7);
			
			if (command == "BORROW")
			{
				for(int i = 0; i < (int)books.size(); ++i)
					if (books[i].title == title)
						books[i].isBorrowed = true;
			}
			else
			{
				for(int i = 0; i < (int)books.size(); ++i)
					if (books[i].title == title)
						returned.push_back( Book(books[i].author, title) );
			}
		}
	}
	return 0;
}
