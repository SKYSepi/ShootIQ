//
//  ResultLayer.hpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/20.
//

#ifndef ResultLayer_hpp
#define ResultLayer_hpp

#include "cocos2d.h"

class ResultLayer : cocos2d::Layer{
protected:
public:
    enum Tag{
      T_end,
    };
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(ResultLayer);
    virtual void onEnter();
    void next();
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void calc_rw();
};


#endif /* ResultLayer_hpp */
