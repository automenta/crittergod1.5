/* 
 * File:   RunSims.h
 * Author: seh
 *
 * Created on February 23, 2010, 3:57 PM
 */

#ifndef _RUNSIMS_H
#define	_RUNSIMS_H

#include <iostream>
#include <string.h>

using namespace std;

#include "video/GLWindow.h"

#include "neural/Brain.h"

#include "objects/BrainPanel.h"
#include "objects/NeuralSignalsPanel.h"
#include "objects/RetinaPanel.h"
#include "objects/FDBrainBody.h"

#include "space/DefaultSpace.h"
#include "physics/OpenGL/GlutStuff.h"

//#include "physics/optic/Raytracer.h"

#include "video/font/FontDemo1.h"

#include "space/AbstractBody.h"
#include "space/SpiderBody.h"
#include "space/SnakeBody.h"
#include "space/Humanoid.h"
#include "space/BoxBody.h"

#include "audio/Audio.h"

#include "widget2d/container.h"
#include "widget2d/panel.h"
#include "widget2d/button.h"
#include "widget2d/text.h"


#define VERSION "CritterGod 0.01"

void runSim();
void runBrainDemo();
void runCritterLab();
void runZoomDemo();
void runHumanoid();

#endif	/* _RUNSIMS_H */

