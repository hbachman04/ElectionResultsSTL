
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include "candidateType.h"

using namespace std;

int main()
{
    list<candidateType> candidateList;
    personType person;
    candidateType candidate;

    ifstream candFile("candData.txt");
    ifstream voteFile("voteData.txt");

    if (!candFile)
    {
        cout << "Error: Cannot open candData.txt" << endl;
        return 1;
    }

    if (!voteFile)
    {
        cout << "Error: Cannot open voteData.txt" << endl;
        return 1;
    }

    while (candFile >> person)
    {
        candidate = person;
        candidateList.push_back(candidate);
    }

    candFile.close();

    string firstName;
    string lastName;
    int region;
    int votes;

    while (voteFile >> firstName >> lastName >> region >> votes)
    {
        for (list<candidateType>::iterator iter = candidateList.begin();
            iter != candidateList.end(); ++iter)
        {
            if (iter->getFirstName() == firstName &&
                iter->getLastName() == lastName)
            {
                iter->updateVotesByRegion(region, votes);
                break;
            }
        }
    }

    voteFile.close();

    int totalVotesPolled = 0;

    for (list<candidateType>::iterator iter = candidateList.begin();
        iter != candidateList.end(); ++iter)
    {
        iter->calculateTotalVotes();
        totalVotesPolled += iter->getTotalVotes();
    }

    cout << "\n";
    cout << "--------------------Election Results--------------------";
    cout << "\n\n";

    cout << left << setw(18) << "Candidate Name";
    cout << right
        << setw(8) << "Region1"
        << setw(8) << "Region2"
        << setw(8) << "Region3"
        << setw(8) << "Region4"
        << setw(8) << "Total" << endl;

    cout << "---------------------------------------------------------------"
        << endl;

    for (list<candidateType>::iterator iter = candidateList.begin();
        iter != candidateList.end(); ++iter)
    {
        iter->printData();
    }

    if (!candidateList.empty())
    {
        list<candidateType>::iterator winner = candidateList.begin();

        for (list<candidateType>::iterator iter = candidateList.begin();
            iter != candidateList.end(); ++iter)
        {
            if (iter->getTotalVotes() > winner->getTotalVotes())
            {
                winner = iter;
            }
        }

        cout << "\nWinner: "
            << winner->getFirstName() << " "
            << winner->getLastName()
            << ", Votes Received: "
            << winner->getTotalVotes() << endl;
    }

    cout << "\nTotal votes polled: "
        << totalVotesPolled << endl;

    return 0;
}
