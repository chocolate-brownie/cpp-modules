#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>

class ATarget {
protected:
    std::string _type;

public:
    ATarget(const std::string& type);
    virtual ~ATarget();

    std::string& getType() const;
    virtual ATarget* clone() = 0;

    void getHitBySpell(const ASpell& src) const;

};

#endif
