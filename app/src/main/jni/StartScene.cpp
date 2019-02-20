//
// Created by oleh on 13.03.18.
//

#include <CCGraphicsNode.h>
#include "StartScene.h"

using namespace cocos2d;
bool StartScene::init() {
    if(!Layer::init()){
        return false;
    }

    Texture2D *texture2d = Director::getInstance()->getTextureCache()->addImage("cube.png");
    SpriteFrame *frame = SpriteFrame::createWithTexture(texture2d, cocos2d::Rect(Vec2::ZERO, texture2d->getContentSize()));
    SpriteFrameCache::getInstance()->addSpriteFrame(frame, "cube");

    Color3B darkViolet(63,51,101);
    Color3B pink(240,3,117);
    auto label = Label::createWithTTF("Hello world", "primer print.ttf",50);
    auto colorLayout = LayerColor::create(Color4B(darkViolet));
    Size size = Director::getInstance()->getVisibleSize();
    colorLayout->setContentSize(size);




    auto sprite= Sprite::create("tiger.jpg");
    auto gr= creator::GraphicsNode::create();

    gr->beginPath();
    gr->moveTo(0,0);
    gr->lineTo(50,0);
    gr->lineTo(50, 15);
    gr->bezierCurveTo(75,10,75,35,50,35);
    gr->lineTo(50, 50);
    gr->lineTo(0, 50);

    gr->close();

    auto action = RepeatForever::create(RotateBy::create(1,90));
    gr->fill();
    auto clipNode = ClippingNode::create(gr);

    clipNode->setPosition(100, 100);

    clipNode->addChild(sprite);
    clipNode->runAction(action);

    addChild(clipNode, 10);

    label->setColor(pink);
    label->setPosition(size/2);


    auto spr = Sprite::createWithSpriteFrameName("cube");

    spr->setPosition(size / 2);
    auto rotateBy = RotateBy::create(4,Vec3(0,180,0));
    auto repeate = RepeatForever::create(rotateBy);
    auto smoke = ParticleGalaxy::create();
    smoke->setPosition(size.height / 3, size.width / 2);
    addChild(smoke,3 );
    spr->runAction(repeate);
    sprites.pushBack(spr);
    addChild(spr,2);
    addChild(colorLayout,1);
    addChild(label,2);

    drawGrid();
    schedule(CC_CALLBACK_1(StartScene::update,this),1,"update");
    return true;

}

void StartScene::update(float dt) {

    for(auto sprt:sprites){
//        sprt->setPosition(sprt->getPosition() + sprt->getContentSize());
    }
}

void StartScene::drawGrid() {
    Vec2 v(0,100);


    for(int i = 0; i < 10;++i){
        auto sprite = Sprite::createWithSpriteFrameName("cube");
        sprite->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
        sprite->setOpacity(100);
        sprite->setPosition(v);
        addChild(sprite,2);
        v += Vec2(sprite->getContentSize().width,0);
    }
}
