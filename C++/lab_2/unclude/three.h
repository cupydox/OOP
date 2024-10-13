#pragma once 
#include <vector>
#include <string>
class Three {
public:
    Three();
    Three(const size_t &n, const unsigned char t);
    Three(const std::initializer_list<unsigned char> &t);
    Three(const std::string &t);
    Three(const Three& other);
    Three(Three&& other);
    Three operator+(const Three& other) const;
    Three operator-(const Three& other) const;
    Three& operator=(const Three& other);
    bool operator>(const Three& other) const;
    bool operator<(const Three& other) const;
    bool operator==(const Three& other) const;
    Three& operator+=(const Three& other);
    Three& operator-=(const Three& other);


    virtual ~Three() noexcept;
    
private:
    std::vector<unsigned char> digits;
};
