#pragma once
#include "global.h"

class CItem
{
private:
	string name;
	int at;
	int price;

public:
	void set(string _name, int _at, int _price);

public:
	string get_name() { return string(name); };
	int get_at() { return at; };
	int get_price() { return price; };

public:
	CItem();
	CItem(string _name, int _at, int _price);
	~CItem();
};

