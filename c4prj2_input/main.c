#include <stdio.h>
#include <stdlib.h>
#include "future.h"
#include "deck.h"
#include "cards.h"
#include "input.h"

int main(void) {
  future_cards_t * fc = malloc(sizeof(*fc));
  fc->decks = malloc(sizeof(*fc->decks));
  fc->n_decks = 0;
  size_t n_hands = 0;
  FILE * f = fopen("input2.txt","r");
  deck_t ** ans = read_input(f,&n_hands,fc);
  for (int i = 0; i < n_hands; i++) {
    free_deck(ans[i]);
  }
  free(ans);
  free(fc->decks);
  free(fc);
  return EXIT_SUCCESS;
}
