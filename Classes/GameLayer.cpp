//
//  GameLayer.cpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/10.
//

#include "ResultLayer.hpp"
#include "GameLayer.hpp"
#include "math.h"
//#include "ScoreHistory.hpp"

#define WINSIZE Director::getInstance()->getWinSize();

USING_NS_CC;

Scene* GameLayer::createScene(){
    auto scene = Scene::createWithPhysics();
    auto _bg = LayerColor::create(Color4B::GRAY,  Director::getInstance()->getVisibleSize().width,  Director::getInstance()->getVisibleSize().height);
    scene->addChild(_bg);
    
    auto layer = GameLayer::create();
    scene->addChild(layer);
   // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    return scene;
}

bool GameLayer::init(){
    if(!Layer::init())return false;
    for (int i=0; i<5; i++) point_array[i]=i*50;
    this->schedule(schedule_selector(GameLayer::pushEnemy), 0.4);
    this->schedule(schedule_selector(GameLayer::endGame), 60.0f);
    
    score = Number_of_shots = Number_of_hits =0;
    initListener();
    MakePointer();
    
    auto text = Label::createWithSystemFont(std::to_string(score)+":"+std::to_string(Number_of_hits), "Arial", 48);
    text->setPosition(500, 500);
    addChild(text);
    p_label=text;
    return true;
}

void GameLayer::onEnter(){
    Layer::onEnter();
}

void GameLayer::createEnemy(cocos2d::Point position){
    auto p_physics = PHYSICSBODY_MATERIAL_DEFAULT;
    p_physics.restitution=0;
    p_physics.friction=0;
    
    auto rand = random(0, 4);
    auto point = rand*50;
    
    auto enemy = Sprite::create("P_"+std::to_string(point)+".png");
    enemy->setUserData(&point_array[rand]);
    enemy->setPosition(position);
    enemy->setTag(T_Enemy);
    auto penemy = PhysicsBody::createBox(enemy->getContentSize(),p_physics);
    penemy->setGravityEnable(false);
    penemy->applyImpulse(Vec2(200000, 0));
    penemy->setDynamic(true);
    penemy->setRotationEnable(false);
    penemy->setCategoryBitmask(1);
    penemy->setContactTestBitmask(2);
    enemy->setPhysicsBody(penemy);
    
   this->addChild(enemy,Z_Enemy,T_Ball);
}

void GameLayer::createchacheball(cocos2d::Point position,cocos2d::Point moved){
    auto p_physics = PHYSICSBODY_MATERIAL_DEFAULT;
    p_physics.restitution=0;
    p_physics.friction=0;
    shot();
    auto ball = Sprite::create("monsterball.png");
    ball->setPosition(position);
    ball->setScale(0.1);
    ball->setTag(T_Ball);
    auto div = moved-position;
    auto root = sqrt(pow(div.x, 2)+pow(div.y, 2));
    auto pball = PhysicsBody::createBox(ball->getContentSize(),p_physics);
    pball->setGravityEnable(false);
    pball->applyImpulse(Point(div.x/root,div.y/root)*40000000);
    pball->setDynamic(true);
    pball->setRotationEnable(false);
    pball->setCategoryBitmask(2);
    pball->setContactTestBitmask(1);
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
    
    auto bodyB = contact.getShapeB()->getBody()->getNode();
    
    void* adr;
    if (bodyA!=NULL && bodyA->getUserData()!=NULL) {
        adr = bodyA->getUserData();
    }else if (bodyB!=NULL && bodyB->getUserData()!=NULL){
        adr = bodyB->getUserData();
    }
    if(*(int*)adr <=200)addscore(*(int*)adr);
    hits();
    UserDefault* _data = UserDefault::getInstance();
    p_label->setString(std::to_string(score)+":"+std::to_string(Number_of_shots)+":"+std::to_string(score/Number_of_hits)+":"+_data->getStringForKey("key"));
    this->removeChild(bodyA);
    this->removeChild(bodyB);
 
    return true;
}
void GameLayer::MakePointer(){
    auto pointer = Sprite::create("pointer.png");
    pointer->setScale(0.3);
    p_pointer=pointer;
    this->addChild(pointer,Z_Pointer);
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

int GameLayer::shot(){
    return ++Number_of_shots;
}
int GameLayer::hits(){
    return ++Number_of_hits;
}
void GameLayer::addscore(int i){
    score+=i;
}

void GameLayer::endGame(float d){
    UserDefault* _userdata = UserDefault::getInstance();
    _userdata->setIntegerForKey("result_score", score);
    _userdata->setIntegerForKey("result_hits", Number_of_hits);
    _userdata->setIntegerForKey("result_shots", Number_of_shots);
    
    auto scene = ResultLayer::createScene();
    TransitionFade* fade = TransitionFade::create(0.5f, scene, Color3B::WHITE);
    Director::getInstance()->replaceScene(fade);
}
