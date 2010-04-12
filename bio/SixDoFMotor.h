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

    float normalLength;
    float linearScale, angularScale;
    float linearStimulation, angularStimulation;

    float lastAngle, lastLength;
public:
    SixDoFMotor(Brain* b, btGeneric6DofConstraint* _constraint, float _linearScale, float _angularScale, float _linearStimulation, float _angularStimulation) :
        NOutput(b, 2), constraint(_constraint), normalLength(0), linearScale(_linearScale), angularScale(_angularScale),
        linearStimulation(_linearStimulation), angularStimulation(_angularStimulation) {

            lastAngle = lastLength = 0;

    }

    virtual void process(double dt) {
        outs[0]->setStimulationFactor(angularStimulation);
        //outs[0]->setDecay(0.9999);
        outs[1]->setStimulationFactor(linearStimulation);
        //outs[1]->setDecay(0.9999);

        float smoothing = 0.001;

        double a = outs[0]->getOutput();
        double l = outs[1]->getOutput();
        
        double angle = smoothing * a + (1.0 - smoothing) * lastAngle;
        double lengthMod = smoothing * l + (1.0 - smoothing) * lastLength;

        lastAngle = angle;
        lastLength = lengthMod;

        //TODO expose this parameter
        double lengthVariation = 0.001;

        float xmax = normalLength + (lengthMod)*lengthVariation;
        float xmin = 0;

        //cout << xmin << " " << xmax << "\n";


        constraint->getTranslationalLimitMotor()->m_currentLimit[0] = xmax;
        constraint->getTranslationalLimitMotor()->m_lowerLimit.setX(xmax);
        constraint->getTranslationalLimitMotor()->m_upperLimit.setX(xmax);
        constraint->getTranslationalLimitMotor()->m_enableMotor[0] = true;

        float currentAngle =  angle * angularScale;
        constraint->getRotationalLimitMotor(0)->m_currentPosition = currentAngle;
        constraint->getRotationalLimitMotor(0)->m_loLimit = currentAngle; //angle * -angularScale/2.0;
        constraint->getRotationalLimitMotor(0)->m_hiLimit = currentAngle; //angle * angularScale/2.0;
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

