#pragma once

#include "CommonSearcher.h"

template <class T>
class AStar : public CommonSearcher<T>
{

public:
	virtual Solution<T> search()
	{
		cout << "AStar SEARCH" << endl;
		return Solution<T>();
	};
};
