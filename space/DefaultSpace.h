/*
Bullet Continuous Collision Detection and Physics Library Copyright (c) 2007 Erwin Coumans
Motor Demo

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
 */


#ifndef MOTORDEMO_H
#define MOTORDEMO_H

#include "../audio/Audio.h"

#include "../physics/OpenGL/AbstractSpace.h"
#include "../physics/LinearMath/btAlignedObjectArray.h"

#include "../physics/OpenGL/GL_DialogDynamicsWorld.h"
#include "../physics/OpenGL/GL_DialogWindow.h"
#include "../physics/OpenGL/GlutStuff.h"
#include "../physics/btBulletDynamicsCommon.h"

#include "AbstractBody.h"

#include "../widget2d/container.h"

class btBroadphaseInterface;
class btCollisionShape;
class btOverlappingPairCache;
class btCollisionDispatcher;
class btConstraintSolver;
struct btCollisionAlgorithmCreateFunc;
class btDefaultCollisionConfiguration;

class DefaultSpace : public AbstractSpace {
    float m_Time;

    btAlignedObjectArray<class AbstractBody*> bodies;

    //keep the collision shapes, for deletion/cleanup
    btAlignedObjectArray<btCollisionShape*> m_collisionShapes;

    btBroadphaseInterface* m_broadphase;

    btCollisionDispatcher* m_dispatcher;

    btConstraintSolver* m_solver;

    btDefaultCollisionConfiguration* m_collisionConfiguration;

    Container faceContainer;
    
    void initPhysics();

public:

    DefaultSpace(Audio* _audio) {
        this->audio = _audio;
        initPhysics();
    }

    void exitPhysics();

    virtual ~DefaultSpace() {
        exitPhysics();
    }

    virtual void addBody(AbstractBody* a);
    virtual void removeBody(AbstractBody* a);
    virtual void addGround(double x, double y, double z);

    virtual void clientMoveAndDisplay();

    virtual void draw();

    void process(btScalar deltaTime);
    
    virtual void reshape(int w, int h);

    virtual void onKeyboard(unsigned char key, int x, int y);
    virtual void onMouseButton(int button, int state, int x, int y);
    virtual void onMouseMove(int x, int y);

    virtual void renderscene(int pass);

    virtual Container* getFace();

};


#endif
