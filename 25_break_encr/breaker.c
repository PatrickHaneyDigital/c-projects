#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getMaxIndex(int * arr){
  int max = 0;
  for (int x = 0; x < 26; x++) {
    if (arr[x] > arr[max]) {
      max = x;
    }
  }
  return max;
}

int getEDiff(int maxLetter) {
    if(maxLetter - 4 < 0) {
    return 26 + (maxLetter - 4);
  }
  else {
    return maxLetter - 4;
  }
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: breaker inputFileName\n");
    return EXIT_FAILURE;}
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;}
  int letterCounts[26] = {0};
  char c;
  while((c=fgetc(f)) != EOF) {
    if (isalpha(c)){
      c = tolower(c);
      letterCounts[c-'a']++;
    }
  }
  int maxLetter = getMaxIndex(letterCounts);
  printf("%d\n", getEDiff(maxLetter));
  return EXIT_SUCCESS;
}
