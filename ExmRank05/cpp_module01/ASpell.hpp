#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>

class ASpell {
protected:
    std::string _name;
    std::string _effect;

    ASpell(const ASpell&);
    ASpell& operator=(const ASpell&);

public:
    virtual ASpell* clone() const = 0;

    std::string getName() const;
    std::string getEffect() const;

    ASpell(const std::string& name, const std::string& effect);
    virtual ~ASpell();

    void launch(const ATarget &src) const;
};

#endif
