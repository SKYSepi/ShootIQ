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
        T_Enemy,T_Ball,T_Pointer,
    };
    
    enum Zorder{
        Z_Enemy,Z_Ball,Z_Pointer,
    };
    cocos2d::Sprite* p_pointer;

    cocos2d::Label* p_label;
    int score;
    int Number_of_shots;
    int point_array[5];
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
    bool onContactBegin(cocos2d::PhysicsContact&);
    void MakePointer();
    void initListener();
    int shot();
    void addscore(int);
};

#endif /* GameLayer_hpp */
