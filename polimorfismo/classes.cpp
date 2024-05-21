#include "classes.hpp"


int PolicyOne::Process(){
  //  try{
        m_tasks->erase(m_tasks->begin());
        //delete first entry in vector
   //     throw 600;
   // }
   // catch(600) {return 1;};
            
    
    return 0;
};




// ------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------



int PolicyTwo::Process(){

   // try{
        m_tasks->pop_back();
        //delete last entry in vector
    //    throw 600;
  //  }
   // catch(600) {return 1;};

    return 0;
};
