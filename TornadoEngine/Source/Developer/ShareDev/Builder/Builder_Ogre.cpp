/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Builder_Ogre.h"

TBuilder_Ogre::TBuilder_Ogre()
{

}
//---------------------------------------------------------------------------------
TBuilder_Ogre::~TBuilder_Ogre()
{

}
//---------------------------------------------------------------------------------
TBuilderShape_Ogre* TBuilder_Ogre::GetShapeMaker()
{
  return &mBuilderShape_Ogre;
}
//---------------------------------------------------------------------------------
