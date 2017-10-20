//
//  StartLayer.hpp
//  ShootIQ
//
//  Created by skytomo on 2017/10/16.
//
#ifndef StartLayer_hpp
#define StartLayer_hpp

#include "cocos2d.h"
#include "ScoreHistory.hpp"

class ButtonSprite : public cocos2d::Sprite {
};

class StartLayer : public cocos2d::Layer{
protected:
    enum Tag {
        T_START,
        T_RULE,
        T_EXIT
    };
    enum ZOrder {
        T_bg,T_sprite,
    };
     void createButton(cocos2d::Point position);
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(StartLayer);
    virtual void onEnter();
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void clear();
    void ranking();
};

#endif
