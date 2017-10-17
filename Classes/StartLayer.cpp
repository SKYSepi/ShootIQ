//
//  StartLayer.cpp
//  ShootIQ
//
//  Created by skytomo on 2017/10/16
//

#include "StartLayer.hpp"

#define WINSIZE Director::getInstance()->getWinSize();

USING_NS_CC;

Scene* StartLayer::createScene() {
	auto scene = Scene::createWithPhysics();
	auto layer = StartLayer::create();
	scene->addChild(layer);
	return scene;
}

bool StartLayer::init() {
	if (!Layer::init()) return false;
	createButton(cocos2d::Point(0, 0));

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(StartLayer::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void StartLayer::createButton(cocos2d::Point position) {
	Size winSize = Director::getInstance()->getWinSize();

	auto button1 = Sprite::create("start.png");
	button1->setTag(T_START);
	button1->setPosition(Point(200, 200));
	button1->setScale(0.5);
	addChild(button1, 1);

	auto button2 = Sprite::create("rule.png");
	button2->setTag(T_RULE);
	button2->setPosition(Point(500, 200));
	button2->setScale(0.5);
	addChild(button2, 1);

	auto button3 = Sprite::create("exit.png");
	button3->setTag(T_EXIT);
	button3->setPosition(Point(800, 200));
	button3->setScale(0.5);
	addChild(button3, 1);

}

Sprite StartLayer::*getTouchButton(cocos2d::Touch *touch) {
	for (int tag = 0; tag < 3; tag++) {
		auto button = (Sprite*)getChildByTag(tag);
		if (button&&button->getBoundingBox().containsPoint(touch->getLocation())) return button;
	}
	return nullptr;
}

bool StartLayer::onTouchBegan(Touch *touch, Event *unused_event) {

	return true;
}

void StartLayer::onEnter() {
	Layer::onEnter();

	//for(int i=0;i<1500;i+=100)for(int j=0;j<1000;j+=100)createEnemy(Point(i,j));
}



