#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <set>
#include "kmer.h"

using namespace std;

set<kmer> * getKmers(const string & corpus, const string & kmerString)
{
    list<size_t> * possibleKmers = new list<size_t>();
    // first pass
    char firstChar = kmerString[0];
    for (size_t i = 0UL; i < corpus.length(); i++)
    {
        if (corpus[i] == firstChar)
        {
            possibleKmers->push_back(i);
        }
    }
    // subsequent passes
    for (size_t offset = 1UL; offset < kmerString.length(); offset++)
    {
        char cmpChar = kmerString[offset];
        list<size_t> * newPossibleKmers = new list<size_t>();
        for (list<size_t>::iterator posIter = possibleKmers->begin();
                posIter != possibleKmers->end();
                posIter++)
        {
            if (corpus[*posIter+offset] == cmpChar)
            {
                newPossibleKmers->push_back(*posIter);
            }
        }
        delete possibleKmers;
        possibleKmers = newPossibleKmers;
    }

    list<size_t>::iterator posIter = possibleKmers->begin();
    set<kmer> * result = new set<kmer>();
    while (posIter != possibleKmers->end())
    {
        size_t repeats = 1UL;
        size_t basePos = *posIter;
        size_t lastPos = *posIter;
        do {
            if (*posIter - lastPos >= kmerString.length())
            {
                lastPos = *posIter;
                repeats++;
            }
            posIter++;
        } while (posIter != possibleKmers->end() &&
                *posIter - lastPos <= kmerString.length());
        result->insert(kmer(corpus.substr(basePos, kmerString.length()),
                basePos,
                repeats));
    }
    delete possibleKmers;
    return result;
}


int main(int argc, char *argv[])
{
    cout << "Enter kmer:" << endl;
    string k;
    getline(cin, k);
    cout << "Enter corpus:" << endl;
    string c;
    getline(cin, c);
    set<kmer> * kmers = getKmers(c,k);
    for (set<kmer>::iterator kIter = kmers->begin();
            kIter != kmers->end();
            kIter++)
    {
        cout << *kIter << endl;
    }
    delete kmers;
    return 0;
}
