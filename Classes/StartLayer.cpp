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
    auto _bg = LayerColor::create(Color4B::GRAY,  Director::getInstance()->getVisibleSize().width,  Director::getInstance()->getVisibleSize().height);
    scene->addChild(_bg,T_bg);
    auto layer = StartLayer::create();
    scene->addChild(layer);
    
    return scene;
}

bool StartLayer::init() {
    if (!Layer::init()) return false;
    //clear();
    ranking();
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
     addChild(button1, T_sprite);
     
     auto button2 = ButtonSprite::create("rule.png");
     button2->setTag(T_RULE);
     button2->setPosition(Point(500, 200));
     button2->setScale(0.5);
     addChild(button2, T_sprite);
     
     auto button3 = ButtonSprite::create("exit.png");
     button3->setTag(T_EXIT);
     button3->setPosition(Point(800, 200));
     button3->setScale(0.5);
     addChild(button3, T_sprite);
     
    
}

bool StartLayer::onTouchBegan(Touch *touch, Event *unused_event) {
    if (this->getChildByTag(T_START)->getBoundingBox().containsPoint(touch->getLocation())) {
        auto scene = StartGameLayer::createScene();
        TransitionFade* fade = TransitionFade::create(0.5f, scene, Color3B::WHITE);
        Director::getInstance()->replaceScene(fade);
    }
    else if (this->getChildByTag(T_RULE)->getBoundingBox().containsPoint(touch->getLocation())) {
        clear();
    }
    else if (this->getChildByTag(T_EXIT)->getBoundingBox().containsPoint(touch->getLocation())) {
        exit(1);
    }
    return true;
}


void StartLayer::onEnter() {
    Layer::onEnter();
}

void StartLayer::clear(){
    auto _data = cocos2d::UserDefault::getInstance();
    _data->setIntegerForKey("scorehistory1",INT_MIN);
    _data->setIntegerForKey("scorehistory2", INT_MIN);
    _data->setIntegerForKey("scorehistory3", INT_MIN);
    _data->setStringForKey("scorehistory1_name", "");
    _data->setStringForKey("scorehistory2_name", "");
    _data->setStringForKey("scorehistory3_name", "");
    
}

void StartLayer::ranking(){
    auto _data = cocos2d::UserDefault::getInstance();
    auto winsize = Director::getInstance()->getWinSize();
    auto scorehistory1 = cocos2d::Label::createWithSystemFont(std::to_string(_data->getIntegerForKey("scorehistory1")), "Arial", 48);
    scorehistory1->setPosition(winsize.width/2+300, 600);
    addChild(scorehistory1,T_sprite);
    auto scorehistory2 = cocos2d::Label::createWithSystemFont(std::to_string(_data->getIntegerForKey("scorehistory2")), "Arial", 48);
    scorehistory2->setPosition(winsize.width/2+300, 550);
    addChild(scorehistory2,T_sprite);
    auto scorehistory3 = cocos2d::Label::createWithSystemFont(std::to_string(_data->getIntegerForKey("scorehistory3")), "Arial", 48);
    scorehistory3->setPosition(winsize.width/2+300, 500);
    addChild(scorehistory3,T_sprite);
    
    auto scorehistory1_name = cocos2d::Label::createWithSystemFont(_data->getStringForKey("scorehistory1_name"), "Arial", 48);
    scorehistory1_name->setPosition(winsize.width/2, 600);
    addChild(scorehistory1_name,T_sprite);
    auto scorehistory2_name = cocos2d::Label::createWithSystemFont(_data->getStringForKey("scorehistory2_name"), "Arial", 48);
    scorehistory2_name->setPosition(winsize.width/2, 550);
    addChild(scorehistory2_name,T_sprite);
    auto scorehistory3_name = cocos2d::Label::createWithSystemFont(_data->getStringForKey("scorehistory3_name"), "Arial", 48);
    scorehistory3_name->setPosition(winsize.width/2, 500);
    addChild(scorehistory3_name,T_sprite);
    
    auto ranking_text = cocos2d::Label::createWithSystemFont("ランキング", "Arial" , 60);
    ranking_text->setPosition(3*winsize.width/4,700);
    addChild(ranking_text,T_sprite);
    
}
