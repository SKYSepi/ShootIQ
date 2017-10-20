//
//  StartLayer.cpp
//  ShootIQ
//
//  Created by skytomo on 2017/10/16
//

#include "StartGameLayer.hpp"
#include "StartLayer.hpp"
#include "ScoreHistory.hpp"

#define WINSIZE Director::getInstance()->getWinSize();

USING_NS_CC;

Scene* StartLayer::createScene(){
    auto scene = Scene::createWithPhysics();
    auto layer = StartLayer::create();
    scene->addChild(layer);
    return scene;
}

bool StartLayer::init() {
    if (!Layer::init()) return false;
    createButton(cocos2d::Point(0, 0));
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(StartLayer::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

void StartLayer::createButton(cocos2d::Point position) {
    Size winSize = Director::getInstance()->getWinSize();
     
     auto button1 = ButtonSprite::create("start.png");
     button1->setTag(T_START);
     button1->setPosition(Point(200, 200));
     button1->setScale(0.5);
     addChild(button1, 1);
     
     auto button2 = ButtonSprite::create("rule.png");
     button2->setTag(T_RULE);
     button2->setPosition(Point(500, 200));
     button2->setScale(0.5);
     addChild(button2, 1);
     
     auto button3 = ButtonSprite::create("exit.png");
     button3->setTag(T_EXIT);
     button3->setPosition(Point(800, 200));
     button3->setScale(0.5);
     addChild(button3, 1);
     
    
}

bool StartLayer::onTouchBegan(Touch *touch, Event *unused_event) {
    if (this->getChildByTag(T_START)->getBoundingBox().containsPoint(touch->getLocation())) {
        auto scene = StartGameLayer::createScene();
        TransitionFade* fade = TransitionFade::create(0.5f, scene, Color3B::WHITE);
        Director::getInstance()->replaceScene(fade);
    }
    else if (this->getChildByTag(T_RULE)->getBoundingBox().containsPoint(touch->getLocation())) {
        
    }
    else if (this->getChildByTag(T_EXIT)->getBoundingBox().containsPoint(touch->getLocation())) {
        exit(1);
    }
    return true;
}


void StartLayer::onEnter() {
    Layer::onEnter();
}





