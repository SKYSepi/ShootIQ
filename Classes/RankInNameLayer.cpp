//
//  RankInNameLayer.cpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/20.
//

#include "RankInNameLayer.hpp"
#include "ResultLayer.hpp"

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
    /*
    auto editbox = ui::EditBox::create(Size(200, 100), ui::Scale9Sprite::create());
    editbox->setFont("arial.ttf", 40.0f);
    editbox->setPlaceHolder("ここに入力してください");
    editbox->setPlaceholderFontColor(Color3B::BLACK);
    editbox->setMaxLength(20);
    editbox->setText("NoName");
    editbox->setReturnType(ui::EditBox::KeyboardReturnType::DONE);
    editbox->setInputMode(ui::EditBox::InputMode::ANY);
    editbox->setDelegate(this);
    this->addChild(editbox);
    */
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
