using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "modeles.h"

/*void setData(int* ptr, int size, string ligne)
{
    string buff;
    stringstream ss(ligne);
    
    ss >> buff;
    
    //on boucle sur le nombre de variable dans notre structure
    for(int i=0;i<(sizeof(cpuStat)/4);i++)
    {
      ss >> buff;
      ptr[i] = atoi(buff.c_str());
    }  
}*/

template<typename T> 
void setData(T str, string ligne) 
{ 
    int *ptr = (int*)str;
    string buff;
    stringstream ss(ligne);
    
    ss >> buff;
    
    //on boucle sur le nombre de variable dans notre structure
    for(int i=0;i<(sizeof(*str)/4);i++)
    {
      ss >> buff;
      ptr[i] = atoi(buff.c_str());
    }  
}

int main(int argc,char** argv)
{
  fstream statFichier;
  char tmp;
  string ligne;
  int nbLignes = 0; //nombre de lignes d'informations dans le fichier stat
  vector<int> testlist;
  
  statFichier.open("test.txt",ios::in); //ouverture du fichier
  
  //on teste que le fichier existe
  if(!statFichier.is_open())
  {
    cout<<"Fichier stat inexistant"<<endl;
  }
  else
  {
    /*// A TESTER
    while (statFichier >> buf)
    {
      getline(statFichier,ligne);
      cpuStat *cpuTest = new cpuStat;    
      setData((int*)cpuTest,sizeof(cpuStat),ligne);
    }*/
    
    
    getline(statFichier,ligne);
    cpuStat *cpuTest = new cpuStat;    
    //setData((int*)cpuTest,sizeof(cpuStat),ligne);
    setData(cpuTest,ligne);
    
    cout<<cpuTest->user<<endl;
    
    
  }
  
  statFichier.close();
  
  return 0;
}
