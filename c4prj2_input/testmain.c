#include <stdio.h>
#include <stdlib.h>
#include "future.h"
#include "deck.h"
#include "cards.h"
#include "input.h"

int main(void) {
  future_cards_t * fc = malloc(sizeof(*fc));
  FILE * f = fopen("input2.txt","r");
  size_t n_hands = 5;
  deck_t ** ans = read_input(f,&n_hands,fc);
  return EXIT_SUCCESS;
}
