#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
#include <cctype>
#include <stack>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include <numeric>
#include <deque>
#include <map>
#include <iterator>
#include <cassert>
#include <list>
#include <functional>
#include <bitset>
#include <array>
#include <regex>
#include <cfloat>
#ifndef ONLINE_JUDGE
#include "debug_macros.h"
#endif
#endif
using namespace std;

struct point
{
	double x, y;
	point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

struct vec
{
	double x, y;
	vec(const point& a, const point& b) : x(b.x - a.x), y(b.y - a.y) {}
};

struct shape
{
	virtual bool contains(const point& p) const = 0;
};

struct rectangle : public shape
{
	point topleft, bottomright;
	rectangle() {}
	rectangle(double ax, double ay, double bx, double by) : topleft(ax, ay), bottomright(bx, by) {}
	bool contains(const point& p) const
	{
		return p.x > topleft.x && p.x < bottomright.x && p.y < topleft.y && p.y > bottomright.y;
	}
};

struct circle : public shape
{
	point center;
	double r;
	circle() {}
	circle(double ax, double ay, double r) : center(ax, ay), r(r) {}
	bool contains(const point& p) const
	{
		return hypot(p.x - center.x, p.y - center.y) < r;
	}
};

double cross_product(const vec& a, const vec& b)
{
	return a.x * b.y - a.y * b.x;
}

double ccw(const point& p, const point& q, const point& r)
{
	return cross_product(vec(p, q), vec(p, r));
}

struct triangle : public shape
{
	point a, b, c;
	triangle() {}
	triangle(double ax, double ay, double bx, double by, double cx, double cy) : a(ax, ay), b(bx, by), c(cx, cy) {}
	bool contains(const point& p) const
	{
		return ccw(a, b, p) * ccw(a, b, c) > 0 &&
			   ccw(b, c, p) * ccw(b, c, a) > 0 &&
			   ccw(c, a, p) * ccw(c, a, b) > 0;
	}
};

const int MAXN = 10;
int n;
shape* shapes[MAXN];

void read_input()
{
	double ax, ay, bx, by, cx, cy, r;
	char ch;

	while(cin >> ch && ch != '*')
	{
		switch (ch)
		{
			case 'r':
				cin >> ax >> ay >> bx >> by;
				shapes[n++] = new rectangle(ax, ay, bx, by);
				break;
			case 'c':
				cin >> ax >> ay >> r;
				shapes[n++] = new circle(ax, ay, r);
				break;
			case 't':
				cin >> ax >> ay >> bx >> by >> cx >> cy;
				shapes[n++] = new triangle(ax, ay, bx, by, cx, cy);
				break;
		}
	}
}

void solve()
{
	point p;
	int test = 1;

	while(cin >> p.x >> p.y)
	{
		if (fabs(p.x - 9999.9) < DBL_EPSILON && fabs(p.y - 9999.9) < DBL_EPSILON)
			break;
		bool found = false;
		for(int i = 0; i < n; ++i)
			if (shapes[i]->contains(p))
			{
				printf("Point %d is contained in figure %d\n", test, i + 1);
				found = true;
			}
		if (!found)
			printf("Point %d is not contained in any figure\n", test);
		++test;
	}

	for(int i = 0; i < n; ++i)
		delete shapes[i];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\IN.txt", "r", stdin);
	freopen("E:\\OUT.txt", "w", stdout);
#endif

	read_input();
	solve();
}