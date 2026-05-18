#include "../math/Vec2.h"
#include <iostream>

// axis aligned bounding boxes
struct AABB {
    Vec2 min;
    Vec2 max;
};

struct Circle {
    float radius;
    Vec2 position;
};
