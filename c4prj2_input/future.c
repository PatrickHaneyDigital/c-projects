#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"
#include "future.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr) {
  if (fc->n_decks > index) {
    fc->decks[index].cards = realloc(fc->decks[index].cards, (fc->decks[index].n_cards+1) * sizeof(*fc->decks[index].cards));
    fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
    fc->decks[index].n_cards++;
  }
  if (fc->n_decks <= index) {
    fc->decks = realloc(fc->decks, (index+1) * sizeof(*fc->decks));
    fc->n_decks = index+1;
    fc->decks[index].cards = malloc(sizeof(*fc->decks[index].cards));
    fc->decks[index].cards[0] = ptr;
    fc->decks[index].n_cards = 1;
  }
  }

void future_cards_from_deck(deck_t * deck, future_cards_t * fc) {
  for (int i = 0; i < fc->n_decks; i++) {
    for (int j = 0; j < fc->decks[i].n_cards; j++) {
      *fc->decks[i].cards[j] = *deck->cards[i];
    }
  }
}
  
