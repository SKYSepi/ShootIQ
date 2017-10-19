//
//  ScoreHistory.hpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/17.
//

#ifndef ScoreHistory_hpp
#define ScoreHistory_hpp

#endif /* ScoreHistory_hpp */

class ScoreHistory{
protected:
    struct Score{
        std::string name;
        int score;
    };

    std::list <struct Score> scorehistory;
    
public:
//  void memoryscore(std::string,int);
 //   void getscore();
};
