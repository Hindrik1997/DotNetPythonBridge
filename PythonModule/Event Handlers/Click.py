from PythonModule import *

b = Button.GetReference("button")
print("You clicked me! :(")
print("You are a fool!")

print(b.GetText())


browser = WebBrowser.GetReference("browser")
browser.Navigate("http://www.google.nl")
browser.InjectJS("alert(\"hoi\")")