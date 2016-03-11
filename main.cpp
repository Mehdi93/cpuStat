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
    long int *ptr = (long int*)str;
    string buff;
    stringstream ss(ligne);
    
    ss >> buff;
    
    //on boucle sur le nombre de variable dans notre structure/variable
    for(int i=0;i<(sizeof(*str)/sizeof(long int));i++)
    {
      ss >> buff;
      ptr[i] = atol(buff.c_str());
    }
}

int main(int argc,char** argv)
{
  fstream statFichier;
  string ligne;
  vector<cpuStat> *allCpu = new vector<cpuStat>;
  
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
      nomLigne = ligne.substr(0,ligne.find(' ')); //on isole le nom de la ligne
      
      //on utilise une liste (vector) pour les cpu car le nb de coeurs est variable
      if(nomLigne.find("cpu")!=nomLigne.npos)
      {
        cpuStat *cpuTest = new cpuStat;
        setData(cpuTest,ligne);
        
        allCpu->push_back(*cpuTest);
      }
      else if(nomLigne.find("ctxt")!=nomLigne.npos)
      {
        long int *ctxt = new long int;
        setData(ctxt,ligne);
      }
      else if(nomLigne.find("btime")!=nomLigne.npos)
      {
        long int *btime = new long int;
        setData(btime,ligne);
      }
      else if(nomLigne.find("processes")!=nomLigne.npos)
      {
        long int *processes = new long int;
        setData(processes,ligne);
      }
      else if(nomLigne.find("procs_running")!=nomLigne.npos)
      {
        long int *procs_running = new long int;
        setData(procs_running,ligne);
      }
      else if(nomLigne.find("procs_blocked")!=nomLigne.npos)
      {
        long int *procs_blocked = new long int;
        setData(procs_blocked,ligne);
      }
      
      getline(statFichier,ligne);
    }

  }
  
  statFichier.close();
  
  return 0;
}
