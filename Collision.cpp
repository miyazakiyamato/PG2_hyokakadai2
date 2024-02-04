#include "Collision.h"
#include "function.h"


Collision* Collision::GetInstance()
{
    static Collision instance;
    return &instance;
}

bool Collision::CircleCollision(Vector2 pos,Vector2 pos2,float radius,float radius2){
    if (Length(pos.x - pos2.x, pos.y - pos2.y) <= radius + radius2) {
        return true;
    }
    return false;
}
