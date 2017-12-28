#ifndef SCORES_HPP
#define SCORES_HPP
#include <string>

class Scores
{
public:
	std::string date;
	std::string name;
	int level;
	int points;
	bool operator <(const Scores& d) {
		if (level > d.level) {
			return true;
		}
		if (level == d.level && points > d.points) {
			return true;
		}
		return false;
	}
};

#endif
