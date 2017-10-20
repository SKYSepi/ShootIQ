//
//  RankInNameLayer.hpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/20.
//

#ifndef RankInNameLayer_hpp
#define RankInNameLayer_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

class RankInNameLayer : public Layer,public ui::EditBoxDelegate{
protected:
public:
    enum Tag{
        T_next,
    };
    static Scene* createScene();
    virtual bool init();
    //CREATE_FUNC(RankInNameLayer);
    virtual void onEnter();
    void next();
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
 
    virtual void editBoxEditingDidBegin(ui::EditBox*);
    virtual void editBoxEditingDidEnd(ui::EditBox*);
    virtual void editBoxTextChanged(ui::EditBox*,const std::string&);
    virtual void editBoxReturn(ui::EditBox*);

  };


#endif /* RankInNameLayer_hpp */
