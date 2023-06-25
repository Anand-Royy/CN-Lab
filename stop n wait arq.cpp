#include <cstdlib>
#include <ctime>
#include <iostream>


using namespace std;

int main() {
  srand(time(NULL));

  int totalFrames;
  cout << "Enter the total number of frames: ";
  cin >> totalFrames;

  int currentFrame = 1;
  int transmittedFrames = 0;

  while (transmittedFrames < totalFrames) {
    cout << "Sending Frame " << currentFrame << "..." << endl;

    int acknowledgement = rand() % 2; // Simulating random acknowledgement (0:
                                      // Acknowledged, 1: Not Acknowledged)

    if (acknowledgement == 0) {
      cout << "Frame " << currentFrame << " Acknowledged." << endl;
      transmittedFrames++;
      currentFrame++;
    } else {
      cout << "Frame " << currentFrame
           << " Not Acknowledged. Retransmitting Frame..." << endl;
    }

    cout << endl;
  }

  cout << "All frames have been transmitted and acknowledged." << endl;

  return 0;
}
