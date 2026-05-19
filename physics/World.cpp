#include "World.h"

void World::AddObject(Object *object){
    m_objects.push_back(object);
}

void World::RemoveObject(Object *object) {
    auto it = std::find(m_objects.begin(), m_objects.end(), object);
    if (it == m_objects.end()) return;
    m_objects.erase(it);
    delete object;
}

void World::Step(float dt) {
    for(Object *obj: m_objects) {
        obj->force += gravity * obj->mass;

        obj->velocity += (obj->force / obj->mass) * dt;
        obj->position += (obj->velocity * dt) * -1;
        obj->force = Vec2{0, 0};
    }
}