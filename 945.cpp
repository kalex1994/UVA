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

class container
{
private:
	int MAX_CAPACITY;
	int INDEX;
	vector<int> packages;
	int current_capacity;

public:
	container(int index, int max_capacity) :
	  INDEX(index),
	  MAX_CAPACITY(max_capacity)
	{
		current_capacity = max_capacity;
	}

	container() :
	  INDEX(0),
	  MAX_CAPACITY(0)
	{
		current_capacity = 0;
	}

	void placeWeight(int weight)
	{
		packages.push_back(weight);
		current_capacity -= weight;
	}

	int getIndex() const
	{
		return INDEX;
	}

	int getMaxCapacity() const
	{
		return MAX_CAPACITY;
	}

	int getCurrentCapacity() const
	{
		return current_capacity;
	}

	int size() const
	{
		return (int)packages.size();
	}

	int& operator[](int position)
	{
		return packages[position];
	}

	void operator=(const container &other)
	{
		MAX_CAPACITY = other.MAX_CAPACITY;
		INDEX = other.INDEX;
		packages = other.packages;
		current_capacity = other.current_capacity;
	}
};

class ship
{
private:
	vector<container> containers;
	vector<int> weights;

	vector<container> getSmallestContainers(vector<container> &c)
	{
		vector<container> temp;
		int min;
		for(int i = 0; i < (int)c.size(); ++i)
			if (i == 0) min = c[i].size();
			else
				if (c[i].size() < min)
					min = c[i].size();
		for(int i = 0; i < (int)c.size(); ++i)
			if (c[i].size() == min)
				temp.push_back(c[i]);
		return temp;
	}

	vector<container> getGreatestCapacityContainers(vector<container> &c)
	{
		vector<container> temp;
		int max;
		for(int i = 0; i < (int)c.size(); ++i)
			if (i == 0) 
				max = c[i].getCurrentCapacity();
			else
				if (c[i].getCurrentCapacity() > max)
					max = c[i].getCurrentCapacity();

		for(int i = 0; i < (int)c.size(); ++i)
			if (c[i].getCurrentCapacity() == max)
				temp.push_back(c[i]);

		return temp;
	}

	bool loadPackage(int _weight)
	{
		vector<container> temp0 = getSmallestContainers(containers);
		vector<container> temp = getGreatestCapacityContainers(temp0);

		if (temp[0].getCurrentCapacity() >= _weight)
		{
			for(int i = 0; i < (int)containers.size(); ++i)
				if (containers[i].getIndex() == temp[0].getIndex())
				{
					containers[i].placeWeight(_weight);
					return true;
				}
		}
		return false;
	}

	int getMaxSize()
	{
		int max;
		for(int i = 0; i < (int)containers.size(); ++i)
			if (i == 0)
				max = containers[i].size();
			else
				if (containers[i].size() > max)
					max = containers[i].size();
		return max;
	}

	int getCargoWeight()
	{
		int sum = 0;
		for(int i = 0; i < (int)containers.size(); ++i)
			for(int j = 0; j < containers[i].size(); ++j)
				sum += containers[i][j];
		return sum;
	}

	int getShipCapacity()
	{
		int sum = 0;
		for(int i = 0; i < (int)containers.size(); ++i)
			sum += containers[i].getMaxCapacity();
		return sum - getCargoWeight();
	}

	int getUnloadedWeight()
	{
		int sum = 0;
		for(int i = 0; i < (int)weights.size(); ++i)
			sum += weights[i];
		return sum - getCargoWeight();
	}

public:
	void loadPackages()
	{
		for(int i = 0; i < (int)weights.size(); ++i)
			if (loadPackage(weights[i]) == false)
				break;
	}

	friend istream &operator >>(istream &input, ship &_ship)
	{
		int containerCount;
		if (input >> containerCount)
		{
			_ship.containers.clear();
			_ship.weights.clear();

			int capacity;
			for(int i = 1; i <= containerCount; ++i)
			{
				input >> capacity;
				_ship.containers.push_back( container(i, capacity) );
			}

			int weightCount, weight;
			input >> weightCount;
			while(weightCount--)
			{
				input >> weight;
				_ship.weights.push_back(weight);
			}
		}		
		return input;
	}

	friend ostream &operator <<(ostream &output, ship &_ship)
	{
		int maxSize = _ship.getMaxSize();

		for(int j = maxSize - 1; j >= 0; --j)
		{
			for(int i = 0; i < (int)_ship.containers.size(); ++i)
			{
				if (i > 0) output << ' ';
				if (j >= _ship.containers[i].size()) output << ':';
				else output << _ship.containers[i][j];
			}
			output << endl;
		}
		for(int i = 0; i < 2 * _ship.containers.size() - 1; ++i)
			output << '=';
		output << endl;
		for(int i = 1; i <= _ship.containers.size(); ++i)
		{
			if (i > 1) output << ' ';
			output << i;
		}
		output << endl << endl;
		output << "cargo weight: " << _ship.getCargoWeight() << endl;
		output << "unused weight: " << _ship.getShipCapacity() << endl;
		output << "unloaded weight: " << _ship.getUnloadedWeight() << endl;
		return output;
	}
};

int main()
{
	//freopen("c:\in.txt","r",stdin);
	//freopen("c:\out.txt","w",stdout);
	
	ship s;
	bool isFirst = true;
	while(cin >> s)
	{
		s.loadPackages();
		if (isFirst) isFirst = false;
		else cout << endl;
		cout << s;
	}
	return 0;
}


