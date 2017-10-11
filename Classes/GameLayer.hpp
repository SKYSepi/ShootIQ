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
        T_Enemy,
    };
    
    enum Zorder{
        Z_Enemy,
    };
    
    void createEnemy(cocos2d::Point position);
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameLayer);
    virtual void onEnter();
    void update(float fream);
};

#endif /* GameLayer_hpp */
