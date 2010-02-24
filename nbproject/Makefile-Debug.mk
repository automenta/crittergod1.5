#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btDispatcher.o \
	${OBJECTDIR}/space/DefaultSpace.o \
	${OBJECTDIR}/physics/BulletDynamics/Dynamics/Bullet-C-API.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConcaveShape.o \
	${OBJECTDIR}/physics/OpenGL/GL_DialogDynamicsWorld.o \
	${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btSliderConstraint.o \
	${OBJECTDIR}/math/vector2f.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btMinkowskiSumShape.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSphereBoxCollisionAlgorithm.o \
	${OBJECTDIR}/physics/OpenGL/Win32DemoApplication.o \
	${OBJECTDIR}/neural/BrainLink.o \
	${OBJECTDIR}/physics/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btBox2dShape.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleMesh.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/SphereTriangleDetector.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btSolve2LinearConstraint.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btGeneric6DofConstraint.o \
	${OBJECTDIR}/physics/BulletDynamics/Vehicle/btRaycastVehicle.o \
	${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleIndexVertexMaterialArray.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleBuffer.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btStridingMeshInterface.o \
	${OBJECTDIR}/space/Humanoid.o \
	${OBJECTDIR}/widget2d/panel.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletCollision/Gimpact/btGenericPoolAllocator.o \
	${OBJECTDIR}/math/vector2i.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btHeightfieldTerrainShape.o \
	${OBJECTDIR}/physics/OpenGL/GL_Simplex1to4.o \
	${OBJECTDIR}/physics/RunBox2D/Box2dDemo.o \
	${OBJECTDIR}/space/SnakeBody.o \
	${OBJECTDIR}/widget2d/container.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btEmptyShape.o \
	${OBJECTDIR}/math/Math.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btHingeConstraint.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btTypedConstraint.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCollisionDispatcher.o \
	${OBJECTDIR}/neural/Brain.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexShape.o \
	${OBJECTDIR}/widget3d/TextRect.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCollisionWorld.o \
	${OBJECTDIR}/physics/BulletSoftBody/btSoftRigidDynamicsWorld.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btBoxShape.o \
	${OBJECTDIR}/space/BoxBody.o \
	${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btAxisSweep3.o \
	${OBJECTDIR}/objects/BrainVis.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btOptimizedBvh.o \
	${OBJECTDIR}/physics/optic/Raytracer.o \
	${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactQuantizedBvh.o \
	${OBJECTDIR}/physics/BulletDynamics/Vehicle/btWheelInfo.o \
	${OBJECTDIR}/physics/OpenGL/SpaceProcess.o \
	${OBJECTDIR}/physics/BulletSoftBody/btSoftBody.o \
	${OBJECTDIR}/widget2d/widget.o \
	${OBJECTDIR}/objects/BrainPanel.o \
	${OBJECTDIR}/physics/OpenGL/GL_DialogWindow.o \
	${OBJECTDIR}/objects/NeuralSignalsPanel.o \
	${OBJECTDIR}/physics/BulletSoftBody/btSoftBodyRigidBodyCollisionConfiguration.o \
	${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.o \
	${OBJECTDIR}/physics/OpenGL/GlutStuff.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btManifoldResult.o \
	${OBJECTDIR}/physics/LinearMath/btAlignedAllocator.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btUnionFind.o \
	${OBJECTDIR}/bio/SineSound.o \
	${OBJECTDIR}/neural/Neuron.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btScaledBvhTriangleMeshShape.o \
	${OBJECTDIR}/neural/NOutput.o \
	${OBJECTDIR}/physics/RunBox2D/main.o \
	${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btSimpleBroadphase.o \
	${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_contact.o \
	${OBJECTDIR}/video/font/FontDemo1.o \
	${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btDbvt.o \
	${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btOverlappingPairCache.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btMultimaterialTriangleMeshShape.o \
	${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.o \
	${OBJECTDIR}/crittergod4.o \
	${OBJECTDIR}/objects/FDBrainBody.o \
	${OBJECTDIR}/physics/OpenGL/Win32AppMain.o \
	${OBJECTDIR}/widget3d/Button.o \
	${OBJECTDIR}/physics/BulletDynamics/Dynamics/btSimpleDynamicsWorld.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btPoint2PointConstraint.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.o \
	${OBJECTDIR}/widget2d/textprinter.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btSphereShape.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexHullShape.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btStaticPlaneShape.o \
	${OBJECTDIR}/physics/LinearMath/btGeometryUtil.o \
	${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_tri_collision.o \
	${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btDbvtBroadphase.o \
	${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btQuantizedBvh.o \
	${OBJECTDIR}/RunWidgets.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.o \
	${OBJECTDIR}/physics/OpenGL/AbstractSpace.o \
	${OBJECTDIR}/video/raycast.o \
	${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactShape.o \
	${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btBroadphaseProxy.o \
	${OBJECTDIR}/video/Spacetime.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btConeTwistConstraint.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btPolyhedralConvexShape.o \
	${OBJECTDIR}/physics/BulletCollision/Gimpact/btTriangleShapeEx.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btRaycastCallback.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCylinderShape.o \
	${OBJECTDIR}/widget2d/button.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btUniformScalingShape.o \
	${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btConvexCast.o \
	${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactBvh.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexInternalShape.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btGhostObject.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTetrahedronShape.o \
	${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConeShape.o \
	${OBJECTDIR}/space/SpiderBody.o \
	${OBJECTDIR}/physics/BulletDynamics/Dynamics/btContinuousDynamicsWorld.o \
	${OBJECTDIR}/video/displaylists.o \
	${OBJECTDIR}/math/vector3f.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvex2dConvex2dAlgorithm.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btUniversalConstraint.o \
	${OBJECTDIR}/physics/LinearMath/btQuickprof.o \
	${OBJECTDIR}/physics/OpenGL/GLDebugFont.o \
	${OBJECTDIR}/video/gldebugdrawer.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btHinge2Constraint.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCapsuleShape.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleMeshShape.o \
	${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCollisionShape.o \
	${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_box_set.o \
	${OBJECTDIR}/widget2d/slider.o \
	${OBJECTDIR}/physics/BulletSoftBody/btSoftBodyConcaveCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleCallback.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btBox2dBox2dCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexPointCloudShape.o \
	${OBJECTDIR}/physics/OpenGL/GL_ShapeDrawer.o \
	${OBJECTDIR}/bio/BloodBrainInterface.o \
	${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_memory.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexTriangleMeshShape.o \
	${OBJECTDIR}/physics/OpenGL/RenderTexture.o \
	${OBJECTDIR}/physics/BulletSoftBody/btSoftBodyHelpers.o \
	${OBJECTDIR}/bio/SixDoFMotor.o \
	${OBJECTDIR}/physics/BulletSoftBody/btSoftSoftCollisionAlgorithm.o \
	${OBJECTDIR}/audio/SoundSource.o \
	${OBJECTDIR}/physics/OpenGL/GLDebugDrawer.o \
	${OBJECTDIR}/physics/BulletDynamics/Dynamics/btRigidBody.o \
	${OBJECTDIR}/audio/Audio.o \
	${OBJECTDIR}/physics/BulletDynamics/Character/btKinematicCharacterController.o \
	${OBJECTDIR}/physics/BulletCollision/Gimpact/btContactProcessing.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCollisionObject.o \
	${OBJECTDIR}/graph/Graph.o \
	${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btMultiSapBroadphase.o \
	${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.o \
	${OBJECTDIR}/video/mousepicker.o \
	${OBJECTDIR}/physics/BulletSoftBody/btSoftRigidCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btGeneric6DofSpringConstraint.o \
	${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btPersistentManifold.o \
	${OBJECTDIR}/video/textprinter.o \
	${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btContactConstraint.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCompoundShape.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSimulationIslandManager.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvex2dShape.o \
	${OBJECTDIR}/RunSims.o \
	${OBJECTDIR}/physics/LinearMath/btConvexHull.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btBoxBoxDetector.o \
	${OBJECTDIR}/bio/Retina.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btMultiSphereShape.o \
	${OBJECTDIR}/widget2d/text.o \
	${OBJECTDIR}/RunTests.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btShapeHull.o \
	${OBJECTDIR}/bio/NColor.o \
	${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkEpa2.o \
	${OBJECTDIR}/bio/NPosition.o \
	${OBJECTDIR}/neural/NInput.o \
	${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.o \
	${OBJECTDIR}/video/GLWindow.o \
	${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.o \
	${OBJECTDIR}/objects/RetinaPanel.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-fopenmp
CXXFLAGS=-fopenmp

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lGL -lSDL -lftgl -lGLU -lglut -lopenal -lalut

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/crittergod4

dist/Debug/GNU-Linux-x86/crittergod4: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/crittergod4 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btDispatcher.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/BroadphaseCollision/btDispatcher.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btDispatcher.o physics/BulletCollision/BroadphaseCollision/btDispatcher.cpp

${OBJECTDIR}/space/DefaultSpace.o: nbproject/Makefile-${CND_CONF}.mk space/DefaultSpace.cpp 
	${MKDIR} -p ${OBJECTDIR}/space
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/space/DefaultSpace.o space/DefaultSpace.cpp

${OBJECTDIR}/physics/BulletDynamics/Dynamics/Bullet-C-API.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/Dynamics/Bullet-C-API.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/Dynamics
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/Dynamics/Bullet-C-API.o physics/BulletDynamics/Dynamics/Bullet-C-API.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConcaveShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btConcaveShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConcaveShape.o physics/BulletCollision/CollisionShapes/btConcaveShape.cpp

${OBJECTDIR}/physics/OpenGL/GL_DialogDynamicsWorld.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/GL_DialogDynamicsWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/GL_DialogDynamicsWorld.o physics/OpenGL/GL_DialogDynamicsWorld.cpp

${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.o physics/BulletCollision/NarrowPhaseCollision/btSubSimplexConvexCast.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btSliderConstraint.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btSliderConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btSliderConstraint.o physics/BulletDynamics/ConstraintSolver/btSliderConstraint.cpp

${OBJECTDIR}/math/vector2f.o: nbproject/Makefile-${CND_CONF}.mk math/vector2f.cpp 
	${MKDIR} -p ${OBJECTDIR}/math
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/math/vector2f.o math/vector2f.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btMinkowskiSumShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btMinkowskiSumShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btMinkowskiSumShape.o physics/BulletCollision/CollisionShapes/btMinkowskiSumShape.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSphereBoxCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btSphereBoxCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSphereBoxCollisionAlgorithm.o physics/BulletCollision/CollisionDispatch/btSphereBoxCollisionAlgorithm.cpp

${OBJECTDIR}/physics/OpenGL/Win32DemoApplication.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/Win32DemoApplication.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/Win32DemoApplication.o physics/OpenGL/Win32DemoApplication.cpp

${OBJECTDIR}/neural/BrainLink.o: nbproject/Makefile-${CND_CONF}.mk neural/BrainLink.cpp 
	${MKDIR} -p ${OBJECTDIR}/neural
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/neural/BrainLink.o neural/BrainLink.cpp

${OBJECTDIR}/physics/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/Dynamics
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.o physics/BulletDynamics/Dynamics/btDiscreteDynamicsWorld.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btBox2dShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btBox2dShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btBox2dShape.o physics/BulletCollision/CollisionShapes/btBox2dShape.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleMesh.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btTriangleMesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleMesh.o physics/BulletCollision/CollisionShapes/btTriangleMesh.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/SphereTriangleDetector.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/SphereTriangleDetector.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/SphereTriangleDetector.o physics/BulletCollision/CollisionDispatch/SphereTriangleDetector.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btSolve2LinearConstraint.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btSolve2LinearConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btSolve2LinearConstraint.o physics/BulletDynamics/ConstraintSolver/btSolve2LinearConstraint.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.o physics/BulletCollision/CollisionShapes/btBvhTriangleMeshShape.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btGeneric6DofConstraint.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btGeneric6DofConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btGeneric6DofConstraint.o physics/BulletDynamics/ConstraintSolver/btGeneric6DofConstraint.cpp

${OBJECTDIR}/physics/BulletDynamics/Vehicle/btRaycastVehicle.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/Vehicle/btRaycastVehicle.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/Vehicle
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/Vehicle/btRaycastVehicle.o physics/BulletDynamics/Vehicle/btRaycastVehicle.cpp

${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.o physics/BulletCollision/NarrowPhaseCollision/btGjkPairDetector.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleIndexVertexMaterialArray.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btTriangleIndexVertexMaterialArray.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleIndexVertexMaterialArray.o physics/BulletCollision/CollisionShapes/btTriangleIndexVertexMaterialArray.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleBuffer.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btTriangleBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleBuffer.o physics/BulletCollision/CollisionShapes/btTriangleBuffer.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btStridingMeshInterface.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btStridingMeshInterface.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btStridingMeshInterface.o physics/BulletCollision/CollisionShapes/btStridingMeshInterface.cpp

${OBJECTDIR}/space/Humanoid.o: nbproject/Makefile-${CND_CONF}.mk space/Humanoid.cpp 
	${MKDIR} -p ${OBJECTDIR}/space
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/space/Humanoid.o space/Humanoid.cpp

${OBJECTDIR}/widget2d/panel.o: nbproject/Makefile-${CND_CONF}.mk widget2d/panel.cpp 
	${MKDIR} -p ${OBJECTDIR}/widget2d
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/widget2d/panel.o widget2d/panel.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.o physics/BulletCollision/CollisionDispatch/btSphereTriangleCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletCollision/Gimpact/btGenericPoolAllocator.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/Gimpact/btGenericPoolAllocator.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/Gimpact
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/Gimpact/btGenericPoolAllocator.o physics/BulletCollision/Gimpact/btGenericPoolAllocator.cpp

${OBJECTDIR}/math/vector2i.o: nbproject/Makefile-${CND_CONF}.mk math/vector2i.cpp 
	${MKDIR} -p ${OBJECTDIR}/math
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/math/vector2i.o math/vector2i.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btHeightfieldTerrainShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btHeightfieldTerrainShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btHeightfieldTerrainShape.o physics/BulletCollision/CollisionShapes/btHeightfieldTerrainShape.cpp

${OBJECTDIR}/physics/OpenGL/GL_Simplex1to4.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/GL_Simplex1to4.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/GL_Simplex1to4.o physics/OpenGL/GL_Simplex1to4.cpp

${OBJECTDIR}/physics/RunBox2D/Box2dDemo.o: nbproject/Makefile-${CND_CONF}.mk physics/RunBox2D/Box2dDemo.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/RunBox2D
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/RunBox2D/Box2dDemo.o physics/RunBox2D/Box2dDemo.cpp

${OBJECTDIR}/space/SnakeBody.o: nbproject/Makefile-${CND_CONF}.mk space/SnakeBody.cpp 
	${MKDIR} -p ${OBJECTDIR}/space
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/space/SnakeBody.o space/SnakeBody.cpp

${OBJECTDIR}/widget2d/container.o: nbproject/Makefile-${CND_CONF}.mk widget2d/container.cpp 
	${MKDIR} -p ${OBJECTDIR}/widget2d
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/widget2d/container.o widget2d/container.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btEmptyShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btEmptyShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btEmptyShape.o physics/BulletCollision/CollisionShapes/btEmptyShape.cpp

${OBJECTDIR}/math/Math.o: nbproject/Makefile-${CND_CONF}.mk math/Math.cpp 
	${MKDIR} -p ${OBJECTDIR}/math
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/math/Math.o math/Math.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btHingeConstraint.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btHingeConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btHingeConstraint.o physics/BulletDynamics/ConstraintSolver/btHingeConstraint.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btTypedConstraint.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btTypedConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btTypedConstraint.o physics/BulletDynamics/ConstraintSolver/btTypedConstraint.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCollisionDispatcher.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btCollisionDispatcher.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCollisionDispatcher.o physics/BulletCollision/CollisionDispatch/btCollisionDispatcher.cpp

${OBJECTDIR}/neural/Brain.o: nbproject/Makefile-${CND_CONF}.mk neural/Brain.cpp 
	${MKDIR} -p ${OBJECTDIR}/neural
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/neural/Brain.o neural/Brain.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btConvexShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexShape.o physics/BulletCollision/CollisionShapes/btConvexShape.cpp

${OBJECTDIR}/widget3d/TextRect.o: nbproject/Makefile-${CND_CONF}.mk widget3d/TextRect.cpp 
	${MKDIR} -p ${OBJECTDIR}/widget3d
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/widget3d/TextRect.o widget3d/TextRect.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCollisionWorld.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btCollisionWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCollisionWorld.o physics/BulletCollision/CollisionDispatch/btCollisionWorld.cpp

${OBJECTDIR}/physics/BulletSoftBody/btSoftRigidDynamicsWorld.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletSoftBody/btSoftRigidDynamicsWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletSoftBody
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletSoftBody/btSoftRigidDynamicsWorld.o physics/BulletSoftBody/btSoftRigidDynamicsWorld.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btBoxShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btBoxShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btBoxShape.o physics/BulletCollision/CollisionShapes/btBoxShape.cpp

${OBJECTDIR}/space/BoxBody.o: nbproject/Makefile-${CND_CONF}.mk space/BoxBody.cpp 
	${MKDIR} -p ${OBJECTDIR}/space
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/space/BoxBody.o space/BoxBody.cpp

${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btAxisSweep3.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/BroadphaseCollision/btAxisSweep3.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btAxisSweep3.o physics/BulletCollision/BroadphaseCollision/btAxisSweep3.cpp

${OBJECTDIR}/objects/BrainVis.o: nbproject/Makefile-${CND_CONF}.mk objects/BrainVis.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/BrainVis.o objects/BrainVis.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btOptimizedBvh.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btOptimizedBvh.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btOptimizedBvh.o physics/BulletCollision/CollisionShapes/btOptimizedBvh.cpp

${OBJECTDIR}/physics/optic/Raytracer.o: nbproject/Makefile-${CND_CONF}.mk physics/optic/Raytracer.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/optic
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/optic/Raytracer.o physics/optic/Raytracer.cpp

${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactQuantizedBvh.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/Gimpact/btGImpactQuantizedBvh.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/Gimpact
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactQuantizedBvh.o physics/BulletCollision/Gimpact/btGImpactQuantizedBvh.cpp

${OBJECTDIR}/physics/BulletDynamics/Vehicle/btWheelInfo.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/Vehicle/btWheelInfo.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/Vehicle
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/Vehicle/btWheelInfo.o physics/BulletDynamics/Vehicle/btWheelInfo.cpp

${OBJECTDIR}/physics/OpenGL/SpaceProcess.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/SpaceProcess.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/SpaceProcess.o physics/OpenGL/SpaceProcess.cpp

${OBJECTDIR}/physics/BulletSoftBody/btSoftBody.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletSoftBody/btSoftBody.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletSoftBody
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletSoftBody/btSoftBody.o physics/BulletSoftBody/btSoftBody.cpp

${OBJECTDIR}/widget2d/widget.o: nbproject/Makefile-${CND_CONF}.mk widget2d/widget.cpp 
	${MKDIR} -p ${OBJECTDIR}/widget2d
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/widget2d/widget.o widget2d/widget.cpp

${OBJECTDIR}/objects/BrainPanel.o: nbproject/Makefile-${CND_CONF}.mk objects/BrainPanel.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/BrainPanel.o objects/BrainPanel.cpp

${OBJECTDIR}/physics/OpenGL/GL_DialogWindow.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/GL_DialogWindow.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/GL_DialogWindow.o physics/OpenGL/GL_DialogWindow.cpp

${OBJECTDIR}/objects/NeuralSignalsPanel.o: nbproject/Makefile-${CND_CONF}.mk objects/NeuralSignalsPanel.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/NeuralSignalsPanel.o objects/NeuralSignalsPanel.cpp

${OBJECTDIR}/physics/BulletSoftBody/btSoftBodyRigidBodyCollisionConfiguration.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletSoftBody/btSoftBodyRigidBodyCollisionConfiguration.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletSoftBody
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletSoftBody/btSoftBodyRigidBodyCollisionConfiguration.o physics/BulletSoftBody/btSoftBodyRigidBodyCollisionConfiguration.cpp

${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.o physics/BulletCollision/NarrowPhaseCollision/btGjkConvexCast.cpp

${OBJECTDIR}/physics/OpenGL/GlutStuff.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/GlutStuff.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/GlutStuff.o physics/OpenGL/GlutStuff.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.o physics/BulletCollision/CollisionDispatch/btSphereSphereCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/Gimpact
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.o physics/BulletCollision/Gimpact/btGImpactCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.o physics/BulletCollision/CollisionDispatch/btConvexConcaveCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btManifoldResult.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btManifoldResult.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btManifoldResult.o physics/BulletCollision/CollisionDispatch/btManifoldResult.cpp

${OBJECTDIR}/physics/LinearMath/btAlignedAllocator.o: nbproject/Makefile-${CND_CONF}.mk physics/LinearMath/btAlignedAllocator.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/LinearMath
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/LinearMath/btAlignedAllocator.o physics/LinearMath/btAlignedAllocator.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btUnionFind.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btUnionFind.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btUnionFind.o physics/BulletCollision/CollisionDispatch/btUnionFind.cpp

${OBJECTDIR}/bio/SineSound.o: nbproject/Makefile-${CND_CONF}.mk bio/SineSound.cpp 
	${MKDIR} -p ${OBJECTDIR}/bio
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/bio/SineSound.o bio/SineSound.cpp

${OBJECTDIR}/neural/Neuron.o: nbproject/Makefile-${CND_CONF}.mk neural/Neuron.cpp 
	${MKDIR} -p ${OBJECTDIR}/neural
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/neural/Neuron.o neural/Neuron.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btScaledBvhTriangleMeshShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btScaledBvhTriangleMeshShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btScaledBvhTriangleMeshShape.o physics/BulletCollision/CollisionShapes/btScaledBvhTriangleMeshShape.cpp

${OBJECTDIR}/neural/NOutput.o: nbproject/Makefile-${CND_CONF}.mk neural/NOutput.cpp 
	${MKDIR} -p ${OBJECTDIR}/neural
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/neural/NOutput.o neural/NOutput.cpp

${OBJECTDIR}/physics/RunBox2D/main.o: nbproject/Makefile-${CND_CONF}.mk physics/RunBox2D/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/RunBox2D
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/RunBox2D/main.o physics/RunBox2D/main.cpp

${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btSimpleBroadphase.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/BroadphaseCollision/btSimpleBroadphase.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btSimpleBroadphase.o physics/BulletCollision/BroadphaseCollision/btSimpleBroadphase.cpp

${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_contact.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/Gimpact/gim_contact.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/Gimpact
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_contact.o physics/BulletCollision/Gimpact/gim_contact.cpp

${OBJECTDIR}/video/font/FontDemo1.o: nbproject/Makefile-${CND_CONF}.mk video/font/FontDemo1.cpp 
	${MKDIR} -p ${OBJECTDIR}/video/font
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/video/font/FontDemo1.o video/font/FontDemo1.cpp

${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btDbvt.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/BroadphaseCollision/btDbvt.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btDbvt.o physics/BulletCollision/BroadphaseCollision/btDbvt.cpp

${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btOverlappingPairCache.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/BroadphaseCollision/btOverlappingPairCache.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btOverlappingPairCache.o physics/BulletCollision/BroadphaseCollision/btOverlappingPairCache.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.o physics/BulletDynamics/ConstraintSolver/btSequentialImpulseConstraintSolver.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btMultimaterialTriangleMeshShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btMultimaterialTriangleMeshShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btMultimaterialTriangleMeshShape.o physics/BulletCollision/CollisionShapes/btMultimaterialTriangleMeshShape.cpp

${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.o physics/BulletCollision/NarrowPhaseCollision/btMinkowskiPenetrationDepthSolver.cpp

${OBJECTDIR}/crittergod4.o: nbproject/Makefile-${CND_CONF}.mk crittergod4.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/crittergod4.o crittergod4.cpp

${OBJECTDIR}/objects/FDBrainBody.o: nbproject/Makefile-${CND_CONF}.mk objects/FDBrainBody.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/FDBrainBody.o objects/FDBrainBody.cpp

${OBJECTDIR}/physics/OpenGL/Win32AppMain.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/Win32AppMain.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/Win32AppMain.o physics/OpenGL/Win32AppMain.cpp

${OBJECTDIR}/widget3d/Button.o: nbproject/Makefile-${CND_CONF}.mk widget3d/Button.cpp 
	${MKDIR} -p ${OBJECTDIR}/widget3d
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/widget3d/Button.o widget3d/Button.cpp

${OBJECTDIR}/physics/BulletDynamics/Dynamics/btSimpleDynamicsWorld.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/Dynamics/btSimpleDynamicsWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/Dynamics
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/Dynamics/btSimpleDynamicsWorld.o physics/BulletDynamics/Dynamics/btSimpleDynamicsWorld.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btPoint2PointConstraint.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btPoint2PointConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btPoint2PointConstraint.o physics/BulletDynamics/ConstraintSolver/btPoint2PointConstraint.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.o physics/BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.cpp

${OBJECTDIR}/widget2d/textprinter.o: nbproject/Makefile-${CND_CONF}.mk widget2d/textprinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/widget2d
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/widget2d/textprinter.o widget2d/textprinter.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btSphereShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btSphereShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btSphereShape.o physics/BulletCollision/CollisionShapes/btSphereShape.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.o physics/BulletCollision/CollisionDispatch/btCompoundCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexHullShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btConvexHullShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexHullShape.o physics/BulletCollision/CollisionShapes/btConvexHullShape.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btStaticPlaneShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btStaticPlaneShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btStaticPlaneShape.o physics/BulletCollision/CollisionShapes/btStaticPlaneShape.cpp

${OBJECTDIR}/physics/LinearMath/btGeometryUtil.o: nbproject/Makefile-${CND_CONF}.mk physics/LinearMath/btGeometryUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/LinearMath
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/LinearMath/btGeometryUtil.o physics/LinearMath/btGeometryUtil.cpp

${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_tri_collision.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/Gimpact/gim_tri_collision.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/Gimpact
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_tri_collision.o physics/BulletCollision/Gimpact/gim_tri_collision.cpp

${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btDbvtBroadphase.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/BroadphaseCollision/btDbvtBroadphase.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btDbvtBroadphase.o physics/BulletCollision/BroadphaseCollision/btDbvtBroadphase.cpp

${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btQuantizedBvh.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/BroadphaseCollision/btQuantizedBvh.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btQuantizedBvh.o physics/BulletCollision/BroadphaseCollision/btQuantizedBvh.cpp

${OBJECTDIR}/RunWidgets.o: nbproject/Makefile-${CND_CONF}.mk RunWidgets.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/RunWidgets.o RunWidgets.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.o physics/BulletCollision/CollisionDispatch/btConvexConvexAlgorithm.cpp

${OBJECTDIR}/physics/OpenGL/AbstractSpace.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/AbstractSpace.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/AbstractSpace.o physics/OpenGL/AbstractSpace.cpp

${OBJECTDIR}/video/raycast.o: nbproject/Makefile-${CND_CONF}.mk video/raycast.cpp 
	${MKDIR} -p ${OBJECTDIR}/video
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/video/raycast.o video/raycast.cpp

${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/Gimpact/btGImpactShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/Gimpact
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactShape.o physics/BulletCollision/Gimpact/btGImpactShape.cpp

${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btBroadphaseProxy.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/BroadphaseCollision/btBroadphaseProxy.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btBroadphaseProxy.o physics/BulletCollision/BroadphaseCollision/btBroadphaseProxy.cpp

${OBJECTDIR}/video/Spacetime.o: nbproject/Makefile-${CND_CONF}.mk video/Spacetime.cpp 
	${MKDIR} -p ${OBJECTDIR}/video
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/video/Spacetime.o video/Spacetime.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btConeTwistConstraint.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btConeTwistConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btConeTwistConstraint.o physics/BulletDynamics/ConstraintSolver/btConeTwistConstraint.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btPolyhedralConvexShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btPolyhedralConvexShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btPolyhedralConvexShape.o physics/BulletCollision/CollisionShapes/btPolyhedralConvexShape.cpp

${OBJECTDIR}/physics/BulletCollision/Gimpact/btTriangleShapeEx.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/Gimpact/btTriangleShapeEx.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/Gimpact
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/Gimpact/btTriangleShapeEx.o physics/BulletCollision/Gimpact/btTriangleShapeEx.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.o physics/BulletCollision/CollisionDispatch/btBoxBoxCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btRaycastCallback.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/NarrowPhaseCollision/btRaycastCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btRaycastCallback.o physics/BulletCollision/NarrowPhaseCollision/btRaycastCallback.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCylinderShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btCylinderShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCylinderShape.o physics/BulletCollision/CollisionShapes/btCylinderShape.cpp

${OBJECTDIR}/widget2d/button.o: nbproject/Makefile-${CND_CONF}.mk widget2d/button.cpp 
	${MKDIR} -p ${OBJECTDIR}/widget2d
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/widget2d/button.o widget2d/button.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btUniformScalingShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btUniformScalingShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btUniformScalingShape.o physics/BulletCollision/CollisionShapes/btUniformScalingShape.cpp

${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btConvexCast.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/NarrowPhaseCollision/btConvexCast.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btConvexCast.o physics/BulletCollision/NarrowPhaseCollision/btConvexCast.cpp

${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactBvh.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/Gimpact/btGImpactBvh.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/Gimpact
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/Gimpact/btGImpactBvh.o physics/BulletCollision/Gimpact/btGImpactBvh.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.o physics/BulletCollision/CollisionDispatch/btEmptyCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexInternalShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btConvexInternalShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexInternalShape.o physics/BulletCollision/CollisionShapes/btConvexInternalShape.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btGhostObject.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btGhostObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btGhostObject.o physics/BulletCollision/CollisionDispatch/btGhostObject.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTetrahedronShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btTetrahedronShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTetrahedronShape.o physics/BulletCollision/CollisionShapes/btTetrahedronShape.cpp

${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.o physics/BulletCollision/NarrowPhaseCollision/btContinuousConvexCollision.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.o physics/BulletCollision/CollisionShapes/btTriangleIndexVertexArray.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConeShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btConeShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConeShape.o physics/BulletCollision/CollisionShapes/btConeShape.cpp

${OBJECTDIR}/space/SpiderBody.o: nbproject/Makefile-${CND_CONF}.mk space/SpiderBody.cpp 
	${MKDIR} -p ${OBJECTDIR}/space
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/space/SpiderBody.o space/SpiderBody.cpp

${OBJECTDIR}/physics/BulletDynamics/Dynamics/btContinuousDynamicsWorld.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/Dynamics/btContinuousDynamicsWorld.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/Dynamics
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/Dynamics/btContinuousDynamicsWorld.o physics/BulletDynamics/Dynamics/btContinuousDynamicsWorld.cpp

${OBJECTDIR}/video/displaylists.o: nbproject/Makefile-${CND_CONF}.mk video/displaylists.cpp 
	${MKDIR} -p ${OBJECTDIR}/video
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/video/displaylists.o video/displaylists.cpp

${OBJECTDIR}/math/vector3f.o: nbproject/Makefile-${CND_CONF}.mk math/vector3f.cpp 
	${MKDIR} -p ${OBJECTDIR}/math
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/math/vector3f.o math/vector3f.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvex2dConvex2dAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btConvex2dConvex2dAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvex2dConvex2dAlgorithm.o physics/BulletCollision/CollisionDispatch/btConvex2dConvex2dAlgorithm.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btUniversalConstraint.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btUniversalConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btUniversalConstraint.o physics/BulletDynamics/ConstraintSolver/btUniversalConstraint.cpp

${OBJECTDIR}/physics/LinearMath/btQuickprof.o: nbproject/Makefile-${CND_CONF}.mk physics/LinearMath/btQuickprof.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/LinearMath
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/LinearMath/btQuickprof.o physics/LinearMath/btQuickprof.cpp

${OBJECTDIR}/physics/OpenGL/GLDebugFont.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/GLDebugFont.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/GLDebugFont.o physics/OpenGL/GLDebugFont.cpp

${OBJECTDIR}/video/gldebugdrawer.o: nbproject/Makefile-${CND_CONF}.mk video/gldebugdrawer.cpp 
	${MKDIR} -p ${OBJECTDIR}/video
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/video/gldebugdrawer.o video/gldebugdrawer.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btHinge2Constraint.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btHinge2Constraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btHinge2Constraint.o physics/BulletDynamics/ConstraintSolver/btHinge2Constraint.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCapsuleShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btCapsuleShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCapsuleShape.o physics/BulletCollision/CollisionShapes/btCapsuleShape.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleMeshShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btTriangleMeshShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleMeshShape.o physics/BulletCollision/CollisionShapes/btTriangleMeshShape.cpp

${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.o physics/BulletCollision/BroadphaseCollision/btCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCollisionShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btCollisionShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCollisionShape.o physics/BulletCollision/CollisionShapes/btCollisionShape.cpp

${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_box_set.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/Gimpact/gim_box_set.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/Gimpact
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_box_set.o physics/BulletCollision/Gimpact/gim_box_set.cpp

${OBJECTDIR}/widget2d/slider.o: nbproject/Makefile-${CND_CONF}.mk widget2d/slider.cpp 
	${MKDIR} -p ${OBJECTDIR}/widget2d
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/widget2d/slider.o widget2d/slider.cpp

${OBJECTDIR}/physics/BulletSoftBody/btSoftBodyConcaveCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletSoftBody/btSoftBodyConcaveCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletSoftBody
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletSoftBody/btSoftBodyConcaveCollisionAlgorithm.o physics/BulletSoftBody/btSoftBodyConcaveCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleCallback.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btTriangleCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btTriangleCallback.o physics/BulletCollision/CollisionShapes/btTriangleCallback.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btBox2dBox2dCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btBox2dBox2dCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btBox2dBox2dCollisionAlgorithm.o physics/BulletCollision/CollisionDispatch/btBox2dBox2dCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexPointCloudShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btConvexPointCloudShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexPointCloudShape.o physics/BulletCollision/CollisionShapes/btConvexPointCloudShape.cpp

${OBJECTDIR}/physics/OpenGL/GL_ShapeDrawer.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/GL_ShapeDrawer.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/GL_ShapeDrawer.o physics/OpenGL/GL_ShapeDrawer.cpp

${OBJECTDIR}/bio/BloodBrainInterface.o: nbproject/Makefile-${CND_CONF}.mk bio/BloodBrainInterface.cpp 
	${MKDIR} -p ${OBJECTDIR}/bio
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/bio/BloodBrainInterface.o bio/BloodBrainInterface.cpp

${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_memory.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/Gimpact/gim_memory.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/Gimpact
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/Gimpact/gim_memory.o physics/BulletCollision/Gimpact/gim_memory.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexTriangleMeshShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btConvexTriangleMeshShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvexTriangleMeshShape.o physics/BulletCollision/CollisionShapes/btConvexTriangleMeshShape.cpp

${OBJECTDIR}/physics/OpenGL/RenderTexture.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/RenderTexture.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/RenderTexture.o physics/OpenGL/RenderTexture.cpp

${OBJECTDIR}/physics/BulletSoftBody/btSoftBodyHelpers.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletSoftBody/btSoftBodyHelpers.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletSoftBody
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletSoftBody/btSoftBodyHelpers.o physics/BulletSoftBody/btSoftBodyHelpers.cpp

${OBJECTDIR}/bio/SixDoFMotor.o: nbproject/Makefile-${CND_CONF}.mk bio/SixDoFMotor.cpp 
	${MKDIR} -p ${OBJECTDIR}/bio
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/bio/SixDoFMotor.o bio/SixDoFMotor.cpp

${OBJECTDIR}/physics/BulletSoftBody/btSoftSoftCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletSoftBody/btSoftSoftCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletSoftBody
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletSoftBody/btSoftSoftCollisionAlgorithm.o physics/BulletSoftBody/btSoftSoftCollisionAlgorithm.cpp

${OBJECTDIR}/audio/SoundSource.o: nbproject/Makefile-${CND_CONF}.mk audio/SoundSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/audio
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/audio/SoundSource.o audio/SoundSource.cpp

${OBJECTDIR}/physics/OpenGL/GLDebugDrawer.o: nbproject/Makefile-${CND_CONF}.mk physics/OpenGL/GLDebugDrawer.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/OpenGL
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/OpenGL/GLDebugDrawer.o physics/OpenGL/GLDebugDrawer.cpp

${OBJECTDIR}/physics/BulletDynamics/Dynamics/btRigidBody.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/Dynamics/btRigidBody.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/Dynamics
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/Dynamics/btRigidBody.o physics/BulletDynamics/Dynamics/btRigidBody.cpp

${OBJECTDIR}/audio/Audio.o: nbproject/Makefile-${CND_CONF}.mk audio/Audio.cpp 
	${MKDIR} -p ${OBJECTDIR}/audio
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/audio/Audio.o audio/Audio.cpp

${OBJECTDIR}/physics/BulletDynamics/Character/btKinematicCharacterController.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/Character/btKinematicCharacterController.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/Character
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/Character/btKinematicCharacterController.o physics/BulletDynamics/Character/btKinematicCharacterController.cpp

${OBJECTDIR}/physics/BulletCollision/Gimpact/btContactProcessing.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/Gimpact/btContactProcessing.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/Gimpact
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/Gimpact/btContactProcessing.o physics/BulletCollision/Gimpact/btContactProcessing.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCollisionObject.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btCollisionObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btCollisionObject.o physics/BulletCollision/CollisionDispatch/btCollisionObject.cpp

${OBJECTDIR}/graph/Graph.o: nbproject/Makefile-${CND_CONF}.mk graph/Graph.cpp 
	${MKDIR} -p ${OBJECTDIR}/graph
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/graph/Graph.o graph/Graph.cpp

${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btMultiSapBroadphase.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/BroadphaseCollision/btMultiSapBroadphase.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/BroadphaseCollision/btMultiSapBroadphase.o physics/BulletCollision/BroadphaseCollision/btMultiSapBroadphase.cpp

${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.o physics/BulletCollision/NarrowPhaseCollision/btVoronoiSimplexSolver.cpp

${OBJECTDIR}/video/mousepicker.o: nbproject/Makefile-${CND_CONF}.mk video/mousepicker.cpp 
	${MKDIR} -p ${OBJECTDIR}/video
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/video/mousepicker.o video/mousepicker.cpp

${OBJECTDIR}/physics/BulletSoftBody/btSoftRigidCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletSoftBody/btSoftRigidCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletSoftBody
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletSoftBody/btSoftRigidCollisionAlgorithm.o physics/BulletSoftBody/btSoftRigidCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btGeneric6DofSpringConstraint.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btGeneric6DofSpringConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btGeneric6DofSpringConstraint.o physics/BulletDynamics/ConstraintSolver/btGeneric6DofSpringConstraint.cpp

${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btPersistentManifold.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/NarrowPhaseCollision/btPersistentManifold.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btPersistentManifold.o physics/BulletCollision/NarrowPhaseCollision/btPersistentManifold.cpp

${OBJECTDIR}/video/textprinter.o: nbproject/Makefile-${CND_CONF}.mk video/textprinter.cpp 
	${MKDIR} -p ${OBJECTDIR}/video
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/video/textprinter.o video/textprinter.cpp

${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btContactConstraint.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletDynamics/ConstraintSolver/btContactConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletDynamics/ConstraintSolver/btContactConstraint.o physics/BulletDynamics/ConstraintSolver/btContactConstraint.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCompoundShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btCompoundShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btCompoundShape.o physics/BulletCollision/CollisionShapes/btCompoundShape.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSimulationIslandManager.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btSimulationIslandManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btSimulationIslandManager.o physics/BulletCollision/CollisionDispatch/btSimulationIslandManager.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.o physics/BulletCollision/CollisionDispatch/btConvexPlaneCollisionAlgorithm.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvex2dShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btConvex2dShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btConvex2dShape.o physics/BulletCollision/CollisionShapes/btConvex2dShape.cpp

${OBJECTDIR}/RunSims.o: nbproject/Makefile-${CND_CONF}.mk RunSims.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/RunSims.o RunSims.cpp

${OBJECTDIR}/physics/LinearMath/btConvexHull.o: nbproject/Makefile-${CND_CONF}.mk physics/LinearMath/btConvexHull.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/LinearMath
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/LinearMath/btConvexHull.o physics/LinearMath/btConvexHull.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btBoxBoxDetector.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btBoxBoxDetector.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btBoxBoxDetector.o physics/BulletCollision/CollisionDispatch/btBoxBoxDetector.cpp

${OBJECTDIR}/bio/Retina.o: nbproject/Makefile-${CND_CONF}.mk bio/Retina.cpp 
	${MKDIR} -p ${OBJECTDIR}/bio
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/bio/Retina.o bio/Retina.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btMultiSphereShape.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btMultiSphereShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btMultiSphereShape.o physics/BulletCollision/CollisionShapes/btMultiSphereShape.cpp

${OBJECTDIR}/widget2d/text.o: nbproject/Makefile-${CND_CONF}.mk widget2d/text.cpp 
	${MKDIR} -p ${OBJECTDIR}/widget2d
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/widget2d/text.o widget2d/text.cpp

${OBJECTDIR}/RunTests.o: nbproject/Makefile-${CND_CONF}.mk RunTests.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/RunTests.o RunTests.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btShapeHull.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionShapes/btShapeHull.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionShapes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionShapes/btShapeHull.o physics/BulletCollision/CollisionShapes/btShapeHull.cpp

${OBJECTDIR}/bio/NColor.o: nbproject/Makefile-${CND_CONF}.mk bio/NColor.cpp 
	${MKDIR} -p ${OBJECTDIR}/bio
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/bio/NColor.o bio/NColor.cpp

${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkEpa2.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/NarrowPhaseCollision/btGjkEpa2.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkEpa2.o physics/BulletCollision/NarrowPhaseCollision/btGjkEpa2.cpp

${OBJECTDIR}/bio/NPosition.o: nbproject/Makefile-${CND_CONF}.mk bio/NPosition.cpp 
	${MKDIR} -p ${OBJECTDIR}/bio
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/bio/NPosition.o bio/NPosition.cpp

${OBJECTDIR}/neural/NInput.o: nbproject/Makefile-${CND_CONF}.mk neural/NInput.cpp 
	${MKDIR} -p ${OBJECTDIR}/neural
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/neural/NInput.o neural/NInput.cpp

${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.o physics/BulletCollision/NarrowPhaseCollision/btGjkEpaPenetrationDepthSolver.cpp

${OBJECTDIR}/video/GLWindow.o: nbproject/Makefile-${CND_CONF}.mk video/GLWindow.cpp 
	${MKDIR} -p ${OBJECTDIR}/video
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/video/GLWindow.o video/GLWindow.cpp

${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.o: nbproject/Makefile-${CND_CONF}.mk physics/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.cpp 
	${MKDIR} -p ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/physics/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.o physics/BulletCollision/CollisionDispatch/btActivatingCollisionAlgorithm.cpp

${OBJECTDIR}/objects/RetinaPanel.o: nbproject/Makefile-${CND_CONF}.mk objects/RetinaPanel.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/RetinaPanel.o objects/RetinaPanel.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/crittergod4

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
