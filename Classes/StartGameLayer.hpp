//
//  StartGameLayer.hpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/19.
//

#ifndef StartGameLayer_hpp
#define StartGameLayer_hpp

#include "cocos2d.h"
//#include "ScoreHistory.hpp"

class StartGameLayer : cocos2d::Layer{
protected:
    cocos2d::Label* p_text;
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(StartGameLayer);
    virtual void onEnter();
    void next(float);
    void countdown(float);
};

#endif /* StartGameLayer_hpp */
