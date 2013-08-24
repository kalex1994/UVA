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

struct Array
{
	vector<int> C;
	int dimensions;

	Array() : dimensions(0) {};

	Array(int baseAdress, int elementSize, int dimensions, vector<int> &L, vector<int> &U)
	{
		this->dimensions = dimensions;
		C.resize(dimensions + 1);
		C[dimensions] = elementSize;

		for(int d = dimensions - 1; d > 0; --d)
			C[d] = C[d + 1] * ( U[d + 1] - L[d + 1] + 1 );

		C[0] = baseAdress;

		for(int i = 1; i <= dimensions; ++i)
			C[0] -= C[i] * L[i];
	}
};

map<string, Array> arrays;
int N, M;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c:\\in.txt","r",stdin);
	freopen("c:\\out.txt","w",stdout);
#endif

	string name;
	int baseAdress, elementSize, dimensions, lower, upper;
	vector<int> L, U;

	cin >> N >> M;
	while(N--)
	{
		cin >> name >> baseAdress >> elementSize >> dimensions;
		L.resize(dimensions + 1);
		U.resize(dimensions + 1);

		for(int i = 1; i <= dimensions; ++i)
		{
			cin >> lower >> upper;
			L[i] = lower;
			U[i] = upper;
		}

		arrays[name] = Array(baseAdress, elementSize, dimensions, L, U);
	}
	while(M--)
	{
		cin >> name;
		vector<int> indexes(arrays[name].dimensions + 1);

		for(int i = 1; i <= arrays[name].dimensions; ++i)
			cin >> indexes[i];

		int adress = arrays[name].C[0];
		for(int i = 1; i <= arrays[name].dimensions; ++i)
			adress += arrays[name].C[i] * indexes[i];

		cout << name << "[";
		for(int i = 1; i <= arrays[name].dimensions; ++i)
		{
			if (i > 1) cout << ", ";
			cout << indexes[i];
		}
		cout << "] = " << adress << endl;
	}
	return 0;
}




