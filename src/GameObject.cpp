//============================= include section ==============================
#include "GameObject.h"
#include "Resources.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
GameObject::GameObject(const bool isDynamic, b2World& world ,const sf::Vector2f& location,
                       const sf::Vector2f& size, char objectType, bool isAnimated, int ID)
        : m_intRect(0, 0, 600, 600),
          m_objectSprite(Resources::instance().getTexture(objectType),m_intRect),
          m_isAnimated(isAnimated), 
		  m_physicsObject(world, location, isDynamic, size),
		  m_ID(ID)
{
    this->m_objectSprite.setPosition(location);

    if (!isAnimated) {
        m_intRect.width = m_objectSprite.getTexture()->getSize().x;
        m_intRect.height = m_objectSprite.getTexture()->getSize().y;

    }
    m_objectSprite.setScale(1, 1);
    m_objectSprite.setTextureRect(m_intRect);
    setSize(sf::Vector2u(size));
    updateLoc();
    m_physicsObject.setID(m_ID);
	setOrigin();
}
//============================================================================
GameObject::~GameObject() = default;
//============================== gets section ================================
const sf::Vector2f& GameObject::getLocation()const {
	return m_objectSprite.getPosition();
}
//============================================================================
sf::Vector2f GameObject::getSize()const {
	return sf::Vector2f(this->getSprite().getGlobalBounds().width,
		getSprite().getGlobalBounds().height);
}
//============================================================================
const sf::Sprite& GameObject::getSprite() const {
	return m_objectSprite;
}
//============================================================================
sf::Sprite* GameObject::getSpritePtr() {
	return &m_objectSprite;
}
//============================================================================
void GameObject::updateLoc()
{
	auto pos = m_physicsObject.getPosition();
	setLocation(sf::Vector2f(pos.x * PPM, pos.y *PPM));
}
//============================ methods section ===============================
void GameObject::draw(sf::RenderWindow& window) {
	m_objectSprite.setTextureRect(m_intRect);
    window.draw(m_objectSprite);
}
//============================================================================
const sf::IntRect& GameObject::getIntRect()const { return m_intRect; }
//============================================================================
PhysicsObject GameObject::getPhysicsObj() const
{
	return m_physicsObject;
}
//============================================================================
void GameObject::setPhysicsObjectPos(sf::Vector2f newPos, b2Vec2 velocity)
{
	m_physicsObject.setPosition(newPos, velocity);
	updateLoc();
}
//============================================================================
void GameObject::setIntRect(const sf::IntRect& rect){
	m_intRect = rect;
}
//============================================================================
/*This method change the direction of the sprite.*/
void GameObject::flipSprite(const sf::Vector2f& scale) {
	m_objectSprite.scale(scale);
}
//=========================== protected section ==============================
//============================== sets section ================================
/*this method get the direction movement and set it to the sprite of the
object.*/
void GameObject::setLocation(const sf::Vector2f& movment) {
	m_objectSprite.setPosition(movment);
}
//============================================================================
void GameObject::setSize(const sf::Vector2u size)
{
	m_objectSprite.scale((size.x / m_objectSprite.getGlobalBounds().width),
		(size.y / m_objectSprite.getGlobalBounds().height));
}
//============================================================================
void GameObject::setOrigin()
{
	m_objectSprite.setOrigin(sf::Vector2f(float(m_intRect.width)/2, float(m_intRect.height)/2 -50));
}
void GameObject::reset()
{
}
//============================================================================

//============================================================================
void GameObject::applyForce(b2Vec2 force) {
    m_physicsObject.applyForce(force);
}
//============================================================================
b2Vec2 GameObject::getLinearVelocity() {
    return m_physicsObject.getLinearVelocity();
}
//============================================================================
//============================================================================
sf::FloatRect GameObject::getGlobalBounds() const
{
	return getSprite().getGlobalBounds();
}

GameObject::GameObject() {}
