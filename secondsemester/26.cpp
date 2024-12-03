#include <iostream>
#include <string>
using namespace std;
class PokerCard
{
public:
  PokerCard(string s, int f)
  {
    suit = s;
    face = arr[f];
  }
  friend ostream &operator<<(ostream &out, PokerCard &p)
  {
    int n = (p.face == 14) ? 1 : p.face;
    out << "[" << n << " of " << p.suit << "]";
    return out;
  }

  bool operator>(PokerCard &b) 
  {
    if (face != b.face)
      return face > b.face;
    else
      return suitPriority(suit) > suitPriority(b.suit);
  }

  bool operator<(PokerCard &b) 
  {
    if (face != b.face)
      return face < b.face;
    else
      return suitPriority(suit) < suitPriority(b.suit);
  }

  bool operator==(PokerCard &b) 
  {
    return face == b.face && suit == b.suit;
  }

private:
  string suit;
  int arr[14] = {0, 14, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  int face;

  int suitPriority(string &suit) 
  {
    if (suit == "spade")
      return 4;
    else if (suit == "heart")
      return 3;
    else if (suit == "diamond")
      return 2;
    else if (suit == "club")
      return 1;
    else
      return 0;
  }
};


