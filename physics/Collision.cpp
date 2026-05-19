#include "Collision.h"

bool isColliding(Object* obj1, Object* obj2)
{
    if (obj1 == nullptr || ob2 == nullptr){
        return;
    }
    if(obj1->shape->type == ShapeType::AABB && bj1->shape->type == ShapeType::AABB )
    {
        return AABBVsAABB(obj1, obj2);
    }
    if(obj1->shape->type == ShapeType::Circle && bj1->shape->type == ShapeType::Circle )
    {
        return CircleVsCircle(obj1, obj2);
    }
    if(obj1->shape->type == ShapeType::AABB && bj1->shape->type == ShapeType::Circle )
    {
        return AABBVsCircle(obj1, obj2);
    }
    if(obj1->shape->type == ShapeType::Circle && bj1->shape->type == ShapeType::AABB )
    {
        return AABBVsCircle(obj2, obj1);
    }

}

bool CircleVsCircle(Object* obj1, Object* obj2){
    Circle *circle1 = static_cast<Circle *>(obj1->shape);
    Circle *circle2 = static_cast<Circle *>(obj2->shape);
    float r = circle1->radius + circle2->radius;
    r *= r;
    float dx = (obj1->position.x - obj2->position.x)
    float dy = (obj1->position.y - obj2->position.y)
    return r >= dx * dx + dy * dy;
}

bool AABBVsAABB(Object* obj1, Object* obj2){
    AABB *aabb1 = static_cast<AABB *>(obj1->shape);
    AABB *aabb2 = static_cast<AABB *>(obj2->shape);
    if (obj1->position.x + aabb1->halfSize.x < obj2->position.x - aabb2->halfSize.x
    || obj2->position.x + aabb2->halfSize.x < obj1->position.x - aabb1->halfSize.x) return false;
    if (obj1->position.y + aabb1->halfSize.y < obj2->position.y - aabb2->halfSize.y
    || obj2->position.y + aabb2->halfSize.y < obj1->position.y - aabb1->halfSize.y) return false;

    return true;
}

bool AABBVsCircle(Object* obj1, Object* obj2){}