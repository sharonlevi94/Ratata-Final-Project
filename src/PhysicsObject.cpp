#include "PhysicsObject.h"
#include "Macros.h"
//===========================================================================
PhysicsObject::PhysicsObject(b2World& world, const sf::Vector2f& position, const bool dynamic,
                             const sf::Vector2f &size)
{
    /*auto objPhysicsInfo = physicsInfo[int(type)];*/
    b2BodyDef bodyDef;
    b2PolygonShape polygonShape;
    //b2CircleShape circleShape;  // if want to add circleshape later

    if (dynamic)
        bodyDef.type = b2_dynamicBody;
    else
        bodyDef.type = b2_staticBody;

    bodyDef.position.Set(position.x * MPP, position.y * MPP);

    m_body = world.CreateBody(&bodyDef);

    polygonShape.SetAsBox(size.x / 4 * MPP, size.y / 2 * MPP);
    m_fixtureDef.shape = &polygonShape;
    m_fixtureDef.friction = 1; // objPhysicsInfo._friction;
    m_fixtureDef.restitution = 0; // objPhysicsInfo._restitution;
    m_fixtureDef.density = 1; // objPhysicsInfo._density;
    m_fixture = m_body->CreateFixture(&m_fixtureDef);  // to update all parameters defined above in Physicsobj.
    m_body->SetFixedRotation(true);  /// this object will not rotate.
}
//===========================================================================
PhysicsObject::~PhysicsObject()
{
    m_body->GetWorld()->DestroyBody(m_body);
}
//===========================================================================
void PhysicsObject::setID(const int ID)
{
    m_body->SetUserData((void*)ID);
}
//===========================================================================
void PhysicsObject::setPosition(const sf::Vector2f pos, const b2Vec2 velocity)
{
    //m_body->ApplyForceToCenter(velocity, true);
    m_body->SetTransform(b2Vec2(pos.x * MPP, pos.y * MPP), 0);
    m_body->SetLinearVelocity(velocity);
}
//===========================================================================
b2Body* PhysicsObject::getBody()const { return m_body; }
//===========================================================================
//void PhysicsObj::setGravityScale(const float scale)
//{
//    m_body->SetGravityScale(scale);
//}
//===========================================================================
//void PhysicsObj::setSize(const sf::Vector2f size)
//{
//
//    auto objPhysicsInfo = physicsInfo[int(m_type)];
//    m_body->DestroyFixture(m_fixture);
//    b2PolygonShape polygonShape;
//    b2CircleShape circleShape;
//
//    if (objPhysicsInfo._shape == RECT)
//    {
//        polygonShape.SetAsBox(size.x / 2 * MPP, size.y / 2 * MPP);
//        m_fixtureDef.shape = &polygonShape;
//    }
//    else if (objPhysicsInfo._shape == CIRCLE)
//    {
//        circleShape.m_radius = size.x / 2 * MPP;
//        m_fixtureDef.shape = &circleShape;
//    }
//
//    m_fixtureDef.friction = objPhysicsInfo._friction;
//    m_fixtureDef.restitution = objPhysicsInfo._restitution;
//    m_fixtureDef.density = objPhysicsInfo._density;
//    m_fixture = m_body->CreateFixture(&m_fixtureDef);
//
//}
//===========================================================================
//void PhysicsObj::setAngle(const int whichAngle)
//{
//    m_body->SetTransform(m_body->GetPosition(), whichAngle * 45 * DEG_TO_RAD);
//}
//
//===========================================================================
void PhysicsObject::applyForce(const b2Vec2& force)
{
    m_body->ApplyLinearImpulse(force, m_body->GetWorldCenter(), true);
}

b2Vec2 PhysicsObject::getLinearVelocity() {
    return m_body->GetLinearVelocity();
}
//void PhysicsObject::setBodyType(const b2BodyType& type) {
//    m_body->SetType(type);
//}