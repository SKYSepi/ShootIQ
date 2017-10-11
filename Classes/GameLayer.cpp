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
    this->scheduleUpdate();
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
    
    auto move = MoveTo::create(3.0f, position+Point(10000,10000));
    enemy->runAction(move);
    
    addChild(enemy,Z_Enemy);
}

void GameLayer::update(float fream){
    createEnemy(Point(random(0, 1000),random(0, 1000)));
}

