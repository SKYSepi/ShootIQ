//
//  ResultLayer.cpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/20.
//

#include "ResultLayer.hpp"
#include "StartLayer.hpp"
#include <iostream>


cocos2d::Scene* ResultLayer::createScene(){
    auto scene = cocos2d::Scene::createWithPhysics();
    auto layer = ResultLayer::create();
    scene->addChild(layer);
    //calc_rw();
    return scene;
}

bool ResultLayer::init() {
    if (!Layer::init()) return false;
    calc_rw();
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(ResultLayer::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto nextimage = cocos2d::Sprite::create("exit.png");
    nextimage->setPosition(cocos2d::Point(800,200));
    nextimage->setScale(0.5);
    nextimage->setTag(T_end);
    addChild(nextimage);
    
    auto _data = cocos2d::UserDefault::getInstance();
    auto scoretext = cocos2d::Label::createWithSystemFont(std::to_string(_data->getIntegerForKey("scorehistory")), "Arial", 48);
    scoretext->setPosition(300, 500);
    auto score = cocos2d::Label::createWithSystemFont(std::to_string(_data->getIntegerForKey("result_score")), "Arial", 24);
    score->setPosition(700, 700);
    auto hits = cocos2d::Label::createWithSystemFont(std::to_string((_data->getIntegerForKey("result_hits")!=0)? (_data->getIntegerForKey("result_score")/ _data->getIntegerForKey("result_hits")):0), "Arial", 24);
    hits->setPosition(700, 650);
    auto shots = cocos2d::Label::createWithSystemFont(std::to_string(_data->getIntegerForKey("result_shots")), "Arial", 24);
    shots->setPosition(700, 600);
    addChild(scoretext);
    addChild(score);
    addChild(hits);
    addChild(shots);
    
    auto scorehistory1 = cocos2d::Label::createWithSystemFont(std::to_string(_data->getIntegerForKey("scorehistory1")), "Arial", 24);
    scorehistory1->setPosition(700, 350);
    addChild(scorehistory1);
    auto scorehistory2 = cocos2d::Label::createWithSystemFont(std::to_string(_data->getIntegerForKey("scorehistory2")), "Arial", 24);
    scorehistory2->setPosition(700, 300);
    addChild(scorehistory2);
    auto scorehistory3= cocos2d::Label::createWithSystemFont(std::to_string(_data->getIntegerForKey("scorehistory3")), "Arial", 24);
    scorehistory3->setPosition(700, 250);
    addChild(scorehistory3);
    
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
void ResultLayer::calc_rw(){
    std::cout << "called" << std::endl;
    auto _data = cocos2d::UserDefault::getInstance();
    auto resultscore = _data->getIntegerForKey("result_score");
    auto resultshots = _data->getIntegerForKey("result_shots");
    auto resulthits = _data->getIntegerForKey("result_hits");
    auto avgIQ = (resulthits!=0)?resultscore/resulthits:0;
    
    
    int score;
    score =  resultscore + avgIQ * 40 - resultshots * 30;
    _data->setIntegerForKey("scorehistory", score);
    std::string scorehistory_name;
    auto score_name = _data->getStringForKey("scorehistory_name");
    int scorehistory;
    int scorehistory=0;
    if(_data->getIntegerForKey("scorehistory1") < score){
        scorehistory = _data->getIntegerForKey("scorehistory1");
        _data->setIntegerForKey("scorehistory1", score);
        score = scorehistory;
    }
    if(_data->getIntegerForKey("scorehistory2") < score){
        scorehistory = _data->getIntegerForKey("scorehistory2");
        _data->setIntegerForKey("scorehistory2", score);
        score = scorehistory;
    }
    if(_data->getIntegerForKey("scorehistory3") < score){
        scorehistory = _data->getIntegerForKey("scorehistory3");
        _data->setIntegerForKey("scorehistory3", score);
        score = scorehistory;
    }
    /*_data->setIntegerForKey("scorehistory1",INT_MIN);
    _data->setIntegerForKey("scorehistory2", INT_MIN);
    _data->setIntegerForKey("scorehistory3", INT_MIN);
    */
 }
