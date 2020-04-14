#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value>=2 && c.value<=VALUE_ACE);
  assert(c.suit>=SPADES && c.suit<=CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r)
    {
    case STRAIGHT_FLUSH:
      return "STRAIGHT_FLUSH";
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
    default :
      break;
    }
  return "";
}

char value_letter(card_t c) {
  if ((c.value >= 2) && (c.value <=9))
    {
      return c.value + '0';
    }
  else
    {
  switch (c.value)
    {
    case 10:
      return '0';           
    case VALUE_JACK:
      return 'J';           
    case VALUE_QUEEN:
      return 'Q';           
    case VALUE_KING:
      return 'K';                
    case VALUE_ACE:
      return 'A';
    default:
      break;
    }
    }
  return c.value;
}


char suit_letter(card_t c) {
  switch (c.suit)
    {
    case SPADES:
      return 's';
    case HEARTS:
      return 'h';
    case DIAMONDS:
      return 'd';
    case CLUBS:
      return 'c';
    default:
      break;
    }
  return c.suit;
}

void print_card(card_t c) {
  char suit, value;
  value = value_letter(c);
  suit = suit_letter(c);
  printf("%c%c",value,suit);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if ((value_let >= '2') && (value_let <= '9'))
    {
      temp.value = value_let - '0';
    }
  else
    {
      switch(value_let)
	{
	case '0':
	  temp.value = 10;
	  break;
	case 'J':
	  temp.value =  VALUE_JACK;
	  break;
	case 'Q':
	  temp.value =  VALUE_QUEEN;
	  break;
	case 'K':
	  temp.value =  VALUE_KING;
	  break;
	case 'A':
	  temp.value =  VALUE_ACE;
	  break;
	default:
	  break;
	}  
    }
  switch(suit_let)
    {
    case 's':
      temp.suit = SPADES;
      break;
    case 'h':
      temp.suit = HEARTS;
      break;
    case 'd':
      temp.suit = DIAMONDS;
      break;
    case 'c':
      temp.suit = CLUBS ;
      break;
    default:
      break;
    }
  assert_card_valid(temp);
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
