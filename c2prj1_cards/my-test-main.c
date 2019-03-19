#include "cards.h"

int main(void) {
  card_t test_card;
  test_card = card_from_num(0);
  print_card(test_card);
  return 0;
}
