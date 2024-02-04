#pragma once
#include <Novice.h>
#include "Struct.h"


class Object{
protected:
	Vector2 pos_{};
	Vector2 velocity_{};
	Vector2 radius_{};
	//int gh = 0;
	int red_ = 0xff;
	int green_ = 0xff;
	int blue_ = 0xff;
	int alpha_ = 0xff;
	unsigned int channel_ = 0xffffffff;
	bool isAlive_{};

public:

	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	Vector2 GetPos() { return pos_; };
	void SetPos(Vector2 pos);
	float GetVelocityX() { return velocity_.x; };
	float GetVelocityY() { return velocity_.y; };
	Vector2 GetVelocity() { return velocity_; };
	void SetVelocity(Vector2 velocity);
	float GetRadiusX() { return radius_.x; };
	float GetRadiusY() { return radius_.y; };
	Vector2 GetRadius() { return radius_; };
	void SetRadius(Vector2 radius);
	int GetRed() { return red_; };
	void SetRed(int red);
	int GetGreen() { return green_; };
	void SetGreen(int green);
	int GetBlue() { return blue_; };
	void SetBlue(int blue);
	unsigned int GetChannel() { return channel_; };
	void SetChannel(int red,int green,int blue,int alpha);
	void SetChannel(unsigned int channel);
	bool GetIsAlive() { return isAlive_; };
	void SetIsAlive(bool isAlive);
};

