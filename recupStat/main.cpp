using namespace std;

#include <iostream>

#include "modeles.h"
#include "statHandler.h"

int main(int argc,char** argv)
{ 
  statHandler sh;
  cout<<sh.getAllCpu().front().user<<endl;
  
  return 0;
}
