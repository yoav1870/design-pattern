#include "publisher.h"



publisher ::~publisher() {};


void publisher::subscribe(subscriber* s)
{
   if(s != nullptr){
       auto it = std::find(subscribers.begin(),subscribers.end(),s);
       if(it != subscribers.end()){
           return;
       }
       else{
           subscribers.push_back(s);
       }
   }
}

void publisher::unsubscribe(subscriber* s)
{
   if(s != nullptr){
       auto it = std::find(subscribers.begin(),subscribers.end(),s);
       if(it != subscribers.end()){
           subscribers.erase(it);
       }
   }
}

void publisher::notify()
{
   for(auto it = subscribers.begin(); it != subscribers.end(); it++){
       (*it)->update();
   }
}