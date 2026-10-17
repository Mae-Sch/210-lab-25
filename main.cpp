#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
using namespace std;
using namespace std::chrono;

const int NUM_CODES = 20000;

int main() {

    // testing reading for vector;
    auto start = high_resolution_clock::now();

    vector<string> testVector
    ifstream inFile("codes.txt");
    for (int i = 0; i < NUM_CODES; ++i) {
        string tempCode;
        getline(inFile, tempCode);
        testVector.push_back(tempCode);
    }
    inFile.close();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/