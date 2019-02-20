//
// Created by oleh on 13.03.18.
//

#pragma once
#include "cocos2d.h"

class StartScene :public cocos2d::Layer{
public:
    cocos2d::Vector<cocos2d::Sprite*> sprites;
    CREATE_FUNC(StartScene);
    bool init();
    void update(float dt);

    void drawGrid();
};


