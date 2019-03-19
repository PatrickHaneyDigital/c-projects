#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv) {
  //WRITE YOUR CODE HERE!
  size_t sz;
  size_t fi = 0;
  size_t i = 0;
  char * line = NULL;
  char ** lines = NULL;
  FILE * f = NULL;
  if (argc == 1) {
    f = stdin;
    while (getline(&line,&sz,f) >= 0) {
      lines = realloc(lines,(i+1)*sizeof(*lines));
      lines[i] = line;
      line = NULL;
      i++;
  }
    sortData(lines,i);
    for (int j = 0; j < i; j++) {
      printf("%s",lines[j]);
      free(lines[j]);
    }
    free(line);
    free(lines);
  } 
  else {
    while (fi < argc-1) {
      f = fopen(argv[fi+1],"r");
      if (f == NULL) {
	fprintf(stderr, "Issue opening file.");
	if (line != NULL) {free(line);}
	if (lines != NULL) {free(lines);}
	return EXIT_FAILURE;
      }
      while (getline(&line,&sz,f) >= 0) {
	lines = realloc(lines,(i+1)*sizeof(*lines));
	lines[i] = line;
	line = NULL;
	i++;
      }
      sortData(lines,i);
      for (int j = 0; j < i; j++) {
	printf("%s",lines[j]);
	free(lines[j]);
      }
      fi++;
      fclose(f);
      i = 0;
    }
    free(line);
    free(lines);
  }
  return EXIT_SUCCESS;
}
