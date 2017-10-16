//
//  GameLayer.cpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/10.
//

#include "GameLayer.hpp"

#define WINSIZE Director::getInstance()->getWinSize();

USING_NS_CC;

Scene* GameLayer::createScene(){
    auto scene = Scene::createWithPhysics();
    auto layer = GameLayer::create();
    scene->addChild(layer);
    
    return scene;
}

bool GameLayer::init(){
    if(!Layer::init())return false;
    this->schedule(schedule_selector(GameLayer::pushEnemy), 1);
    
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(GameLayer::onKeyPressed, this);
     listener->onKeyReleased = CC_CALLBACK_2(GameLayer::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    //this->scheduleUpdate();
    return true;
}

void GameLayer::onEnter(){
    Layer::onEnter();
    
    //for(int i=0;i<1500;i+=100)for(int j=0;j<1000;j+=100)createEnemy(Point(i,j));
}

void GameLayer::createEnemy(cocos2d::Point position){
    auto enemy = Sprite::create("/Users/seita/Develop/ShootIQ/Resources/P_0.png");
    enemy->setPosition(position);
    enemy->setTag(T_Enemy);
    
    auto move = MoveTo::create(6.0f, position+Point(1200,0));
    enemy->runAction(move);
    
    addChild(enemy,Z_Enemy);
}

void GameLayer::createchacheball(cocos2d::Point position){
    auto ball = Sprite::create("/Users/seita/Develop/ShootIQ/Resources/monsterball.png");
    ball->setPosition(position);
    ball->setScale(0.1);
    ball->setTag(T_Ball);
    
    auto move = MoveTo::create(0.75f, position+Point(0,600));
    ball->runAction(move);
    
    addChild(ball,Z_Ball);
}

void GameLayer::pushEnemy(float d){
    createEnemy(Point(-50,random(100,1000)));
}

 void GameLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event){
    createchacheball(Point(700,0));
}

void GameLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event){
    
}
