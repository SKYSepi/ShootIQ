//
//  GameLayer.cpp
//  ShootIQ
//
//  Created by 東誠太 on 2017/10/10.
//

#include "GameLayer.hpp"

USING_NS_CC;

Scene* GameLayer::createScene(){
    auto scene = Scene::create();
    auto layer = GameLayer::create();
    scene->addChild(layer);
    
    return scene;
}

bool GameLayer::init(){
    if(!Layer::init())return false;
    return true;
}
