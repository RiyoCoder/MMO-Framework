/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PhysicEngine_Bullet.h"
#include <boost/foreach.hpp>


TPhysicEngine_Bullet::TPhysicEngine_Bullet()
{
  mLastID = 0;
}
//----------------------------------------------------------------------------------------------
TPhysicEngine_Bullet::~TPhysicEngine_Bullet()
{

}
//----------------------------------------------------------------------------------------------
void TPhysicEngine_Bullet::Work()
{
  // ������ ������ ������� ��������������
  //BOOST_FOREACH(TMapIntWorldVT& ID_World, mMapIDWorld)
    //ID_World.second.pWorld->stepSimulation(timeStep, maxSubSteps, fixedTimeStep);
}
//----------------------------------------------------------------------------------------------
void TPhysicEngine_Bullet::Work(btScalar timeStep, int maxSubSteps, btScalar fixedTimeStep)
{
  BOOST_FOREACH(TMapIntWorldVT& ID_World, mMapIDWorld)
    ID_World.second.pWorld->stepSimulation(timeStep, maxSubSteps, fixedTimeStep);
}
//----------------------------------------------------------------------------------------------
int TPhysicEngine_Bullet::AddWorld()
{
  mLastID++;
  TWorld world;

  world.pBroadphase = new btDbvtBroadphase;
  world.pCollisionConfiguration = new btDefaultCollisionConfiguration;
  world.pDispatcher = new btCollisionDispatcher(world.pCollisionConfiguration);
  world.pSolver = new btSequentialImpulseConstraintSolver;
  world.pWorld = new btDiscreteDynamicsWorld(world.pDispatcher, world.pBroadphase, world.pSolver, world.pCollisionConfiguration);

  mMapIDWorld.insert(TMapIntWorldVT(mLastID, world));
  return mLastID;
}
//----------------------------------------------------------------------------------------------
void TPhysicEngine_Bullet::DeleteWorld(int id_world)
{
  TWorld world;
  if(GetByID(id_world, world))
    world.Done();

  mMapIDWorld.erase(id_world);
}
//----------------------------------------------------------------------------------------------
btDiscreteDynamicsWorld* TPhysicEngine_Bullet::GetWorld(int id_world)
{
  TWorld world;
  if(GetByID(id_world, world))
    return world.pWorld;

  return NULL;
}
//----------------------------------------------------------------------------------------------
btBroadphaseInterface* TPhysicEngine_Bullet::GetBroadphase(int id_world)
{
  TWorld world;
  if(GetByID(id_world, world))
    return world.pBroadphase;

  return NULL;
}
//----------------------------------------------------------------------------------------------
btCollisionDispatcher* TPhysicEngine_Bullet::GetDispatcher(int id_world)
{
  TWorld world;
  if(GetByID(id_world, world))
    return world.pDispatcher;

  return NULL;
}
//----------------------------------------------------------------------------------------------
btSequentialImpulseConstraintSolver* TPhysicEngine_Bullet::GetSolver(int id_world)
{
  TWorld world;
  if(GetByID(id_world, world))
    return world.pSolver;

  return NULL;
}
//----------------------------------------------------------------------------------------------
btDefaultCollisionConfiguration* TPhysicEngine_Bullet::GetCollisionConfiguration(int id_world)
{
  TWorld world;
  if(GetByID(id_world, world))
    return world.pCollisionConfiguration;

  return NULL;
}
//----------------------------------------------------------------------------------------------
bool TPhysicEngine_Bullet::GetByID(int id_world, TPhysicEngine_Bullet::TWorld& world)
{
  TMapIntWorldIt fit = mMapIDWorld.find(id_world);
  if(fit==mMapIDWorld.end())
    return false;

  world = fit->second;
  return true;
}
//----------------------------------------------------------------------------------------------
