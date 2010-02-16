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

	BoxBody(const btVector3& position, const btVector3& size) 	{

	}

	virtual ~BoxBody();
};

#endif /* BOXBODY_H_ */
