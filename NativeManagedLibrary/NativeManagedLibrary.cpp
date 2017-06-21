// This is the main DLL file.

#include "stdafx.h"

#include "NativeManagedLibrary.h"

using namespace NativeManagedLibrary;
using namespace System::Drawing;

Handle<Button>* NativeManagedLibrary::CreateNewButton(int width, int height, int x, int y, const char * text)
{
	String^ t = gcnew String(text);
	Handle<Button>* button = new Handle<Button>(ManagedLibrary::ExposedInterface::CreateNewButton(width, height, x,y, t));
	return button;
}

void NativeManagedLibrary::DestroyButton(Handle<Button>* button)
{
	ExposedInterface::m_Form->Controls->Remove(button->m_ManagedObject.get());
	delete button;
}

void NativeManagedLibrary::SetButtonText(Handle<Button>* button, const char * text)
{
	String^ s = gcnew String(text);
	button->m_ManagedObject.get()->Text = s;
}

const char * NativeManagedLibrary::GetButtonText(Handle<Button>* button)
{
	String^ t = button->m_ManagedObject.get()->Text;
	IntPtr ptr = Marshal::StringToHGlobalAnsi(t);
	char* string = static_cast<char*>(ptr.ToPointer());
	char* allocated = new char[strlen(string) + 1];
	memcpy(allocated,string, strlen(string) + 1);
	return allocated;
}

int NativeManagedLibrary::GetButtonWidth(Handle<Button>* button)
{
	return button->m_ManagedObject.get()->Width;
}

int NativeManagedLibrary::GetButtonHeight(Handle<Button>* button)
{
	return button->m_ManagedObject.get()->Height;
}

void NativeManagedLibrary::SetButtonSize(Handle<Button>* button, int width, int height)
{
	button->m_ManagedObject.get()->Height = height;
	button->m_ManagedObject.get()->Width  = width;

}

void NativeManagedLibrary::SetButtonHeight(Handle<Button>* button, int height)
{
	button->m_ManagedObject.get()->Height = height;
}

void NativeManagedLibrary::SetButtonWidth(Handle<Button>* button, int width)
{
	button->m_ManagedObject.get()->Width = width;
}

void NativeManagedLibrary::SetButtonPosition(Handle<Button>* button, int x, int y)
{
	button->m_ManagedObject.get()->Location.X = x;
	button->m_ManagedObject.get()->Location.Y = y;
}

void NativeManagedLibrary::SetButtonX(Handle<Button>* button, int x)
{
	button->m_ManagedObject.get()->Location.X = x;
}

void NativeManagedLibrary::SetButtonY(Handle<Button>* button, int y)
{
	button->m_ManagedObject.get()->Location.Y = y;
}

int NativeManagedLibrary::GetButtonX(Handle<Button>* button)
{
	return button->m_ManagedObject.get()->Location.X;
}

int NativeManagedLibrary::GetButtonY(Handle<Button>* button)
{
	return button->m_ManagedObject.get()->Location.Y;
}

void NativeManagedLibrary::ShowButton(Handle<Button>* button)
{
	button->m_ManagedObject.get()->Show();
}

void NativeManagedLibrary::HideButton(Handle<Button>* button)
{
	button->m_ManagedObject.get()->Hide();
}


Handle<TextBox>* NativeManagedLibrary::CreateNewTextBox(int width, int height, int x, int y, const char * text)
{
	String^ t = gcnew String(text);
	Handle<TextBox>* box = new Handle<TextBox>(ManagedLibrary::ExposedInterface::CreateNewTextBox(width, height, x, y, t));
	return box;
}

void NativeManagedLibrary::DestroyTextBox(Handle<TextBox>* button)
{
	ExposedInterface::m_Form->Controls->Remove(button->m_ManagedObject.get());
	delete button;
}

void NativeManagedLibrary::SetTextBoxText(Handle<TextBox>* TextBox, const char * text)
{
	String^ s = gcnew String(text);
	TextBox->m_ManagedObject.get()->Text = s;
}

const char * NativeManagedLibrary::GetTextBoxText(Handle<TextBox>* TextBox)
{
	String^ t = TextBox->m_ManagedObject.get()->Text;
	IntPtr ptr = Marshal::StringToHGlobalAnsi(t);
	char* string = static_cast<char*>(ptr.ToPointer());
	char* allocated = new char[strlen(string) + 1];
	memcpy(allocated, string, strlen(string) + 1);
	return allocated;
}

