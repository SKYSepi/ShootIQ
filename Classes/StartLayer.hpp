//
//  StartLayer.hpp
//  ShootIQ
//
//  Created by skytomo on 2017/10/16.
//

	enum Tag {
		T_START,
		T_RULE,
		T_EXIT
	};

	

#ifndef StartLayer_hpp
#define StartLayer_hpp

#include "cocos2d.h"

class ButtonSprite : public cocos2d::Sprite {
};

class StartLayer : public cocos2d::Layer {
protected:

	void createButton(cocos2d::Point position);

public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StartLayer);
	virtual void onEnter();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
};

#endif 