/* 
 * File:   SixDoFMotor.h
 * Author: seh
 *
 * Created on February 15, 2010, 9:41 PM
 */

#ifndef _SIXDOFMOTOR_H
#define	_SIXDOFMOTOR_H

#include "../physics/BulletDynamics/ConstraintSolver/btGeneric6DofConstraint.h"
#include "../neural/NOutput.h"

class SixDoFMotor : public NOutput {
    btGeneric6DofConstraint* constraint;

    float maxLength;

public:

    SixDoFMotor(Brain* b, btGeneric6DofConstraint* _constraint) : NOutput(b, 2), constraint(_constraint), maxLength(0.5) {

    }

    virtual void process(double dt) {
        double angle = outs[0]->getOutput();
        double length = (outs[1]->getOutput()+1.0)/2.0;

        double scale = 0.001;
        float xmax = fmin(maxLength, length * scale);
        float xmin = 0;

        //cout << xmin << " " << xmax << "\n";

        constraint->getTranslationalLimitMotor()->m_lowerLimit.setX(xmin);
        constraint->getTranslationalLimitMotor()->m_upperLimit.setX(xmax);

        constraint->getRotationalLimitMotor(0)->m_loLimit = angle * -(M_PI_4);
        constraint->getRotationalLimitMotor(0)->m_hiLimit = angle * (M_PI_4);
        constraint->getRotationalLimitMotor(0)->m_enableMotor = true;

        //
        //			btVector3 v(xmin, 0, 0);
        //			c->setLinearLowerLimit(v);
        //
        //			btVector3 w(xmax, 0, 0);
        //			c->setLinearUpperLimit(w);

        //			btScalar fCurAngle = hingeC->getHingeAngle();
        //
        //			btScalar fTargetAngle = (1.0 + getLegTargetAngle(i)) * 2.0; //0.5 * (1 + sin(2 * M_PI * fTargetPercent));
        //
        //			btScalar fTargetLimitAngle = hingeC->getLowerLimit() + fTargetAngle
        //					* (hingeC->getUpperLimit() - hingeC->getLowerLimit());
        //			btScalar fAngleError = fTargetLimitAngle - fCurAngle;
        //			btScalar fDesiredAngularVel = 1000000.f * fAngleError / dt
        //					* 1000000.;
        //			hingeC->enableAngularMotor(true, fDesiredAngularVel,
        //					m_fMuscleStrength);

    }

    virtual ~SixDoFMotor() {

    }
private:

};

#endif	/* _SIXDOFMOTOR_H */

