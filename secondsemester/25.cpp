#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Friend
{
public:
  int street, avenue;
  Friend(int s, int a) : street(s), avenue(a) {}
};
class GridCity
{
private:
  int streets, avenues;
  vector<Friend> friends;

public:
  GridCity(int s, int a) : streets(s), avenues(a) {}

  void addFriend(int s, int a)
  {
    friends.push_back(Friend(s, a));
  }

  pair<int, int> findMeetingPoint()
  {
    int min_distance = 9999;
    pair<int, int> meeting_point = {-1, -1};

    for (int street = 1; street <= streets; ++street)
    {
      for (int avenue = 1; avenue <= avenues; ++avenue)
      {
        int distance = 0;
        for (const auto &friendObj : friends)
        {
          distance += abs(friendObj.street - street) + abs(friendObj.avenue - avenue);
        }
        if (distance < min_distance)
        {
          min_distance = distance;
          meeting_point = make_pair(street, avenue);
        }
      }
    }
    return meeting_point;
  }
};

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int S, A, F;
    cin >> S >> A >> F;
    GridCity grid(S, A);

    for (int f = 0; f < F; f++)
    {
      int s, a;
      cin >> s >> a;
      grid.addFriend(s, a);
    }
    pair<int, int> out = grid.findMeetingPoint();
    cout << "(Street: " << out.first << ", Avenue: " << out.second << ")" << endl;
  }
  return 0;
}

