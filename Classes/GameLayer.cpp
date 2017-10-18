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
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    return scene;
}

bool GameLayer::init(){
    if(!Layer::init())return false;
    this->schedule(schedule_selector(GameLayer::pushEnemy), 0.3);
    initListener();
    MakePointer();
    //this->scheduleUpdate();
    return true;
}

void GameLayer::onEnter(){
    Layer::onEnter();
    
    //for(int i=0;i<1500;i+=100)for(int j=0;j<1000;j+=100)createEnemy(Point(i,j));
}

void GameLayer::createEnemy(cocos2d::Point position){
    auto p_physics = PHYSICSBODY_MATERIAL_DEFAULT;
    p_physics.restitution=0;
    p_physics.friction=0;
    auto enemy = Sprite::create("/Users/seita/Develop/ShootIQ/Resources/P_"+std::to_string(random(0, 4)*50)+".png");
    enemy->setPosition(position);
    enemy->setTag(T_Enemy);
    auto penemy = PhysicsBody::createBox(enemy->getContentSize(),p_physics);
    penemy->setGravityEnable(false);
    penemy->applyImpulse(Vec2(100000, 0));
    penemy->setDynamic(true);
    penemy->setRotationEnable(false);
    penemy->setCategoryBitmask(T_Enemy);
    penemy->setCollisionBitmask(T_Ball);
    penemy->setContactTestBitmask(INT_MAX);
    enemy->setPhysicsBody(penemy);
    
 //   auto move = MoveTo::create(6.0f, position+Point(500,0));
//    enemy->runAction(move);
    
    this->addChild(enemy,Z_Enemy,Z_Ball);
}

void GameLayer::createchacheball(cocos2d::Point position,cocos2d::Point moved){
    auto p_physics = PHYSICSBODY_MATERIAL_DEFAULT;
    p_physics.restitution=0;
    p_physics.friction=0;
    
    auto ball = Sprite::create("/Users/seita/Develop/ShootIQ/Resources/monsterball.png");
    ball->setPosition(position);
    ball->setScale(0.1);
    ball->setTag(T_Ball);
    auto div = moved-position;
    //auto move = MoveBy::create(sqrt(1000000+pow((1000/div.y)*div.x,2))*0.0015f, Point(1000/div.y*div.x,1000));
    //ball->runAction(move);
    
    auto pball = PhysicsBody::createBox(ball->getContentSize(),p_physics);
    pball->setGravityEnable(false);
    pball->applyImpulse(Point(div.x,1000)*10000);
    pball->setDynamic(true);
    pball->setRotationEnable(false);
    pball->setCategoryBitmask(T_Ball);
    pball->setCollisionBitmask(T_Enemy);
    pball->setContactTestBitmask(INT_MAX);
    ball->setPhysicsBody(pball);
    
    this->addChild(ball,Z_Ball,T_Ball);
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

void GameLayer::onMouseMove(cocos2d::Event* event){
    auto mouse = (EventMouse*)event;
   p_pointer->setPosition(Point(mouse->getCursorX(), mouse->getCursorY()));
}

bool GameLayer::onContactBegin(cocos2d::PhysicsContact& contact){
    
    auto bodyA = contact.getShapeA()->getBody()->getNode();
    this->removeChild(bodyA);
    this->removeChild(contact.getShapeB()->getBody()->getNode());
    
    auto p = Sprite::create("/Users/seita/Develop/ShootIQ/Resources/pointer.png");
    p->setPosition(100,100);
    this->addChild(p);
    return true;
}
void GameLayer::MakePointer(){
    auto pointer = Sprite::create("/Users/seita/Develop/ShootIQ/Resources/pointer.png");
    pointer->setScale(0.8);
    p_pointer=pointer;
    this->addChild(pointer);
}

void GameLayer::initListener(){
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority
    (listener, this);
    
    auto mouselistener = EventListenerMouse::create();
    mouselistener->onMouseMove=CC_CALLBACK_1(GameLayer::onMouseMove, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouselistener, this);
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
}
