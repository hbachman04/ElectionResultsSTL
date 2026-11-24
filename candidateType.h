
#ifndef H_candidateType
#define H_candidateType

#include <string>
#include "personType.h"

const int NO_OF_REGIONS = 4;

class candidateType : public personType
{
public:
    const candidateType& operator=(const candidateType&);
    const candidateType& operator=(const personType&);

    void updateVotesByRegion(int region, int votes);
    void setVotes(int region, int votes);
    void calculateTotalVotes();
    int getTotalVotes() const;
    void printData() const;

    candidateType();

    bool operator==(const candidateType& right) const;
    bool operator!=(const candidateType& right) const;
    bool operator<=(const candidateType& right) const;
    bool operator<(const candidateType& right) const;
    bool operator>=(const candidateType& right) const;
    bool operator>(const candidateType& right) const;

private:
    int votesByRegion[NO_OF_REGIONS];
    int totalVotes;
};

#endif
