#pragma once
#include "subscriber.h"
#include <vector>
#include <algorithm>

class publisher
{
private:
   std::vector<subscriber*> subscribers; 

public:
   void subscribe(subscriber* s);
   void unsubscribe(subscriber* s);
   virtual void notify();
   virtual ~publisher() = 0; 

};