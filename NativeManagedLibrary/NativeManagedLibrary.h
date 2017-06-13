// NativeManagedLibrary.h

#pragma once
#include <msclr/all.h>
#include <map>
#include <string>
#define EXPORT __declspec(dllexport)

#ifdef __cplusplus
#define START_EXPORT extern "C" {
#define END_EXPORT }
#endif

using namespace System;
using namespace ManagedLibrary;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;
using std::map;
using std::string;

namespace NativeManagedLibrary
{
	template<typename T>
	struct Handle {
		msclr::auto_gcroot<T^> m_ManagedObject;

		template<typename... Args>
		Handle(Args... args);
	};

	template<typename T>
	template<typename... Args>
	Handle<T>::Handle(Args... args) : m_ManagedObject(args...)
	{
	}

	static map<string, void*> m_Pointers;


	START_EXPORT

	EXPORT Handle<Button>* CreateNewButton(int width, int height, int x, int y, const char* text);
	EXPORT void DestroyButton(Handle<Button>* button);
	
	EXPORT void SetButtonText(Handle<Button>* button, const char* text);
	EXPORT const char* GetButtonText(Handle<Button>* button);

	EXPORT int  GetButtonWidth(Handle<Button>* button);
	EXPORT int  GetButtonHeight(Handle<Button>* button);
	EXPORT void SetButtonSize(Handle<Button>* button, int width, int height);
	EXPORT void SetButtonHeight(Handle<Button>* button, int height);
	EXPORT void SetButtonWidth(Handle<Button>* button, int width);

	EXPORT void SetButtonPosition(Handle<Button>* button, int x, int y);
	EXPORT void SetButtonX(Handle<Button>* button, int x);
	EXPORT void SetButtonY(Handle<Button>* button, int y);
	EXPORT int  GetButtonX(Handle<Button>* button);
	EXPORT int  GetButtonY(Handle<Button>* button);
	
	EXPORT void ShowButton(Handle<Button>* button);
	EXPORT void HideButton(Handle<Button>* button);

	EXPORT void SetButtonHandler(Handle<Button>* button, const char* text);
	EXPORT void SetTextBoxHandler(Handle<TextBox>* box, const char* text);
	EXPORT void SetLabelHandler(Handle<Label>* label, const char* text);


	EXPORT Handle<TextBox>* CreateNewTextBox(int width, int height, int x, int y, const char* text);
	EXPORT void DestroyTextBox(Handle<TextBox>* textbox);

	EXPORT void SetTextBoxText(Handle<TextBox>* TextBox, const char* text);
	EXPORT const char* GetTextBoxText(Handle<TextBox>* TextBox);

	EXPORT int  GetTextBoxWidth(Handle<TextBox>* TextBox);
	EXPORT int  GetTextBoxHeight(Handle<TextBox>* TextBox);
	EXPORT void SetTextBoxSize(Handle<TextBox>* TextBox, int width, int height);
	EXPORT void SetTextBoxHeight(Handle<TextBox>* TextBox, int height);
	EXPORT void SetTextBoxWidth(Handle<TextBox>* TextBox, int width);

	EXPORT void SetTextBoxPosition(Handle<TextBox>* TextBox, int x, int y);
	EXPORT void SetTextBoxX(Handle<TextBox>* TextBox, int x);
	EXPORT void SetTextBoxY(Handle<TextBox>* TextBox, int y);
	EXPORT int  GetTextBoxX(Handle<TextBox>* TextBox);
	EXPORT int  GetTextBoxY(Handle<TextBox>* TextBox);

	EXPORT void ShowTextBox(Handle<TextBox>* TextBox);
	EXPORT void HideTextBox(Handle<TextBox>* TextBox);



	EXPORT Handle<Label>* CreateNewLabel(int width, int height, int x, int y, const char* text);
	EXPORT void DestroyLabel(Handle<Label>* Label);

	EXPORT void SetLabelText(Handle<Label>* Label, const char* text);
	EXPORT const char* GetLabelText(Handle<Label>* Label);

	EXPORT int  GetLabelWidth(Handle<Label>* Label);
	EXPORT int  GetLabelHeight(Handle<Label>* Label);
	EXPORT void SetLabelSize(Handle<Label>* Label, int width, int height);
	EXPORT void SetLabelHeight(Handle<Label>* Label, int height);
	EXPORT void SetLabelWidth(Handle<Label>* Label, int width);

	EXPORT void SetLabelPosition(Handle<Label>* Label, int x, int y);
	EXPORT void SetLabelX(Handle<Label>* Label, int x);
	EXPORT void SetLabelY(Handle<Label>* Label, int y);
	EXPORT int  GetLabelX(Handle<Label>* Label);
	EXPORT int  GetLabelY(Handle<Label>* Label);

	EXPORT void ShowLabel(Handle<Label>* Label);
	EXPORT void HideLabel(Handle<Label>* Label);









	EXPORT void		SetInt(const char* name, int value);
	EXPORT int		GetInt(const char* name);

	EXPORT void		SetString(const char* name, const char* text);
	EXPORT char*	GetString(const char* name);

	EXPORT void		SetDouble(const char* name, double value);
	EXPORT double	GetDouble(const char* name);

	EXPORT void				SetBytes(const char* name, unsigned char* bytes);
	EXPORT unsigned char*	GetBytes(const char* name);

	EXPORT void				SetPointer(const char* name, void* ptr);
	EXPORT void*			GetPointer(const char* name);


	END_EXPORT
}
