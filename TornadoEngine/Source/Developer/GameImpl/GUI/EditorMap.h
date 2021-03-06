/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef EditorMapH
#define EditorMapH

#include "BaseGUI.h"
#include <MyGUI.h>
#include <Ogre.h>

#include <boost/smart_ptr/scoped_ptr.hpp>

#define TypeEvent_EditorMap 999
struct DllExport TLoadMapParam
{
  char/*std::string*/ nameMap[100];
};

class TEditorMap : public TBaseGUI
{
  TLoadMapParam mLMP;
public:
  TEditorMap();
  virtual ~TEditorMap();

protected:
  virtual void Activate();
  virtual void* GetParent();
  virtual const char* GetNameLayout();
  virtual void SetupTabChild();

  virtual void KeyEvent(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char);
protected:
  void sl_Open(MyGUI::Widget* _sender);
  void sl_Exit(MyGUI::Widget* _sender);
protected:
  MyGUI::MenuBar*     mBar;
  MyGUI::MenuControl* mPopupMenu_File;
  MyGUI::MenuControl* mPopupMenu_NewShape;
  MyGUI::MenuControl* mPopupMenu_Instruments;

  MyGUI::MenuItem* miOpen;
  MyGUI::MenuItem* miSave;
  MyGUI::MenuItem* miExit;
};

#endif 
