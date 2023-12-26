#pragma once

#include "CommonSearcher.h"

template <class T>
class BFS : public CommonSearcher<T>
{

public:
	virtual Solution<T> search()
	{
		cout << "BFS SEARCH" << endl;
		return Solution<T>();
	};
};
