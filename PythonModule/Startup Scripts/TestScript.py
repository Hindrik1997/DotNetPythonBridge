from PythonModule import *

DLL.SetInt("hallo", 1)
print(DLL.GetInt("hallo"))

button = Button(100,200,100,200,"Hello")
button.SetReference("button")
#button = Button.GetReference("button")
print(button.GetText())

button.SetHeight(100)
print(button.GetHeight())

button.SetWidth(100)
print(button.GetWidth())

button.SetOnClickFile("Click")

browser = WebBrowser(400,400,0,0, "http://www.google.nl")
browser.Navigate("http://www.google.nl")
browser.SetReference("browser")