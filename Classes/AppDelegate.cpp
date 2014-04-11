//
//  example16_1AppDelegate.cpp
//  example12-1
//
//  Created by shuoquan man on 12-10-21.
//  Copyright __MyCompanyName__ 2012年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "GameMenuScene.h"

#define DESIGN_WIDTH 480
#define DESIGN_HEIGHT 320

USING_NS_CC;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
    // pDirector->enableRetinaDisplay(true);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);


	// resolution information
    CCSize size;
    size= pDirector->getWinSize();
    CCLog("***IDONG: Director getWinSize:w=%f,h=%f",size.width,size.height);

    size = pDirector->getWinSizeInPixels();
    CCLog("***IDONG: Director getWinSizeInPixels:w=%f,h=%f",size.width,size.height);
    
    size = pDirector->getVisibleSize();
    CCLog("***IDONG: Director getVisibleSize:w=%f,h=%f",size.width,size.height);

    CCPoint point = pDirector->getVisibleOrigin();
    CCLog("***IDONG: Director getVisibleOrigin:x=%f,y=%f",point.x,point.y);
    
    
    CCLog("***IDONG: Director BS: getContentScaleFactor: scaleFactor=%f",pDirector->getContentScaleFactor());


    // set design resolution size
	pDirector->getOpenGLView()->setDesignResolutionSize(DESIGN_WIDTH,DESIGN_HEIGHT,kResolutionNoBorder);

    CCLog("***IDONG:\n");
    CCLog("***IDONG: Director AS: getContentScaleFactor: scaleFactor=%f",pDirector->getContentScaleFactor());

    size= pDirector->getVisibleSize();
    CCLog("***IDONG: Director getWinSize:w=%f,h=%f",size.width,size.height);

    size = pDirector->getWinSizeInPixels();
    CCLog("***IDONG: Director getWinSizeInPixels:w=%f,h=%f",size.width,size.height);
    
    size = pDirector->getVisibleSize();
    CCLog("***IDONG: Director getVisibleSize:w=%f,h=%f",size.width,size.height);

    point = pDirector->getVisibleOrigin();
    CCLog("***IDONG: Director getVisibleOrigin:x=%f,y=%f",point.x,point.y);


    // create a scene. it's an autorelease object
    CCScene *pScene = GameMenu::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
