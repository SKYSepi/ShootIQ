//
//  GameLayer.hpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/10.
//

#ifndef GameLayer_hpp
#define GameLayer_hpp



#include "cocos2d.h"

class GameLayer : public cocos2d::Layer{
protected:
    enum Tag{
        T_Enemy,T_Ball,
    };
    
    enum Zorder{
        Z_Enemy,Z_Ball,
    };
    
    void createEnemy(cocos2d::Point);
    void createchacheball(cocos2d::Point,cocos2d::Point);
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameLayer);
    void pushEnemy(float);
    virtual void onEnter();
    bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    void onMouseMove(cocos2d::Event*);
};

#endif /* GameLayer_hpp */
