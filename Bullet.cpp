#include "Bullet.h"

Bullet::Bullet(){
	Initalaze();
}

Bullet::~Bullet()
{
}

void Bullet::Initalaze(){
	pos_ = { 0,0 };
	velocity_ = { 5,5 };
	radius_ = { 16,16 };
	channel_ = 0xffffffff;
	isAlive_ = false;
}

void Bullet::Update(char* keys, char* preKeys){
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

	}
	if (isAlive_) {
		pos_.y -= velocity_.y;
	}
	if (pos_.y < 0) {
		isAlive_ = false;
	}
}

void Bullet::Draw(Vector2 textureSize, int gh){
	textureSize = { 0,0 };
	if (isAlive_) {
		//Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_.x, (int)radius_.y, 0.0f, channel_, kFillModeSolid);
		Novice::DrawSprite(int(pos_.x - radius_.x), int(pos_.y - radius_.y), gh, 0.5f, 0.5f, 0.0f, channel_);
	}
}
