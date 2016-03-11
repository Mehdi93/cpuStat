#include "statHandler.h"

statHandler::statHandler()
{
  allCpu = new vector<cpuStat>;
  ctxt = new long int;
  btime = new long int;
  processes = new long int;
  procs_running = new long int;
  procs_blocked = new long int;
  
  refreshData(); //récupération des données immédiate
}

statHandler::~statHandler()
{
  delete allCpu;
  delete ctxt;
  delete btime;
  delete processes;
  delete procs_running;
  delete procs_blocked;
}

vector<cpuStat> statHandler::getAllCpu()
{
  return *allCpu;
}

long int statHandler::getCtxt()
{
  return *ctxt;
}

long int statHandler::getBtime()
{
  return *btime;
}

long int statHandler::getProcesses()
{
  return *processes;
}

long int statHandler::getProcs_running()
{
  return *procs_running;
}

long int statHandler::getProcs_blocked()
{
  return *procs_blocked;
}

template<typename T> void statHandler::setData(T str, string ligne)
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

void statHandler::refreshData()
{
  fstream statFichier;
  string ligne;
  
  //AZERTY remplacer par "/proc/stat"
  statFichier.open("test.txt",ios::in); //ouverture du fichier
  
  //on teste que le fichier existe
  if(!statFichier.is_open())
  {
    cout<<"Fichier stat inexistant"<<endl;
  }
  else
  {
    string nomLigne;
    allCpu->clear(); //on vide la liste de cpu
    
    //lecture du fichier de stat
    getline(statFichier,ligne);
    while (!statFichier.eof())
    {
      nomLigne = ligne.substr(0,ligne.find(' ')); //on isole le nom de la ligne
      
      //on utilise une liste (vector) pour les cpu car le nb de coeurs est variable
      if(nomLigne.find("cpu")!=nomLigne.npos)
      {
        cpuStat *cpuTmp = new cpuStat;
        setData(cpuTmp,ligne);
        
        allCpu->push_back(*cpuTmp);
        delete cpuTmp;
      }
      else if(nomLigne.find("ctxt")!=nomLigne.npos)
      {
        setData(ctxt,ligne);
      }
      else if(nomLigne.find("btime")!=nomLigne.npos)
      {
        setData(btime,ligne);
      }
      else if(nomLigne.find("processes")!=nomLigne.npos)
      {
        setData(processes,ligne);
      }
      else if(nomLigne.find("procs_running")!=nomLigne.npos)
      {
        setData(procs_running,ligne);
      }
      else if(nomLigne.find("procs_blocked")!=nomLigne.npos)
      {
        setData(procs_blocked,ligne);
      }
      
      getline(statFichier,ligne);
    }
  }
  
  statFichier.close();
}
