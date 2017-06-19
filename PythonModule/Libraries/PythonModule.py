from ctypes import *

DLL = CDLL("NativeManagedLibrary.dll")

DLL.SetPointer.restype = c_void_p;
DLL.SetPointer.argtypes = [c_char_p, c_void_p];

DLL.GetPointer.restype = c_void_p;
DLL.GetPointer.argtypes = [c_char_p];

class Button(object):
    
    DLL.CreateNewButton.argtypes = [c_int, c_int, c_int, c_int, c_char_p]
    DLL.CreateNewButton.restype = c_void_p

    DLL.GetButtonText.restype = c_char_p;
    DLL.SetButtonText.argtypes = [c_void_p, c_char_p];

    DLL.SetButtonHandler.argtypes = [c_void_p, c_char_p];      


    def __init__(self, *args):
        if len(args) == 1:       
            self.handle = args[0]
        else:
            self.handle = DLL.CreateNewButton(args[0], args[1], args[2], args[3], args[4])


    def Destroy(self):
            DLL.DestroyButton(self.handle)

    def SetReference(self, name):
        DLL.SetPointer(name, c_void_p(self.handle))

    @classmethod
    def GetReference(cls, name):
         return cls(DLL.GetPointer(name))

    @classmethod
    def GetNew(cls, width, height, x, y, text):
        return cls(width,height,x,y,text)

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

    DLL.CreateNewTextBox.argtypes = [c_int, c_int, c_int, c_int, c_char_p]
    DLL.CreateNewTextBox.restype = c_void_p

    DLL.GetTextBoxText.restype = c_char_p
    DLL.SetTextBoxText.argtypes = [c_void_p, c_char_p]

    DLL.SetTextBoxHandler.argtypes = [c_void_p, c_char_p]

    def __init__(self, *args):
        if len(args) == 1:       
            self.handle = args[0]
        else:
            self.handle = DLL.CreateNewTextBox(args[0], args[1], args[2], args[3], args[4])

    def Destroy(self):
            DLL.DestroyTextBox(self.handle)


    def SetReference(self, name):
        DLL.SetPointer(name, c_void_p(self.handle))

    @classmethod
    def GetReference(cls, name):
         return cls(DLL.GetPointer(name))

    @classmethod
    def GetNew(cls, width, height, x, y, text):
        return cls(width,height,x,y,text)

    def SetSize(self, width, height):
        DLL.SetTextBoxSize(self.handle, width, height)
    def SetWidth(self, width):
        DLL.SetTextBoxWidth(self.handle, width)
    def SetHeight(self, height):
        DLL.SetTextBoxHeight(self.handle, height)

    def GetWidth(self):
        return DLL.GetTextBoxWidth(self.handle)
    def GetHeight(self):
        return DLL.GetTextBoxHeight(self.handle)

    def SetPosition(self, x, y):
        DLL.SetTextBoxPosition(self,x,y)
    def SetPositionX(self, x):
        DLL.SetTextBoxX(self.handle, x)
    def SetPositionY(self, y):
        DLL.SetTextBoxY(self.handle, y)

    def GetPositionX(self):
        return DLL.GetTextBoxX(self.handle)
    def GetPositionY(self):
        return DLL.GetTextBoxY(self.handle)

    def GetText(self):
        return DLL.GetTextBoxText(self.handle)
    def SetText(self, text):
        return DLL.SetTextBoxText(self.handle, text)

    def Show(self):
        DLL.ShowTextBox(self.handle)
    def Hide(self):
        DLL.HideTextBox(self.handle)

class Label(object):

    DLL.CreateNewLabel.argtypes = [c_int, c_int, c_int, c_int, c_char_p]
    DLL.CreateNewLabel.restype = c_void_p

    DLL.GetLabelText.restype = c_char_p;
    DLL.SetLabelText.argtypes = [c_void_p, c_char_p];

    DLL.SetLabelHandler.argtypes = [c_void_p, c_char_p];

    def __init__(self, *args):
        if len(args) == 1:       
            self.handle = args[0]
        else:
            self.handle = DLL.CreateNewLabel(args[0], args[1], args[2], args[3], args[4])
    
    def Destroy(self):
            DLL.DestroyLabel(self.handle)

    def SetReference(self, name):
        DLL.SetPointer(name, c_void_p(self.handle))
    
    @classmethod
    def GetReference(cls, name):
         return cls(DLL.GetPointer(name))

    @classmethod
    def GetNew(cls, width, height, x, y, text):
        return cls(width,height,x,y,text)

    def SetSize(self, width, height):
        DLL.SetLabelSize(self.handle, width, height)
    def SetWidth(self, width):
        DLL.SetLabelWidth(self.handle, width)
    def SetHeight(self, height):
        DLL.SetLabelHeight(self.handle, height)

    def GetWidth(self):
        return DLL.GetLabelWidth(self.handle)
    def GetHeight(self):
        return DLL.GetLabelHeight(self.handle)

    def SetPosition(self, x, y):
        DLL.SetLabelPosition(self,x,y)
    def SetPositionX(self, x):
        DLL.SetLabelX(self.handle, x)
    def SetPositionY(self, y):
        DLL.SetLabelY(self.handle, y)

    def GetPositionX(self):
        return DLL.GetLabelX(self.handle)
    def GetPositionY(self):
        return DLL.GetLabelY(self.handle)

    def GetText(self):
        return DLL.GetLabelText(self.handle)
    def SetText(self, text):
        return DLL.SetLabelText(self.handle, text)

    def Show(self):
        DLL.ShowLabel(self.handle)
    def Hide(self):
        DLL.HideLabel(self.handle)