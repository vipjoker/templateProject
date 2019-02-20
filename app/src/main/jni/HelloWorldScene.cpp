#include "HelloWorldScene.h"
#include "audio/include/SimpleAudioEngine.h"

USING_NS_CC;

Scene *HelloWorld::createScene()
{
    Scene *sceen = Scene::create();
    auto layer = HelloWorld::create();
    sceen->addChild(layer);
    return sceen;
}


bool HelloWorld::init()
{
    FileUtils::getInstance();
    if (!Layer::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

std::vector<std::string> files = FileUtils::getInstance()->listFiles("/");
for(auto &str:files){
    log("%s",str.c_str());
}

    auto label = Label::createWithTTF("Hello World", "primer print.ttf", 50);
    label->setTextColor(Color4B::WHITE);
    this->addChild(label, 1);
    label->setPosition(visibleSize/2);
    auto sprt = Sprite::create("rocket.png");
    sprt->setPosition(visibleSize/2);
    addChild(sprt);
    log("WORKS");
    EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [](Touch *touch, Event *event){
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("gunfire.wav");
        return true;
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);



    return true;
}

