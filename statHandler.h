#ifndef DEF_STATHANDLER
#define DEF_STATHANDLER

using namespace std;

#include<vector>
#include "modeles.h"

class statHandler {
  private:
    vector<cpuStat> *allCpu; //stat du cpu et des différents coeurs
    long int *ctxt;
    long int *btime;
    long int *processes;
    long int *procs_running;
    long int *procs_blocked;
  
  public:
    statHandler();
    ~statHandler();
    vector<cpuStat> getAllCpu();
    long int getCtxt();
    long int getBtime();
    long int getProcesses();
    long int getProcs_running();
    long int getProcs_blocked();
};

#endif
