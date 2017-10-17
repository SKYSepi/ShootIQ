//
//  ScoreHistory.hpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/17.
//

#ifndef ScoreHistory_hpp
#define ScoreHistory_hpp

#include <stdio.h>

#endif /* ScoreHistory_hpp */

typedef struct{
    std::string name;
    int score;
}Score;

class ScoreHistory{
protected:
    std::list<Score> scorehistory;
    
public:
    void memoryscore(std::string,int);
 //   void getscore();
};
