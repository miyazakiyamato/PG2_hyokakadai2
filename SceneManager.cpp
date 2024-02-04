#include "SceneManager.h"

SceneManager::SceneManager(){
    Scene_ = NULL;
}

void SceneManager::ChangeScene(){

    if (Scene_ != NULL && Scene_->GetIsScene()) {
        Scene_ = NULL;
    }
    
    switch (scene_) {          
    case TITLE:
        if (Scene_ == NULL) {
            Scene_ = new TitleScene();
        }
        break;
    case GAME:
        if (Scene_ == NULL) {
            Scene_ = new Stage();
        }
        break;
    case RESULT:
        if (Scene_ == NULL) {
            Scene_ = new ResultScene();
        }
        break;
    default:
        break;
    }
}

void SceneManager::Update(char* keys, char* preKeys){
    if (Scene_ != NULL) {
        Scene_->Update(keys, preKeys);
        if (Scene_->GetIsScene()) {
            scene_++;
            if (scene_ > 2) {
                scene_ = 0;
            }
        }
    }
}

void SceneManager::Draw(){
    if (Scene_ != NULL) {
        Scene_->Draw();
    }
}
