//
//  ResultLayer.cpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/20.
//

#include "ResultLayer.hpp"
#include "StartLayer.hpp"


cocos2d::Scene* ResultLayer::createScene(){
    auto scene = cocos2d::Scene::createWithPhysics();
    auto layer = ResultLayer::create();
    scene->addChild(layer);
    return scene;
}

bool ResultLayer::init() {
    if (!Layer::init()) return false;
    
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(ResultLayer::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto nextimage = cocos2d::Sprite::create("exit.png");
    nextimage->setPosition(cocos2d::Point(800,200));
    nextimage->setScale(0.5);
    nextimage->setTag(T_end);
    addChild(nextimage);
    
    auto text = cocos2d::Label::createWithSystemFont(cocos2d::UserDefault::getInstance()->getStringForKey("key"), "Arial", 48);
    text->setPosition(500, 500);
    addChild(text);
    
    return true;
}

void ResultLayer::onEnter() {
    Layer::onEnter();
}

void ResultLayer::next(){
    auto nextsene = StartLayer::createScene();
    //auto fade = cocos2d::TransitionFade::create(0.5f, nextsene,cocos2d::Color3B::WHITE);
    cocos2d::Director::getInstance()->replaceScene(nextsene);
}

bool ResultLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){
    if (this->getChildByTag(T_end)->getBoundingBox().containsPoint(touch->getLocation())) {
        auto scene = StartLayer::createScene();
        cocos2d::Director::getInstance()->replaceScene(scene);
    }
    return true;
}
