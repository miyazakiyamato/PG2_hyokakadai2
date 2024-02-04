#include "Player.h"
#include <Novice.h>
#include "function.h"
Player::Player(){
	for (int i = 0; i < 10; i++) {
		bullet[i] = new Bullet();
	}
	Initalaze();
}
Player::~Player(){

}
void Player::Initalaze(){
	pos_ = { 600,600 };
	velocity_ = { 5,5 };
	radius_ = { 32,32 };
	channel_ = 0xffffffff;
	isAlive_ = false;
	coolTime = 0;
}

void Player::Update(char* keys, char* preKeys){
	Vector2 direction{};
	if (keys[DIK_D] && pos_.x < 1280 - radius_.x) {
		direction.x += 1;
	}
	if (keys[DIK_A] && pos_.x > 0 + radius_.x) {
		direction.x -= 1;
	}
	if (keys[DIK_W] && pos_.y > 0 + radius_.y) {
		direction.y -= 1;
	}
	if (keys[DIK_S] && pos_.y < 720 - radius_.y) {
		direction.y += 1;
	}
	if (!preKeys[DIK_SPACE] ) {
		
	}
	if (keys[DIK_SPACE] && coolTime == 0) {
		for (int i = 0; i < 10; i++) {
			if (!bullet[i]->GetIsAlive()) {
				bullet[i]->SetIsAlive(true);
				bullet[i]->SetPos(pos_);
				break;
			}
		}
		coolTime++;
	}
	CTcount(coolTime, 15);
	float ruto = Length(direction.x, direction.y);
	if (ruto != 0.0f) {
		pos_.x += direction.x / ruto * velocity_.x;
		pos_.y += direction.y / ruto * velocity_.y;
	}
	for (int i = 0; i < 10; i++) {
		bullet[i]->Update(keys, preKeys);
	}
}

void Player::Draw(Vector2 textureSize, int gh){
	textureSize = { 0,0 };
	for (int i = 0; i < 10; i++) {
		bullet[i]->Draw({0,0}, bulletgh_);
	}
	if (isAlive_) {
		//Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_.x, (int)radius_.y, 0.0f, channel_, kFillModeSolid);
		Novice::DrawSprite(int(pos_.x - radius_.x), int(pos_.y - radius_.y), gh, 1.f, 1.f, 0.0f, channel_);
	}
}