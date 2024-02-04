#include "SmallEnemy.h"
#include <math.h>

SmallEnemy::SmallEnemy(){
	Initalaze();
}

SmallEnemy::~SmallEnemy(){

}

void SmallEnemy::Initalaze(){
	pos_ = {600,100};
	velocity_ = {3,3};
	radius_ = {16,16};
	red_ = 0xff;
	green_ = 0xff;
	blue_ = 0xff;
	alpha_ = 0xff;
	channel_ = 0xffffffff;
	isAlive_ = false;
	count_ = 0;

	theta = 0;
}

void SmallEnemy::Update(){
	if (isAlive_) {
		theta += 0.1f;
		pos_.x += velocity_.x;
		pos_.y += velocity_.y * cosf(theta);
		if (pos_.x > 1280 || pos_.x < 0 && velocity_.x < 0) {
			velocity_.x *= -1;
		}
	}
	else {
		count_++;
		if (count_ >= 600) {
			count_ = 0;
			isAlive_ = true;
		}
	}
}

void SmallEnemy::Draw(Vector2 textureSize, int gh){
	textureSize = { 0,0 };
	if (isAlive_) {
		//Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_.x, (int)radius_.y, 0.0f, channel_, kFillModeSolid);
		Novice::DrawSprite(int(pos_.x - radius_.x), int(pos_.y - radius_.y), gh, 0.5f, 0.5f, 0.0f, channel_);
	}
}
