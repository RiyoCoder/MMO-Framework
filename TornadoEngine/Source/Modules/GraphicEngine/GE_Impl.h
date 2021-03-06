/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef GRAPHIC_ENGINE_IMPLEMENTATION_H
#define GRAPHIC_ENGINE_IMPLEMENTATION_H

#include <Ogre.h>
#include <MyGUI.h>

#include "InputManagerOIS.h"
#include "MyGUI_LastHeader.h"
#include "MyGUI_OgrePlatform.h"
#include "CallBackRegistrator.h"
#include "Events.h"
#include "ControlClippingCursor.h"

class TGE_Impl :
  public TInputManagerOIS,
	public Ogre::FrameListener,
	public Ogre::WindowEventListener
{
  TControlClippingCursor mClipCursor;
  volatile bool flgCenterClippingCursor;
public:
	TGE_Impl();
	virtual ~TGE_Impl();

  bool InitOGRE(const std::string& pathPluginCfg);
  void AddResource(const std::string& name, const std::string& type);
  bool InitMyGUI(const std::string& nameFileCore, const std::string& nameFileSkin);

  bool Work();

  void SetCallBackKeyBoard(TCallBackRegistrator2<const OIS::KeyEvent &, bool>* pCB);
  void SetCallBackMouse(TCallBackRegistrator3<const OIS::MouseEvent &, OIS::MouseButtonID, nsGraphicEngine::tTypeMouseEvent>*  pCB);

  int GetModifierKeyBoard();

	void SetWindowCaption(const std::wstring& _text);
	size_t GetWindowHandle();

  void SetCenterClippingCursor(bool v);
  bool GetCenterClippingCursor();

	Ogre::SceneManager* GetSceneManager();
	Ogre::Root*         GetRoot();
	Ogre::Camera*       GetCamera();
  Ogre::RenderWindow* GetWindow();
protected:
  void ClipCursor();
  void UnclipCursor();

  bool IsWindowFocus();

  void SetKeyBoardModifier(const OIS::KeyEvent &arg, bool pressed);

  void Done();
	void DestroyGui();

  virtual bool mouseMoved( const OIS::MouseEvent &arg );
  virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
  virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
  virtual bool keyPressed(const OIS::KeyEvent &arg);
  virtual bool keyReleased(const OIS::KeyEvent &arg);		
private:
	virtual bool frameStarted(const Ogre::FrameEvent& _evt);
	virtual bool frameEnded(const Ogre::FrameEvent& _evt);
  virtual void windowMoved(Ogre::RenderWindow* rw);
	virtual void windowResized(Ogre::RenderWindow* _rw);
	virtual void windowClosed(Ogre::RenderWindow* _rw);
  virtual void windowFocusChange(Ogre::RenderWindow* rw);

private:
	MyGUI::Gui* mGUI;
	MyGUI::OgrePlatform* mPlatform;

	Ogre::Root* mRoot;
	Ogre::Camera* mCamera;
	Ogre::SceneManager* mSceneManager;
	Ogre::RenderWindow* mWindow;

	bool mExit;

  int mKeyModifier;

  TCallBackRegistrator2<const OIS::KeyEvent &, bool>* mCBKeyBoard;
  TCallBackRegistrator3<const OIS::MouseEvent&,OIS::MouseButtonID, nsGraphicEngine::tTypeMouseEvent>* mCBMouse;

  bool flgLControl_Press;
  bool flgRControl_Press;
  bool flgLAlt_Press;
  bool flgRAlt_Press;
  bool flgLShift_Press;
  bool flgRShift_Press;
};

#endif 
