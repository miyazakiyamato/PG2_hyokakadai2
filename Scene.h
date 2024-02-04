#pragma once
#include <Novice.h>
class Scene{
protected:
	bool isScene_{};
	
public:
	
	virtual ~Scene();

	virtual void Initalaze() = 0;
	virtual void Update(char* keys,char* preKeys) = 0;
	virtual void Draw() = 0;

	bool GetIsScene() { return isScene_; };
	void SetIsScene(bool isScene);
};

