#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>

// Function to build an inverted index
std::map<std::string, std::set<int>> buildInvertedIndex(const std::vector<std::string>& documents) {
    std::map<std::string, std::set<int>> invertedIndex;

    for (int docID = 0; docID < documents.size(); ++docID) {
        std::istringstream stream(documents[docID]);
        std::string word;
        while (stream >> word) {
            // Insert the word into the map with the document ID
            invertedIndex[word].insert(docID + 1); // Document IDs are 1-based
        }
    }
    return invertedIndex;
}

// Function to print the inverted index
void printInvertedIndex(const std::map<std::string, std::set<int>>& invertedIndex) {
    for (const auto& entry : invertedIndex) {
        std::cout << entry.first << " -> [";
        for (auto it = entry.second.begin(); it != entry.second.end(); ++it) {
            if (it != entry.second.begin()) {
                std::cout << ", ";
            }
            std::cout << *it;
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    // Document collection
    std::vector<std::string> documents = {
        "new home sales top forecasts",
        "home sales rise in july",
        "increase in home sales in july",
        "july new home sales rise"
    };

    // Build the inverted index
    std::map<std::string, std::set<int>> invertedIndex = buildInvertedIndex(documents);

    // Print the inverted index
    std::cout << "Inverted Index:" << std::endl;
    printInvertedIndex(invertedIndex);

    return 0;
}
