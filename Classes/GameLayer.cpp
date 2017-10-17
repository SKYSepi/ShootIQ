//
//  GameLayer.cpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/10.
//

#include "GameLayer.hpp"
#include "math.h"

#define WINSIZE Director::getInstance()->getWinSize();

USING_NS_CC;

Scene* GameLayer::createScene(){
    auto scene = Scene::createWithPhysics();
    auto _bg = LayerColor::create(Color4B::GRAY,  Director::getInstance()->getVisibleSize().width,  Director::getInstance()->getVisibleSize().height);
    scene->addChild(_bg);
    
    auto layer = GameLayer::create();
    scene->addChild(layer);
    
    return scene;
}

bool GameLayer::init(){
    if(!Layer::init())return false;
    this->schedule(schedule_selector(GameLayer::pushEnemy), 0.3);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority
    (listener, this);
    auto mouselistener = EventListenerMouse::create();
 //   mouselistener->onMouseMove=CC_CALLBACK_1(GameLayer::onMouseMove, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouselistener, this);

    //this->scheduleUpdate();
    return true;
}

void GameLayer::onEnter(){
    Layer::onEnter();
    
    //for(int i=0;i<1500;i+=100)for(int j=0;j<1000;j+=100)createEnemy(Point(i,j));
}

void GameLayer::createEnemy(cocos2d::Point position){
    auto enemy = Sprite::create("/Users/seita/Develop/ShootIQ/Resources/P_"+std::to_string(random(0, 4)*50)+".png");
    enemy->setPosition(position);
    enemy->setTag(T_Enemy);
    
    auto move = MoveTo::create(6.0f, position+Point(1200,0));
    enemy->runAction(move);
    
    addChild(enemy,Z_Enemy);
}

void GameLayer::createchacheball(cocos2d::Point position,cocos2d::Point moved){
    auto ball = Sprite::create("/Users/seita/Develop/ShootIQ/Resources/monsterball.png");
    ball->setPosition(position);
    ball->setScale(0.1);
    ball->setTag(T_Ball);
    auto div = moved-position;
    auto move = MoveBy::create(sqrt(1000000+pow((1000/div.y)*div.x,2))*0.0015f, Point(1000/div.y*div.x,1000));
    ball->runAction(move);
    
    addChild(ball,Z_Ball);
}

void GameLayer::pushEnemy(float d){
    auto size = Director::getInstance()->getWinSize();
    createEnemy(Point(-50,random(200,(int)size.height)));
}

bool GameLayer::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent){
    auto point = pTouch->getLocation();
    createchacheball(Point(Director::getInstance()->getWinSize().width/2,5),point);
    return true;
}

void onMouseMove(cocos2d::Event* event){
    auto mouse = (EventMouse*)event;
    Point(mouse->getCursorX(), mouse->getCursorY());
}
