/*
 * BoxBody.h
 *
 *  Created on: Feb 13, 2010
 *      Author: seh
 */

#ifndef BOXBODY_H_
#define BOXBODY_H_

#include "DefaultSpace.h"
#include "AbstractBody.h"

class BoxBody : public AbstractBody {
public:

        const btVector3& position;
        const btVector3& size;

	BoxBody(const btVector3& _position, const btVector3& _size) : AbstractBody(), position(_position), size(_size) 	{

	}

        virtual void init() {
            btTransform transform;
            transform.setIdentity();
            transform.setOrigin(position);

            createRigidShape(btScalar(1.), transform, new btBoxShape(size));
        }

	virtual ~BoxBody();
};

#endif /* BOXBODY_H_ */
