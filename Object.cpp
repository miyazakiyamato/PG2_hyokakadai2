#include "Object.h"

void Object::SetPos(Vector2 pos){
	pos_ = pos;
}

void Object::SetVelocity(Vector2 velocity){
	velocity_ = velocity;
}

void Object::SetRed(int red){
	red_ = red;
}

void Object::SetGreen(int green){
	green_ = green;
}

void Object::SetBlue(int blue){
	blue_ = blue;
}

void Object::SetChannel(int red, int green, int blue, int alpha){
	unsigned int color{};
	color |= (red & 0xFF) << 24;
	color |= (green & 0xFF) << 16;
	color |= (blue & 0xFF) << 8;
	color |= (alpha & 0xFF);
	channel_ = color;
}

void Object::SetChannel(unsigned int channel){
	channel_ = channel;
}

void Object::SetRadius(Vector2 radius){
	radius_ = radius;
}

void Object::SetIsAlive(bool isAlive){
	isAlive_ = isAlive;
}
