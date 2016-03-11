#ifndef DEF_MODELES
#define DEF_MODELES

#define CPUSTAT 0
struct cpuStat {
  int user;
  int nice;
  int system;
  int idle;
  int iowait;
  int irq;
  int softirq;
  int steal;
  int guest;
  int guest_nice;
};

#define IZISTAT 1
struct iziStat {
  int user;
  int nice;
  int system;
  int idle;
  int iowait;
  int irq;
  int softirq;
  int steal;
  int guest;
  int guest_nice;
};

#endif
