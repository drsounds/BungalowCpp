#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
using namespace std;
typedef int (*entify_promise_callback)(void *sender, void *data);
namespace Entify {
class Entity;
class Resolver;
class Promise;
/***
 * Entity
 * @class
 **/
class Entity
{
    private:
        vector<Resolver *> *resolvers;
    public:
            /**
             * Creates a new instance of Entity
             * @constructor
             **/
            Entity();

            /**
             * @function
             **/
            void request(char *method, char *uri, void *data);

            /***
             * @function
             * @param {Entify::Resolver *} resolver the resolver to register
             * @return {void}
             **/
            void registerResolver(Resolver *resolver);
            virtual ~Entity();
    protected:
};

class Resolver {
public:
    Resolver();

    /**
     * Does a request
     * @function
     * @param {char *} method The method
     * @param {char *} uri The uri
     * @param {char *} data The data
     **/
    virtual Promise request(char *method, char *uri, void *data);

    /***
     * Checks if the current entity URI is covered by this resolver
     * @virtual
     * @function
     * @return {bool}
     * @param {char *} uri the uri
     **/
    virtual bool acceptsUri(char *uri);
};

/***
 * The promise
 * @class
 **/
class Promise {
private:
    entify_promise_callback _done;
    entify_promise_callback _fail;
    entify_promise_callback _always;
public:
    Promise();
    ~Promise();
    void done(entify_promise_callback callback);
    void fail(entify_promise_callback callback);
    void always(entify_promise_callback callback);
    void setDone(void *data);
    void setFail(void *data);
};
}

#endif // ENTITY_H
