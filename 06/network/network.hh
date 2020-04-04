#ifndef NETWORK_HH
#define NETWORK_HH

#include <string>
#include <map>
#include <list>

class Network{
public:
    void store(const std::string recruiter, const std::string recruited);
    std::string print(int level, const std::string root) const;
    int count(const std::string root) const;
    int depth(int level, const std::string root) const;

private:
    std::map<std::string, std::list<std::string>> members_;
};

#endif // NETWORK_HH
