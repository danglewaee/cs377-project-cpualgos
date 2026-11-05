#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/pmetrics.h"
#include "user/user.h"

int
main(void)
{
  int workloads[3] = {1000000, 5000000, 10000000};

  printf("Process Metrics Test\n");

  for (int i = 0; i < 3; i++) {
    int pid = fork();

    if (pid < 0) {
      printf("fork failed\n");
      exit(1);
    }

if (pid == 0) {
       unsigned long result = 0;

      for (int j = 0; j < workloads[i]; j++) {
        result += j;
      }

      exit(0);
    }
  }

for (int i = 0; i < 3; i++) {
    struct pmetrics m;
    int status;
    int pid = waitmetrics(&status, &m);
 if (pid < 0) {
      printf("waitmetrics failed\n");
      exit(1);
    }

    printf("PID: %d\n", m.pid);
  printf("Turnaround: %lu\n", m.turnaround);
    printf("Response:   %lu\n", m.response);
    printf("Waiting:    %lu\n\n", m.waiting);
  }

  exit(0);
}
