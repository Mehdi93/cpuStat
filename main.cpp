using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "modeles.h"

template<typename T> 
void setData(T str, string ligne) //parse un string et rempli une structure/variable avec les données correspondantes
{ 
    int *ptr = (int*)str;
    string buff;
    stringstream ss(ligne);
    
    ss >> buff;
    
    //on boucle sur le nombre de variable dans notre structure/variable
    for(int i=0;i<(sizeof(*str)/sizeof(long int));i++)
    {
      ss >> buff;
      ptr[i] = atoi(buff.c_str());
    }  
}

int main(int argc,char** argv)
{
  fstream statFichier;
  string ligne;
  
  statFichier.open("test.txt",ios::in); //ouverture du fichier
  
  //on teste que le fichier existe
  if(!statFichier.is_open())
  {
    cout<<"Fichier stat inexistant"<<endl;
  }
  else
  {
    string nomLigne;
    
    //lecture du fichier de stat
    getline(statFichier,ligne);
    while (!statFichier.eof())
    {
      nomLigne = ligne.substr(0,ligne.find(' '));
      
      if(nomLigne.find("cpu")!=nomLigne.npos)
      {
      
      }
      else if(nomLigne.find("ctxt")!=nomLigne.npos)
      {
        long int *ctxt = new long int;
        setData(ctxt,ligne);
        cout<<*ctxt<<endl;
      }
      
      getline(statFichier,ligne);
    }
   
    /*getline(statFichier,ligne);
    cpuStat *cpuTest = new cpuStat;
    setData(cpuTest,ligne);*/
  }
  
  statFichier.close();
  
  return 0;
}
