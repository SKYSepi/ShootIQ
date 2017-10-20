//
//  RankInNameLayer.hpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/20.
//

#ifndef RankInNameLayer_hpp
#define RankInNameLayer_hpp

#include "cocos2d.h"
//#include "extensions/cocos-ext.h"

using namespace cocos2d;

class RankInNameLayer : Layer{
protected:
public:
    enum Tag{
        T_next,
    };
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(RankInNameLayer);
    virtual void onEnter();
    void next();
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
 /*
    virtual void editBoxEditingDidBegin(ui::EditBox *editBox);
    virtual void editBoxEditingDidEnd(ui::EditBox *editBox);
    virtual void editBoxTextChanged(ui::EditBox *editBox, const std::string& text);
    virtual void editBoxReturn(ui::EditBox *editBox);
*/
  };


#endif /* RankInNameLayer_hpp */
