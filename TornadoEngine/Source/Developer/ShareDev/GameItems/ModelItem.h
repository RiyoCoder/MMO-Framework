/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ModelItemH
#define ModelItemH

#include "BaseItem.h"

#include <map>
#include <set>
#include <vector>
#include <memory>
#include <list>

#include "ParamBuilderConstraint.h"
#include "MathTools.h"
#include "ContainerArrObj.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

struct DllExport TModelItem : public TBaseItem
{
  struct DllExport TJoint
  {
    std::string namePart;
    std::string nameJoint;
    bool operator < (const TJoint& right) const;
    bool operator > (const TJoint& right) const;
  };
  //---------------------------------------------------------
  typedef std::map<std::string,TJoint>     TMapExternalInternal;
  typedef TMapExternalInternal::iterator   TMapExternalInternalIt;
  typedef TMapExternalInternal::value_type TMapExternalInternalVT;
  //---------------------------------------------------------  
  struct DllExport TVariant
  {
    std::string name;    // уникален в пределах части (Part)
    std::string nameItem;// имя модели/формы

    std::string           redefinitionMaterial;// переопределение материала действует только для формы
    TMapExternalInternal  mapExternalInternal;
    nsMathTools::TVector3 scale;
  };
  //---------------------------------------------------------  
  struct DllExport TPart
  {
    std::vector<std::string> vecNameJoint;
    std::vector<TVariant>    vecVariant;
  };
  //---------------------------------------------------------  
  typedef std::map<std::string,TPart> TMapStrPart;
  typedef TMapStrPart::iterator   TMapStrPartIt;
  typedef TMapStrPart::value_type TMapStrPartVT;
  //---------------------------------------------------------  
  typedef std::auto_ptr<nsParamBuilderConstraint::TBaseParam> TAutoPtrConstraint;
  //---------------------------------------------------------  
  struct DllExport TLink
  {
    std::string nameJointBase;
    std::string nameJointBranch;
    TAutoPtrConstraint mPtrConstraint;

    TLink(){}
    TLink(const TLink& c);
    TLink& operator = (const TLink& c);
  };
  //---------------------------------------------------------  
  typedef std::list<TLink> TListLink;
  //---------------------------------------------------------  
  struct DllExport TLocation
  {
    std::string nameBase;
    std::string nameBranch;
    nsMathTools::TVector3 position;
    nsMathTools::TVector3 rotation;
    TListLink listLink;

    TLocation(){}
    TLocation(const TLocation& c);
    TLocation& operator = (const TLocation& c);
  };
  //---------------------------------------------------------  
  typedef std::multimap<std::string,TLocation> TMMapStrLocation;
  typedef TMMapStrLocation::iterator           TMMapStrLocationIt;
  typedef TMMapStrLocation::value_type         TMMapStrLocationVT;
  //---------------------------------------------------------
  struct DllExport TRoot
  {
    std::string           name;
    nsMathTools::TVector3 position;
    nsMathTools::TVector3 rotation;
  };
  //---------------------------------------------------------
  typedef std::map<std::string,std::string> TMapStrStr;
  typedef TMapStrStr::iterator              TMapStrStrIt;
  typedef TMapStrStr::value_type            TMapStrStrVT;
  //---------------------------------------------------------
  //---------------------------------------------------------
  std::string      mNamePattern;        // модель поведения

  TRoot            mRoot;
  TMMapStrLocation mMapNameBaseLocation;// иерархия

  typedef enum{eModel,eShape}eType;// либо модель, либо форма
  eType            mTypeCollection;
  TMapStrPart      mMapNamePart;        // набор
  
  TModelItem(std::string& name);
}_PACKED;

#if defined( WIN32 )
#pragma pack(pop)
#endif

#endif
