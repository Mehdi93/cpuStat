#ifndef DEF_MODELES
#define DEF_MODELES

#define CPUSTAT 0
struct cpuStat {
  long int user;
  long int nice;
  long int system;
  long int idle;
  long int iowait;
  long int irq;
  long int softirq;
  long int steal;
  long int guest;
  long int guest_nice;
};

#endif
