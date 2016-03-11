#include "statHandler.h"

statHandler::statHandler()
{
  allCpu = new vector<cpuStat>;
  ctxt = new long int;
  btime = new long int;
  processes = new long int;
  procs_running = new long int;
  procs_blocked = new long int;
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
