#include "Entity.h"

Entify::Entity::Entity()
{
    this->resolvers = new vector<Resolver *>();
}
void Entify::Entity::registerResolver(Resolver *resolver) {
    this->resolvers->push_back(resolver);
}

Entify::Entity::~Entity()
{
    delete this->resolvers;
}

Entify::Promise::Promise() {
}
Entify::Promise::~Promise() {

}
void Entify::Promise::done(entify_promise_callback callback) {
    this->_done = callback;
}
void Entify::Promise::fail(entify_promise_callback callback) {
    this->_fail = callback;
}

void Entify::Promise::always(entify_promise_callback callback) {
    this->_always = callback;
}

void Entify::Promise::setDone(void *data) {
    this->_done(this, data);
    this->_always(this, data);
}
void Entify::Promise::setFail(void *data) {
    this->_fail(this, data);
    this->_always(this, data);
}

