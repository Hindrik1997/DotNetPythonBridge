from PythonModule import *

DLL.SetInt("hallo", 1)
print(DLL.GetInt("hallo"))

button = Button(100,200,100,200,"Hello")
button.SetText("hello!")
print(button.GetText())

button.SetHeight(100)
print(button.GetHeight())

button.SetWidth(100)
print(button.GetWidth())

button.SetOnClickFile("Click")