int NativeManagedLibrary::GetTextBoxWidth(Handle<TextBox>* TextBox)
{
	return TextBox->m_ManagedObject.get()->Width;
}

int NativeManagedLibrary::GetTextBoxHeight(Handle<TextBox>* TextBox)
{
	return TextBox->m_ManagedObject.get()->Height;
}

void NativeManagedLibrary::SetTextBoxSize(Handle<TextBox>* TextBox, int width, int height)
{
	TextBox->m_ManagedObject.get()->Height = height;
	TextBox->m_ManagedObject.get()->Width = width;

}

void NativeManagedLibrary::SetTextBoxHeight(Handle<TextBox>* TextBox, int height)
{
	TextBox->m_ManagedObject.get()->Height = height;
}

void NativeManagedLibrary::SetTextBoxWidth(Handle<TextBox>* TextBox, int width)
{
	TextBox->m_ManagedObject.get()->Width = width;
}

void NativeManagedLibrary::SetTextBoxPosition(Handle<TextBox>* TextBox, int x, int y)
{
	TextBox->m_ManagedObject.get()->Location.X = x;
	TextBox->m_ManagedObject.get()->Location.Y = y;
}

void NativeManagedLibrary::SetTextBoxX(Handle<TextBox>* TextBox, int x)
{
	TextBox->m_ManagedObject.get()->Location.X = x;
}

void NativeManagedLibrary::SetTextBoxY(Handle<TextBox>* TextBox, int y)
{
	TextBox->m_ManagedObject.get()->Location.Y = y;
}

int NativeManagedLibrary::GetTextBoxX(Handle<TextBox>* TextBox)
{
	return TextBox->m_ManagedObject.get()->Location.X;
}

int NativeManagedLibrary::GetTextBoxY(Handle<TextBox>* TextBox)
{
	return TextBox->m_ManagedObject.get()->Location.Y;
}

void NativeManagedLibrary::ShowTextBox(Handle<TextBox>* TextBox)
{
	TextBox->m_ManagedObject.get()->Show();
}

void NativeManagedLibrary::HideTextBox(Handle<TextBox>* TextBox)
{
	TextBox->m_ManagedObject.get()->Hide();
}




Handle<InjectableWebBrowser>* NativeManagedLibrary::CreateNewWebBrowser(int width, int height, int x, int y, const char * text)
{
	String^ t = gcnew String(text);
	Handle<InjectableWebBrowser>* box = new Handle<InjectableWebBrowser>(ManagedLibrary::ExposedInterface::CreateNewWebBrowser(width, height, x, y, t));
	return box;
}

void NativeManagedLibrary::DestroyWebBrowser(Handle<InjectableWebBrowser>* button)
{
	ExposedInterface::m_Form->Controls->Remove(button->m_ManagedObject.get());
	delete button;
}

void NativeManagedLibrary::SetWebBrowserURL(Handle<InjectableWebBrowser>* WebBrowser, const char * text)
{
	String^ s = gcnew String(text);
	WebBrowser->m_ManagedObject.get()->Url = gcnew Uri(s);
}

const char * NativeManagedLibrary::GetWebBrowserURL(Handle<InjectableWebBrowser>* WebBrowser)
{
	String^ t = WebBrowser->m_ManagedObject.get()->Url->ToString();
	IntPtr ptr = Marshal::StringToHGlobalAnsi(t);
	char* string = static_cast<char*>(ptr.ToPointer());
	char* allocated = new char[strlen(string) + 1];
	memcpy(allocated, string, strlen(string) + 1);
	return allocated;
}

void NativeManagedLibrary::WebBrowserNavigate(Handle<InjectableWebBrowser>* webBrowser, const char * text)
{
	String^ t = gcnew String(text);
	webBrowser->m_ManagedObject.get()->Navigate(t);
}

int NativeManagedLibrary::GetWebBrowserWidth(Handle<InjectableWebBrowser>* WebBrowser)
{
	return WebBrowser->m_ManagedObject.get()->Width;
}

