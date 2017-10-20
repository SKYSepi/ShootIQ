//
//  RankInNameLayer.cpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/20.
//

#include "RankInNameLayer.hpp"
#include "ResultLayer.hpp"
#include <iostream>
using namespace cocos2d;

Scene* RankInNameLayer::createScene(){
    auto scene = Scene::createWithPhysics();
    auto layer = RankInNameLayer::create();
    scene->addChild(layer);
    return scene;
}

bool RankInNameLayer::init() {
    if (!Layer::init()) return false;
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(RankInNameLayer::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto editBox = ui::EditBox::create(Size(500,500),"exit.png");
    editBox->EditBox::setFont("Arial", 100);
    editBox->EditBox::setPlaceHolder("Input Here");
    editBox->EditBox::setFontColor(Color3B::WHITE);
    editBox->EditBox::setPlaceholderFontColor(Color3B::WHITE);
    editBox->setMaxLength(20);
    editBox->setText("Input Here");
    editBox->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
    editBox->setInputMode(ui::EditBox::InputMode::SINGLE_LINE);
    editBox->ui::EditBox::setPosition(Vec2(0, 0));
    editBox->setAnchorPoint(Vec2(0,0));
    
    editBox->setDelegate(this);
    this->addChild(editBox);
    
    return true;
}

void RankInNameLayer::onEnter() {
    Layer::onEnter();
}

void RankInNameLayer::next(){
    auto nextsene = ResultLayer::createScene();
    cocos2d::Director::getInstance()->replaceScene(nextsene);
}

bool RankInNameLayer::onTouchBegan(Touch *touch, Event *unused_event){
    /*if (this->getChildByTag(T_next)->getBoundingBox().containsPoint(touch->getLocation())) {
        auto scene = ResultLayer::createScene();
        cocos2d::Director::getInstance()->replaceScene(scene);
    }*/
    return true;
}


void RankInNameLayer::editBoxEditingDidBegin(ui::EditBox *editBox){
    std::cout << "InputBegin" << std::endl;
}
void RankInNameLayer::editBoxEditingDidEnd(ui::EditBox *editBox){
    std::cout << "InputEditing" << std::endl;
}
void RankInNameLayer::editBoxTextChanged(ui::EditBox *editBox, const std::string& text){
    std::cout << "InputTextChanged" << std::endl;
}
void RankInNameLayer::editBoxReturn(ui::EditBox *editBox){
    std::cout << "InputReturn" << std::endl;
}

