#pragma once
#include "Vector2.h"
struct Vertex {
	Vector2 leftTop;
	Vector2 rightTop;
	Vector2 leftBottom;
	Vector2 rightBottom;
};
struct Matrix3x3 {
	float m[3][3];
};
struct MapPos {
	int width;
	int height;
};
const int Map_w = 30;
const int Map_h = 17;
struct TileMap {
	int map[Map_h][Map_w];
};
enum SceneScene {
	TITLE,
	TUTORIAL,
	STAGESELECT,
	STAGESCENE,
};
