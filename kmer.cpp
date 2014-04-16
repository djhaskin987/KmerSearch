#include "kmer.h"
#include <sstream>
using namespace std;

kmer::kmer(const std::string & kmer,
        std::size_t position,
        std::size_t repeats) : m_kmer(kmer), m_position(position), m_repeats(repeats)
{
}

kmer::kmer(const kmer & other) : m_kmer(other.m_kmer),
    m_position(other.m_position), m_repeats(other.m_repeats)
{
}

kmer::~kmer() {}

const kmer & kmer::operator = (const kmer & other)
{
    if (&other != this)
    {
        m_kmer = other.m_kmer;
        m_position = other.m_position;
        m_repeats = other.m_repeats;
    }
}

bool kmer::operator == (const kmer & other) const
{
    return other.m_kmer == m_kmer && other.m_position == m_position &&
        other.m_repeats == m_repeats;
}

bool kmer::operator < (const kmer & other) const
{
    if (m_kmer.length() < other.m_kmer.length())
    {
        return true;
    }
    else if (m_kmer.length() > other.m_kmer.length())
    {
        return false;
    }
    if (m_position < other.m_position)
    {
        return true;
    }
    else if (m_position > other.m_position)
    {
        return false;
    }
    if (m_repeats < other.m_repeats)
    {
        return true;
    }
    else if (m_repeats > other.m_repeats)
    {
        return false;
    }
    if (m_kmer < other.m_kmer)
    {
        return true;
    }
    else
    {
        return false;
    }
}


const std::string & kmer::kmerString() const
{
    return m_kmer;
}

std::size_t kmer::length() const
{
    return m_kmer.length();
}

std::size_t kmer::position() const
{
    return m_position;
}

std::size_t kmer::repeats() const
{
    return m_repeats;
}

ostream & operator << (ostream & s, const kmer & k)
{
    stringstream ss;
    char *buffer = new char[k.length()+1];
    buffer[k.length()] = '\0';
    ss << k.kmerString();
    ss >> buffer;
    s << "{ kmer: '" << buffer << "', length: " << k.length()
        << ", position: " << k.position() << ", repeats: "
        << k.repeats() << "}";
    return s;
}
