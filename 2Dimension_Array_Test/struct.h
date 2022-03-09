#pragma once
#include "global.h"

struct fVec2
{
	float x;
	float y;

public:
	float Lenght()
	{
		return sqrt(x * x + y * y);
	}

	fVec2& normalize()
	{
		float fLen = Lenght();

		assert(fLen != 0.f);

		x /= fLen;
		y /= fLen;

		return *this;
	}

public:
	fVec2& operator = (POINT _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}

	fVec2 operator + (fVec2 _vOther)
	{
		return fVec2(x + _vOther.x, y + _vOther.y);
	}

	void operator += (fVec2 _vOther)
	{
		x += _vOther.x;
		y += _vOther.y;
	}

	fVec2 operator - (fVec2 _vOther)
	{
		return fVec2(x - _vOther.x, y - _vOther.y);
	}

	fVec2 operator * (fVec2 _vOther)
	{
		return fVec2(x * _vOther.x, y * _vOther.y);
	}

	fVec2 operator * (int _i)
	{
		return fVec2(x * (float)_i, y * (float)_i);
	}

	fVec2 operator * (float _f)
	{
		return fVec2(x * _f, y * _f);
	}

	fVec2 operator / (fVec2 _vOther)
	{
		assert(!(0.f == _vOther.x || 0.f == _vOther.y));
		return fVec2(x / _vOther.x, y / _vOther.y);
	}

	fVec2 operator / (float _f)
	{
		assert(!(0.f == _f));
		return fVec2(x / _f, y / _f);
	}

public:
	fVec2()
		: x(0.f)
		, y(0.f)
	{}

	fVec2(float _x, float _y)
		: x(_x)
		, y(_y)
	{}

	fVec2(int _x, int _y)
		: x((float)_x)
		, y((float)_y)
	{}

	fVec2(const POINT& _pt)
		: x((float)_pt.x)
		, y((float)_pt.y)
	{}
};


//----------------------------------------------------------------------------------------------


struct iVec2
{
	int x;
	int y;

public:
	iVec2 operator + (iVec2 _vOther)
	{
		return iVec2(x + _vOther.x, y + _vOther.y);
	}

	void operator += (iVec2 _vOther)
	{
		x += _vOther.x;
		y += _vOther.y;
	}

	iVec2 operator - (iVec2 _vOther)
	{
		return iVec2(x - _vOther.x, y - _vOther.y);
	}

	iVec2 operator * (iVec2 _vOther)
	{
		return iVec2(x * _vOther.x, y * _vOther.y);
	}

	iVec2 operator * (int _i)
	{
		return iVec2(x * _i, y * _i);
	}

	iVec2 operator / (iVec2 _vOther)
	{
		assert(!(0 == _vOther.x || 0 == _vOther.y));
		return iVec2(x / _vOther.x, y / _vOther.y);
	}

public:
	iVec2()
		: x(0)
		, y(0)
	{}

	iVec2(int _x, int _y)
		: x(_x)
		, y(_y)
	{}
};