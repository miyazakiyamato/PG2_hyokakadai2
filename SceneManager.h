#pragma once
#include "Scene.h"
#include "TitleScene.h"
#include "Stage.h"
#include "ResultScene.h"
class SceneManager{
private:
    int scene_ = 0;
    Scene* Scene_;              
public:
    enum SCENE {
        TITLE,
        GAME,
        RESULT
    };
    
    SceneManager();

    void ChangeScene();         
    void Update(char* keys, char* preKeys);
    void Draw();                           

};

