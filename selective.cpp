#include <bits/stdc++.h>
using namespace std;
bool ack() {
  // acknowledged or not
  return rand() % 2;
}

void solve() {
  int packets;
  cin >> packets;
  int window_size;
  cin >> window_size;
  int window_start = 1;
  set<int> packets_to_be_transmitted;

  while (window_start <= packets) {
    for (int j = window_start; j < window_start + window_size && j <= packets;
         ++j) {
      cout << "Sending packet No : " << j << "\n";
    }
    for (int j = window_start; j < window_start + window_size && j <= packets;
         ++j) {
      if (ack()) {
        cout << "Packet No : " << j << " acknowledged \n";
      } else {
        cout << "Failed to acknowledge packet : " << j << "\n";
        packets_to_be_transmitted.insert(j);
      }
    }
    while (!packets_to_be_transmitted.empty()) {
      auto f = packets_to_be_transmitted.begin();
      if (ack()) {
        cout << "Resending Packet No : " << *f << " acknowledged \n";
        packets_to_be_transmitted.erase(f);
      } else {
        cout << "Failed to acknowledge packet : " << *f << "\n";
      }
    }
    window_start += window_size;
  }
}

int main() { solve(); }
