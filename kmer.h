#ifndef __KMER_H__
#define __KMER_H__
#include <iostream>
#include <string>

class kmer
{
    private:
        std::string m_kmer;
        std::size_t m_position;
        std::size_t m_repeats;
    public:
        kmer(const std::string & kmer,
                std::size_t position,
                std::size_t repeats);
        kmer(const kmer & other);
        ~kmer();
        const kmer & operator = (const kmer & other);
        bool operator == (const kmer & other) const;
        bool operator < (const kmer & other) const;
        const std::string & kmerString() const;
        std::size_t length() const;
        std::size_t position() const;
        std::size_t repeats() const;
};
std::ostream & operator << (std::ostream & s, const kmer & k);

#endif
