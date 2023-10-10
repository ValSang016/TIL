#include <stdio.h>
#include <stdlib.h>

#define num 1000
typedef struct
{
  int idx;
  int w;
  int iq;
} EP;

void sort(EP ep[], int k) {
  EP temp;
  for (int i = 0; i < k-1; i++)
  {
    for (int j = i+1; j < k; j++)
    {
      if (ep[i].w > ep[j].w)
      {
        temp = ep[i]; // Create temporary variable of type EP.
        ep[i] = ep[j];
        ep[j] = temp;
      } else if(ep[i].w == ep[j].w){
        if (ep[i].iq > ep[j].iq){
          temp = ep[i];
          ep[i] = ep[j];
          ep[j] = temp;
        }
        
      }
    }
  }
}


void find_longest_subsequence(EP ep[], int n) {
  
	int i, j, k;
  int tmp_iq;
	int max_seq = 0;
	int max_index = 0;
  int len_dp[n];
	int index_dp[n][n];

  for(i = 0; i < n; i++){
    len_dp[i] = 1;
  }

	for (i = 0; i < n; i++){
    k = 1;
    tmp_iq = ep[i].iq;
    index_dp[i][0] = ep[i].idx;
		//Find the number of cases where iq is larger and store it in the table.
		for (j = i; j < n - 1; j++){
			if (tmp_iq > ep[j + 1].iq){
        tmp_iq = ep[j+1].iq;
				len_dp[i] += 1;
        index_dp[i][k] = ep[j+1].idx;
        k++;
			}
		}
		
		//Find the sequence with the longest sequence.
		if (max_seq < len_dp[i])
		{
			max_seq = len_dp[i];
			max_index = i;
		}
	}

	//Prints longest sequence length
	printf("%d\n", max_seq);

	for (i = 0; i < max_seq; i++)
	{
		printf("%d ", index_dp[max_index][i]);
	}
}

int main(){
  EP ep[num];

  FILE *filePtr=fopen("input1.txt","r");
  if(filePtr==NULL){
    printf("File not found!\n");
    return -1;
    }

  int n=0;
  while(fscanf(filePtr, "%d %d", &ep[n].w, &ep[n].iq)!=EOF){
      ep[n].idx = n+1;
      n++;
  }

  fclose(filePtr);

  sort(ep, n);

  find_longest_subsequence(ep, n);

  return 0;
}
