from ctypes import *

DLL = CDLL("NativeManagedLibrary.dll")

class Button(object):
    
    DLL.CreateNewButton.argtypes = [c_int, c_int, c_int, c_int, c_char_p]
    DLL.CreateNewButton.restype = c_void_p

    DLL.GetButtonText.restype = c_char_p;
    DLL.SetButtonText.argtypes = [c_void_p, c_char_p];

    DLL.SetButtonHandler.argtypes = [c_void_p, c_char_p];


    def __init__(self, width, height, x, y, text):
        self.handle = DLL.CreateNewButton(width, height, x, y, text)
    def __del__(self):
        DLL.DestroyButton(self.handle)

    
    def SetSize(self, width, height):
        DLL.SetButtonSize(self.handle, width, height)
    def SetWidth(self, width):
        DLL.SetButtonWidth(self.handle, width)
    def SetHeight(self, height):
        DLL.SetButtonHeight(self.handle, height)

    def GetWidth(self):
        return DLL.GetButtonWidth(self.handle)
    def GetHeight(self):
        return DLL.GetButtonHeight(self.handle)

    def SetPosition(self, x, y):
        DLL.SetButtonPosition(self,x,y)
    def SetPositionX(self, x):
        DLL.SetButtonX(self.handle, x)
    def SetPositionY(self, y):
        DLL.SetButtonY(self.handle, y)

    def GetPositionX(self):
        return DLL.GetButtonX(self.handle)
    def GetPositionY(self):
        return DLL.GetButtonY(self.handle)

    def GetText(self):
        return DLL.GetButtonText(self.handle)
    def SetText(self, text):
        return DLL.SetButtonText(self.handle, text)

    def Show(self):
        DLL.ShowButton(self.handle)
    def Hide(self):
        DLL.HideButton(self.handle)

    def SetOnClickFile(self, text):
        DLL.SetButtonHandler(self.handle, text)

class TextBox(object):

    def __init__():
        self.handle = 0
    def __del__(self):
        return

class Label(object):

    def __init__():
        self.handle = 0

    def __del__(self):
        return


