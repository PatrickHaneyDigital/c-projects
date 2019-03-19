#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((c.value >= 2 && c.value <= VALUE_ACE) && (c.suit >= SPADES && c.suit <= CLUBS));
}

const char * ranking_to_string(hand_ranking_t r) {
  char * ranking;
  switch(r){
  case STRAIGHT_FLUSH:
    ranking = "STRAIGHT_FLUSH";
    break;
  case FOUR_OF_A_KIND:
    ranking = "FOUR_OF_A_KIND";
    break;
  case FULL_HOUSE:
    ranking = "FULL_HOUSE";
    break;
  case FLUSH:
    ranking = "FLUSH";
    break;
  case STRAIGHT:
    ranking = "STRAIGHT";
    break;
  case THREE_OF_A_KIND:
    ranking = "THREE_OF_A_KIND";
    break;
  case TWO_PAIR:
    ranking = "TWO_PAIR";
    break;
  case PAIR:
    ranking = "PAIR";
    break;
  case NOTHING:
    ranking = "NOTHING";
    break;
  default:
    ranking = "NOTHING";
    break;
  }
 return ranking;
}

char value_letter(card_t c) {
  char letter_value = 'Z';
  if (c.value >= 2 && c.value <= 9) {
    letter_value = c.value + 48;
}
  else if (c.value == 10) {
    letter_value = '0';
  }
  else if (c.value == 11 || c.value == 'J') {
    letter_value = 'J';
  }
  else if (c.value == 12 || c.value == 'Q') {
    letter_value = 'Q';
      }
  else if (c.value == 13) {
    letter_value = 'K';
  }
  else if (c.value == 14) {
    letter_value = 'A';
  }
  if (letter_value != 'Z') {
  return letter_value;
  }
  else {
    return 0;
  }
}

char suit_letter(card_t c) {
  char suit_value = 'Z';
  if (c.suit == SPADES) {suit_value = 's';}
  else if (c.suit == HEARTS) {suit_value = 'h';}
  else if (c.suit == DIAMONDS) {suit_value = 'd';}
  else if (c.suit == CLUBS) {suit_value = 'c';}
  if (suit_value != 'Z') {
  return suit_value;
  }
  else {
    return 0;
  }
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c),suit_letter(c)); 
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if (value_let >= '1' && value_let <= '9') {
    temp.value = value_let - 48;
  }
  switch(value_let) {
  case 48:
    temp.value = 10;
    break;
  case 'J':
    temp.value = 11;
    break;
  case 'Q':
    temp.value = 12;
    break;
  case 'K':
    temp.value = 13;
    break;
  case 'A':
    temp.value = 14;
    break;
  default:
    break;
  }
  switch(suit_let) {
  case 's':
    temp.suit = SPADES;
    break;
  case 'd':
    temp.suit = DIAMONDS;
    break;
  case 'c':
    temp.suit = CLUBS;
    break;
  case 'h':
    temp.suit = HEARTS;
    break;
  default:
    break;
  }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  if (c >= 0 && c <= 52) {
    if (c == 0) {
      temp.value = 13;
      temp.suit = 0;
    }
    else if (c < 13) {
      temp.value = c % 13;
      temp.suit = 0;
    }
    else if (c < 26) {
      temp.value = c % 13;
      temp.suit = 1;
    }
    else if (c < 39) {
      temp.value = c % 13;
      temp.suit = 2;
    }
    else if (c < 52) {
      temp.value = c % 13;
      temp.suit = 3;
    }
  }
  else {
    printf("Invalid value entered. Please enter a value between 0 and 51.");
    exit(EXIT_FAILURE);
  }
  if (temp.value == 0 || temp.value == 1) {
    temp.value += 13;
  }
  return temp;
}
