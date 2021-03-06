[Variables]
Tray_X=854

[Metadata]
Name=Notch\\Tray
Author=reddit.com/u/khanhas
Description=Click to show tray

[TrayIconDirection]
Measure=String
String=
IfCondition=SubSkinDirectionCalc = 1
IfTrueAction=[!SetOption TrayIconDirection String "[\xE5CE]"]
IfFalseAction=[!SetOption TrayIconDirection String "[\xE5CF]"]
DynamicVariables=1

[TrayOffsetX]
Measure = Calc
Formula = #CURRENTCONFIGX#+[TrayButton:X]+[TrayButton:W]/2
DynamicVariables = 1

[TrayButton]
Meter=String
MeasureName=TrayIconDirection
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme3#
AntiAlias=1
StringAlign=CenterCenter
X=(#Bar_OffsetX#+#Tray_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
H=#Bar_Height#
SolidColor=0,0,0,1
DynamicVariables=1
LeftMouseDownAction=["#@#AutoHotKey\ActivateTray.exe" "[TrayOffsetX]" "[SubSkinYPositionCalc]" "[SubSkinDirectionCalc]"]