int NativeManagedLibrary::GetWebBrowserHeight(Handle<InjectableWebBrowser>* WebBrowser)
{
	return WebBrowser->m_ManagedObject.get()->Height;
}

void NativeManagedLibrary::SetWebBrowserSize(Handle<InjectableWebBrowser>* WebBrowser, int width, int height)
{
	WebBrowser->m_ManagedObject.get()->Height = height;
	WebBrowser->m_ManagedObject.get()->Width = width;

}

void NativeManagedLibrary::SetWebBrowserHeight(Handle<InjectableWebBrowser>* WebBrowser, int height)
{
	WebBrowser->m_ManagedObject.get()->Height = height;
}

void NativeManagedLibrary::SetWebBrowserWidth(Handle<InjectableWebBrowser>* WebBrowser, int width)
{
	WebBrowser->m_ManagedObject.get()->Width = width;
}

void NativeManagedLibrary::SetWebBrowserPosition(Handle<InjectableWebBrowser>* WebBrowser, int x, int y)
{
	WebBrowser->m_ManagedObject.get()->Location.X = x;
	WebBrowser->m_ManagedObject.get()->Location.Y = y;
}

void NativeManagedLibrary::SetWebBrowserX(Handle<InjectableWebBrowser>* WebBrowser, int x)
{
	WebBrowser->m_ManagedObject.get()->Location.X = x;
}

void NativeManagedLibrary::SetWebBrowserY(Handle<InjectableWebBrowser>* WebBrowser, int y)
{
	WebBrowser->m_ManagedObject.get()->Location.Y = y;
}

int NativeManagedLibrary::GetWebBrowserX(Handle<InjectableWebBrowser>* WebBrowser)
{
	return WebBrowser->m_ManagedObject.get()->Location.X;
}

int NativeManagedLibrary::GetWebBrowserY(Handle<InjectableWebBrowser>* WebBrowser)
{
	return WebBrowser->m_ManagedObject.get()->Location.Y;
}

void NativeManagedLibrary::ShowWebBrowser(Handle<InjectableWebBrowser>* WebBrowser)
{
	WebBrowser->m_ManagedObject.get()->Show();
}

void NativeManagedLibrary::HideWebBrowser(Handle<InjectableWebBrowser>* WebBrowser)
{
	WebBrowser->m_ManagedObject.get()->Hide();
}

void NativeManagedLibrary::InjectJS(Handle<InjectableWebBrowser>* WebBrowser, const char* js)
{
	String^ t = gcnew String(js);
	WebBrowser->m_ManagedObject.get()->ExecuteJavascript(t);
}



void NativeManagedLibrary::SetButtonHandler(Handle<Button>* button, const char * text)
{

	String^ t = gcnew String(text);
	ManagedLibrary::ExposedInterface::SetEventHandler(button->m_ManagedObject.get(), t);
}

void NativeManagedLibrary::SetTextBoxHandler(Handle<TextBox>* box, const char * text)
{
	String^ t = gcnew String(text);
	ManagedLibrary::ExposedInterface::SetEventHandler(box->m_ManagedObject.get(), t);
}

void NativeManagedLibrary::SetLabelHandler(Handle<Label>* label, const char * text)
{
	String^ t = gcnew String(text);
	ManagedLibrary::ExposedInterface::SetEventHandler(label->m_ManagedObject.get(), t);
}

void NativeManagedLibrary::SetWebBrowserHandler(Handle<Label>* label, const char * text)
{
	String^ t = gcnew String(text);
	ManagedLibrary::ExposedInterface::SetEventHandler(label->m_ManagedObject.get(), t);
}






void NativeManagedLibrary::SetInt(const char * name, int value)
{
	String^ t = gcnew String(name);
	ManagedLibrary::VariableStorage::SetInt(t, value);
}

int NativeManagedLibrary::GetInt(const char * name)
{
	String^ t = gcnew String(name);
	return ManagedLibrary::VariableStorage::GetInt(t);
}

void NativeManagedLibrary::SetString(const char * name, const char * text)
{
	String^ t = gcnew String(name);
	String^ val = gcnew String(text);
	ManagedLibrary::VariableStorage::SetString(t, val);
}

