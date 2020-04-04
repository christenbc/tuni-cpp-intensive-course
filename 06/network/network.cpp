#include "network.hh"
#include <iostream>
#include <string>

void Network::store(const std::string recruiter, const std::string recruited){
    members_[recruiter].push_back(recruited);
}

std::string Network::print(int level, const std::string root) const{
    std::string answer = std::string(level * 2, '.') + root;
    if(members_.find(root) == members_.end())
        return answer;
    else{
        const std::list<std::string> &recruitedList = members_.at(root);
        for(auto& r : recruitedList)
            answer += "\n" + print(level + 1, r);
        return answer;
    }
}

int Network::count(const std::string root) const{
    if(members_.find(root) == members_.end())
        return 1;
    else{
        int answer = 1;
        const std::list<std::string> &recruitedList = members_.at(root);
        for(auto & r : recruitedList)
            answer += count(r);
        return answer;
    }
}

int Network::depth(int level, const std::string root) const{
    if(members_.find(root) == members_.end())
        return level + 1;
    else{
        int answer = 0;
        const std::list<std::string> &recruitedList = members_.at(root);
        for(auto& r : recruitedList)
            answer = std::max(answer, depth(level + 1, r));
        return answer;
    }
}
