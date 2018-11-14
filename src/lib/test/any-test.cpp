#include <vector>
#include <string>
#include <iostream>
#include "catch.hpp"

using namespace std;

class Idea {
public:
	Idea(string w, double h):
		whatIsAbout(w),
		howBadlyYouWantIt(h),
		randomPriority(rand()) { }
	virtual ~Idea() = default;
	string whatIsAbout;
	int howBadlyYouWantIt;
	int randomPriority;
};

std::ostream &operator<<(std::ostream os, Idea const &idea) {
	return os << idea.howBadlyYouWantIt << " - " << idea.whatIsAbout;
}

bool keepYourPriorities(Idea i1, Idea i2) {
	return i1.howBadlyYouWantIt > i2.howBadlyYouWantIt;
}

bool moodOfTheDay(Idea i1, Idea i2) {
	return i1.randomPriority > i2.randomPriority;
}

SCENARIO ("Life") {
	std::vector<Idea> ideas;
	
	GIVEN( "That you have too many ideas" ) {
		int iWantItVeryBadly = 10;
		ideas.push_back(Idea("computer vision with openCV",
		                     iWantItVeryBadly    ));
		ideas.push_back(Idea("Raspberry pi driving a model car",
		                     iWantItVeryBadly - 1));
		ideas.push_back(Idea("Write articles about them",
		                     iWantItVeryBadly - 2));
		ideas.push_back(Idea("Build nice model planes",
		                     iWantItVeryBadly - 3));
		ideas.push_back(Idea("Machine learning",
		                     iWantItVeryBadly - 4));
		ideas.push_back(Idea("etc.",
		                     iWantItVeryBadly - 5));

		WHEN("You let your fancy change priorities daily") {
			sort(ideas.begin(), ideas.end(), moodOfTheDay);
			
			THEN("You will not begin by your highest priority") {
				REQUIRE(ideas.begin() -> howBadlyYouWantIt < iWantItVeryBadly);
			}
		}
		
		WHEN("You keep your priorities straight") {
			sort(ideas.begin(), ideas.end(), keepYourPriorities);
			
			THEN ("You will concentrate in your topmost priority") {
				REQUIRE(ideas.begin() -> howBadlyYouWantIt == iWantItVeryBadly);
			}
		}
	}
}
