#pragma once

#include "Solution.h"

template <class T>
class Searcher
{
public:
	virtual Solution<T> search() = 0;
	virtual int getNumberOfNodesEvaluated() = 0;
};

