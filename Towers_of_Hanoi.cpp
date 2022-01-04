#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> t[3];
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
  
   int close = (n % 2 == 0 ? 2 : 1), far = (n % 2 == 0 ? 1 : 2), from = 0, to = close, candidate = 1, move = 0;
   
   for(int i = n + 1; i >= 1; --i)
      t[0].push_back(i);
   t[1].push_back(n+1);
   t[2].push_back(n+1);
   
   while (t[1].size() < n+1) { // while t[1] does not contain all of the rings
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";

      // Move the ring from the "from" tower to the "to" tower.
      t[to].push_back(t[from].back()); 
      t[from].pop_back();
      
      if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back())
         from = (to + 1) % 3;
      else
         from = (to + 2) % 3;
         
      // candidate = the ring on top of the t[from] tower
      candidate = t[from].back();   
         
      // (compare the candidate with the ring on the closer tower; which tower is "closer" depends on whether n is odd or even)
      if (t[(close + from) % 3].back() > candidate)
         to = (close + from) % 3;
      else
         to = (far + from) % 3;
   }
   return 0;
}