#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock {
	private:
		std::string _name;
		std::string _title;

        Warlock(const Warlock&);
        Warlock& operator=(const Warlock&);

	public:
		const std::string& getName() const;
		const std::string& getTitle() const;

		void setTitle(const std::string& title);

		void introduce() const;

		Warlock(const std::string& name, const std::string& title);
		~Warlock();
};

#endif
