/*
 * BoxBody.h
 *
 *  Created on: Feb 13, 2010
 *      Author: seh
 */

#ifndef ABSTRACTBODY_H_
#define ABSTRACTBODY_H_

using namespace std;
#include <vector>

#include "../physics/btBulletDynamicsCommon.h"
#include "../space/DefaultSpace.h"

#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif

#ifndef M_PI_2
#define M_PI_2     1.57079632679489661923
#endif

#ifndef M_PI_4
#define M_PI_4     0.785398163397448309616
#endif

#ifndef M_PI_8
#define M_PI_8     0.5 * M_PI_4
#endif

class AbstractBody {
public:
    btDynamicsWorld* dyn;

    vector<btCollisionShape*> shapes;
    vector<btRigidBody*> bodies;
    vector<btTypedConstraint*> joints;

    AbstractSpace* space;

    AbstractBody() {

    }

    virtual void init(AbstractSpace* ds) {
        space = ds;
        dyn = ds->dynamicsWorld;
        init();
    }

    virtual void init() {
    }

    virtual ~AbstractBody() {

    }

    virtual void process(float deltaTime) {
    }

    int indexOfPart(btRigidBody* part) {
        for (unsigned i = 0; i < bodies.size(); i++) {
            if (bodies[i] == part)
                return i;
        }
        return -1;
    }

    int indexOfShape(btCollisionShape* shape) {
        for (unsigned i = 0; i < shapes.size(); i++) {
            if (shapes[i] == shape)
                return i;
        }
        return -1;
    }

    virtual btVector3 getColor(btCollisionShape* shape) {
        return btVector3(0.5, 0.5, 0.5);
    }

    btRigidBody* localCreateRigidBody(btScalar mass, const btTransform& startTransform, btCollisionShape* shape) {
        bool isDynamic = (mass != 0.f);

        btVector3 localInertia(0, 0, 0);
        if (isDynamic)
            shape->calculateLocalInertia(mass, localInertia);

        btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
        btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, shape, localInertia);
        btRigidBody* body = new btRigidBody(rbInfo);

        dyn->addRigidBody(body);

        return body;
    }

};

#endif
