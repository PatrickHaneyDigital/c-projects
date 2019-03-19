#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  char temp[100];
  int determine_length=0;
  if (str == NULL) {
    return;
  }
  while (str[determine_length] != '\0') {
    temp[determine_length] = str[determine_length];
    determine_length++;
}
  temp[determine_length]='\0';
  if (determine_length > 0){
  for (int x = determine_length - 1; x >= 0; x--) {
    str[x] = temp[determine_length - 1 - x];
}
}
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
