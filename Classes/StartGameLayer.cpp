//
//  StartGameLayer.cpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/19.
//

#include "StartGameLayer.hpp"
#include "GameLayer.hpp"
//#include "ScoreHistory.hpp"

cocos2d::Scene* StartGameLayer::createScene(){
    auto scene = cocos2d::Scene::createWithPhysics();
    auto layer = StartGameLayer::create();
    scene->addChild(layer);
    return scene;
}

bool StartGameLayer::init() {
    if (!Layer::init()) return false;
    this->schedule(schedule_selector(StartGameLayer::next), 4.0f);
    this->schedule(schedule_selector(StartGameLayer::countdown), 1.0f);
    auto text = cocos2d::Label::createWithSystemFont(" ", "Arial", 130);
    text->setPosition(cocos2d::Director::getInstance()->getWinSize().width/2,cocos2d::Director::getInstance()->getWinSize().height/2);
    addChild(text);
    p_text = text;
    return true;
}

void StartGameLayer::onEnter() {
    Layer::onEnter();
}

void StartGameLayer::next(float d){
    auto nextsene = GameLayer::createScene();
    //auto fade = cocos2d::TransitionFade::create(0.5f, nextsene,cocos2d::Color3B::WHITE);
    cocos2d::Director::getInstance()->replaceScene(nextsene);
}

void StartGameLayer::countdown(float d){
    static int i = 3;
    p_text->setString(std::to_string(i--));
    p_text->setScale(1/0.8);
    auto scale = cocos2d::ScaleBy::create(1, 0.8);
    p_text->runAction(scale);
    if(i==-1)i=3;
}
