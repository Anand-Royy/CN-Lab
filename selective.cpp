#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));
    
    int totalFrames;
    cout << "Enter the total number of frames: ";
    cin >> totalFrames;
    
    int windowSize;
    cout << "Enter the window size: ";
    cin >> windowSize;
    
    int base = 1;
    int nextSeqNum = 1;
    int transmittedFrames = 0;
    
    while (transmittedFrames < totalFrames) {
        for (int i = base; i < base + windowSize && i <= totalFrames; i++) {
            cout << "Sending Frame " << i << "..." << endl;
        }
        
        int acknowledgement = rand() % 2; // Simulating random acknowledgement (0: Acknowledged, 1: Not Acknowledged)
        
        if (acknowledgement == 0) {
            int numAckedFrames = rand() % windowSize + 1; // Simulating random number of frames acknowledged
            cout << numAckedFrames << " frame(s) Acknowledged." << endl;
            
            transmittedFrames += numAckedFrames;
            base += numAckedFrames;
            nextSeqNum += numAckedFrames;
        } else {
            cout << "Frames Not Acknowledged. Retransmitting Window..." << endl;
        }
        
        cout << endl;
    }
    
    cout << "All frames have been transmitted and acknowledged." << endl;
    
    return 0;
}