char * NativeManagedLibrary::GetString(const char * name)
{
	String^ t = ManagedLibrary::VariableStorage::GetString(gcnew String(name));
	IntPtr ptr = Marshal::StringToHGlobalAnsi(t);
	char* string = static_cast<char*>(ptr.ToPointer());
	char* allocated = new char[strlen(string) + 1];
	memcpy(allocated, string, strlen(string) + 1);
	return allocated;
}

void NativeManagedLibrary::SetDouble(const char * name, double value)
{
	ManagedLibrary::VariableStorage::SetDouble(gcnew String(name), value);
}

double NativeManagedLibrary::GetDouble(const char * name)
{
	return ManagedLibrary::VariableStorage::GetDouble(gcnew String(name));
}

void NativeManagedLibrary::SetBytes(const char * name, unsigned char * bytes)
{



}

unsigned char * NativeManagedLibrary::GetBytes(const char * name)
{
	return nullptr;
}

void NativeManagedLibrary::SetPointer(const char * name, void * ptr)
{
	if (ptr == nullptr)
		throw "Error, received nullptr!";
	
	string cppName(name);
	m_Pointers[cppName] = ptr;
}

void * NativeManagedLibrary::GetPointer(const char * name)
{
	auto it = m_Pointers.find(string(name));
	if (it != end(m_Pointers))
	{
		return it->second;
	}
	throw "Error, no such pointer found!";
}



Handle<Label>* NativeManagedLibrary::CreateNewLabel(int width, int height, int x, int y, const char * text)
{
	String^ t = gcnew String(text);
	Handle<Label>* button = new Handle<Label>(ManagedLibrary::ExposedInterface::CreateNewLabel(width, height, x, y, t));
	return button;
}

void NativeManagedLibrary::DestroyLabel(Handle<Label>* button)
{
	ExposedInterface::m_Form->Controls->Remove(button->m_ManagedObject.get());
	delete button;
}

void NativeManagedLibrary::SetLabelText(Handle<Label>* button, const char * text)
{
	String^ s = gcnew String(text);
	button->m_ManagedObject.get()->Text = s;
}

const char * NativeManagedLibrary::GetLabelText(Handle<Label>* button)
{
	String^ t = button->m_ManagedObject.get()->Text;
	IntPtr ptr = Marshal::StringToHGlobalAnsi(t);
	char* string = static_cast<char*>(ptr.ToPointer());
	char* allocated = new char[strlen(string) + 1];
	memcpy(allocated, string, strlen(string) + 1);
	return allocated;
}

int NativeManagedLibrary::GetLabelWidth(Handle<Label>* button)
{
	return button->m_ManagedObject.get()->Width;
}

int NativeManagedLibrary::GetLabelHeight(Handle<Label>* button)
{
	return button->m_ManagedObject.get()->Height;
}

void NativeManagedLibrary::SetLabelSize(Handle<Label>* button, int width, int height)
{
	button->m_ManagedObject.get()->Height = height;
	button->m_ManagedObject.get()->Width = width;

}

void NativeManagedLibrary::SetLabelHeight(Handle<Label>* button, int height)
{
	button->m_ManagedObject.get()->Height = height;
}

void NativeManagedLibrary::SetLabelWidth(Handle<Label>* button, int width)
{
	button->m_ManagedObject.get()->Width = width;
}

void NativeManagedLibrary::SetLabelPosition(Handle<Label>* button, int x, int y)
{
	button->m_ManagedObject.get()->Location.X = x;
	button->m_ManagedObject.get()->Location.Y = y;
}

void NativeManagedLibrary::SetLabelX(Handle<Label>* button, int x)
{
	button->m_ManagedObject.get()->Location.X = x;
}

void NativeManagedLibrary::SetLabelY(Handle<Label>* button, int y)
{
	button->m_ManagedObject.get()->Location.Y = y;
}

int NativeManagedLibrary::GetLabelX(Handle<Label>* button)
{
	return button->m_ManagedObject.get()->Location.X;
}

int NativeManagedLibrary::GetLabelY(Handle<Label>* button)
{
	return button->m_ManagedObject.get()->Location.Y;
}

void NativeManagedLibrary::ShowLabel(Handle<Label>* button)
{
	button->m_ManagedObject.get()->Show();
}

void NativeManagedLibrary::HideLabel(Handle<Label>* button)
{
	button->m_ManagedObject.get()->Hide();
}