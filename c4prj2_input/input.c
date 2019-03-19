#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"
#include "future.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc) {
  deck_t * ans = malloc(sizeof(*ans));
  char * tempStr = malloc((strlen(str)+1) * sizeof(char));
  strcpy(tempStr, str);
  ans->n_cards = 0;
  ans->cards = malloc(sizeof(*ans->cards));
  char * token = NULL;
  char * newline = strchr(tempStr, '\n');
  if (newline) {
    *newline = '\0';
  }
  token = strtok(tempStr, " ");
  while (token != NULL) {
    ans->cards = realloc(ans->cards, (ans->n_cards+1) * sizeof(card_t));
    if (token[0] == '?') {
      add_future_card(fc, atoi(&token[1]), add_empty_card(ans));
    }
    else {
      add_card_to(ans,card_from_letters(token[0],token[1]));
    }
    token = strtok(NULL, " ");
  }
  if (ans->n_cards < 5) {
    fprintf(stderr, "Hand needs at least 5 cards");
    exit(EXIT_FAILURE);
  }
  free(tempStr);
  return ans;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {
  deck_t ** ans = malloc(sizeof(*ans));
  char * line = NULL;
  size_t sz;
  size_t i = 0;
  while (getline(&line,&sz,f) >= 0) {
    ans = realloc(ans, (i + 1) * sizeof(*ans));
    ans[i] = hand_from_string(line, fc);
    i++;
    line = NULL;
  }
  free(line);
  *n_hands = i;
  return ans;
}
    
