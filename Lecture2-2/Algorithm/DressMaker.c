#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int time;
    int fine;
} Job;

int compare(const void *a, const void *b) {
  Job *jobA = (Job *)a;
  Job *jobB = (Job *)b;

  double ratioA = (double)jobA->fine / jobA->time;
  double ratioB = (double)jobB->fine / jobB->time;

  if(ratioA == ratioB)
    return jobA->time - jobB->time; // If the ratios are equal, sort by id.
    
  return ratioB - ratioA; // Otherwise, sort by fine/time in descending order.
} // return 1 -> swap, 0 or -1 -> no swap

int main() {
    int testCases, nJobs, i;
    FILE* input = fopen("input.txt", "r");



    scanf("%d", &testCases);

    // fscanf(input, "%d", &testCases);
    printf("\n");

    while(testCases--) {
      scanf("%d", &nJobs);

      // fscanf(input, "%d", &nJobs);

      if (nJobs < 0 || nJobs > 1000) {
        printf("Please enter the number from 0 to 1000\n");
        testCases++;
        continue;
      }

      Job jobs[nJobs];

      for(i = 0; i < nJobs; i++) {
        jobs[i].id = i + 1;
        scanf("%d %d", &(jobs[i].time), &(jobs[i].fine));
        // fscanf(input, "%d %d", &jobs[i].time, &jobs[i].fine);


        if (!(jobs[i].time >= 0 && jobs[i].time <= 1000) || 
        !(jobs[i].fine >= 0 && jobs[i].fine <= 10000)) {
          printf("Please enter the time from 0 to 1000 and the fine from 0 to 1000.\n");
          i--;
          continue;
        }
      }

      qsort(jobs, nJobs, sizeof(Job), compare);

      for(i=0; i < nJobs; i++){
        printf("%d ", jobs[i].id);
      }
      
      printf("\n"); // To avoid trailing space.

      if(testCases)
        printf("\n"); // Print a newline between test cases.
    }

    return 0;
}
