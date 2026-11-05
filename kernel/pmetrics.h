#ifndef _PMETRICS_H
#define _PMETRICS_H_

struct pmetrics {
  int pid;
  uint64 turnaround;
  uint64 response;
  uint64 waiting;
};
#endif
