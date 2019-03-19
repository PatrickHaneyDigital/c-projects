#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void add_card_to(deck_t * deck, card_t c) {
  deck->cards = realloc(deck->cards, (deck->n_cards+1) * sizeof(card_t));
  deck->cards[deck->n_cards] = malloc(sizeof(*deck->cards[deck->n_cards]));
  *deck->cards[deck->n_cards] = c;
  deck->n_cards++;
}

card_t * add_empty_card(deck_t * deck) {
  card_t * empty = malloc(sizeof(card_t));
  empty->value = 0;
  empty->suit = 0;
  add_card_to(deck,*empty);
  return deck->cards[deck->n_cards-1];
}

deck_t * make_deck_exclude(deck_t * excluded_cards) {
  deck_t * new_deck = malloc(sizeof(deck_t));
  new_deck->n_cards = 0;
  new_deck->cards = malloc(sizeof(card_t));
  for (int i = 0; i < 52; i++) {
    card_t temp = card_from_num(i);
    if (deck_contains(excluded_cards,temp)==1){
      continue;
    }
    else {
      new_deck->cards[new_deck->n_cards] = malloc(sizeof(card_t));
      *new_deck->cards[new_deck->n_cards] = temp;
      new_deck->n_cards++;
      new_deck->cards = realloc(new_deck->cards, (new_deck->n_cards+1) * sizeof(card_t));
}
  }
  return new_deck;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t * excl_deck = NULL;
  excl_deck = malloc(sizeof(deck_t));
  excl_deck->n_cards = 0;
  excl_deck->cards = malloc(sizeof(card_t));
  for (int i = 0; i < n_hands; i++) {
    for (int j = 0; j < hands[i]->n_cards; j++) {
      add_card_to(excl_deck, *hands[i]->cards[j]);
    }
  }
  deck_t * remaining_deck = make_deck_exclude(excl_deck);
  return remaining_deck;
}

void free_deck(deck_t * deck) {
  for (int i = 0; i < deck->n_cards; i++) {
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}

void print_hand(deck_t * hand){
  for (int x = 0; x < hand->n_cards; x++) {
    print_card(*(hand->cards[x]));
  printf(" ");
}
}


int deck_contains(deck_t * d, card_t c) {
  for (int x = 0; x < d->n_cards; x++) {
    if (d->cards[x]->value == c.value && d->cards[x]->suit == c.suit) {
      return 1;
	}
  }
  return 0;
}

void shuffle(deck_t * d){
  for (int x = 0; x < d->n_cards; x++) {
    int randindex = random() % d->n_cards;
    card_t * temp = d->cards[randindex];
    d->cards[randindex] = d->cards[x]; 
      d->cards[x] = temp;
  }
}

void assert_full_deck(deck_t * d) {
  for (int x = 0; x < d->n_cards; x++) {
    assert(deck_contains(d,*(d->cards[x])) == 1);
}
}
