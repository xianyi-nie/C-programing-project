#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value>=2 && c.value<=14);
  assert(c.suit>=SPADES && c.suit<=CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r)
    {
    case STRAIGHT_FLUSH:
      return "STARIGHT_FLUSH";
    case FOUR_OF_A_KIND:
      return "FOUR_OF_A_KIND";
    case FULL_HOUSE:
      return "FULL_HOUSE";
    case FLUSH:
      return "FLUSH";
    case STRAIGHT:
      return "STRAIGHT";
    case THREE_OF_A_KIND:
      return "THREE_OF_A_KIND";
    case TWO_PAIR:
      return "TWO_PAIR";
    case PAIR:
      return "PAIR";
    case NOTHING:
      return "NOTHING";
    }
  return "";
}

char value_letter(card_t c) {
  char x;
  switch (c.value)
    {
    case 2:
      x = '2';
      break;
    case 3:
      x = '3';
      break;
    case 4:
      x = '4';
      break;
    case 5:
      x = '5';           
      break;
    case 6:
      x = '6';           
      break;
    case 7:
      x = '7';           
      break;
    case 8:
      x = '8';           
      break;
    case 9:
      x = '9';           
      break;
    case 10:
      x = '0';           
      break;
    case 11:
      x = 'J';           
      break;
    case 12:
      x = 'Q';           
      break;
    case 13:
      x = 'K';           
      break;
    case 14:
      x = 'A';
      break;	  
    }
  return x;
}


char suit_letter(card_t c) {
  char x;
  switch (c.suit)
    {
    case SPADES:
      x = 's';
      break;
    case HEARTS:
      x = 'h';
      break;
    case DIAMONDS:
      x = 'd';
      break;
    case CLUBS:
      x = 'c';
      break;
    case NUM_SUITS:
      break;
    }
  return x;
}

void print_card(card_t c) {
  char suit, value;
  value = value_letter(c);
  suit = suit_letter(c);
  printf("%c%c",value,suit);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  temp.value = value_let;
  temp.suit = suit_let;
  assert(temp.value >=2 && temp.value <=14);
  assert(temp.suit >=0 && temp.suit <=3);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  assert (c >=0 && c <52);
  if (c/13 == 0)
    {
      temp.suit = SPADES;
    }
  else if (c/13 == 1)
    {
      temp.suit = HEARTS;
    }
  else if (c/13 == 2)
    {
      temp.suit = DIAMONDS;
    }
  else
    {
      temp.suit = CLUBS;
    }
 temp.value = (c % 13) + 2;
  return temp;
}
