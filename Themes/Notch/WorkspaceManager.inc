[Variables]
workspacemanager_x=552
;Left, Right or Center
Workspacemanager_Anchor=middle
Maximum_Workspace = 10
Workspace_Number_Gap = 15

;Self-generated, change Workspacemanager_Anchor instead.
WorkspaceAnchorPoint = 0
Workspace_Total
Workspace_Current
[Metadata]
Name=Notch\\Workspace Manager
Author=reddit.com/u/khanhas
Description=Click at number to change to desired workspace. Middle click to create new workspace. Choose a windows then hold Shift + click at number to move that window to desired workspace.

[VirtualDesktop]
Measure = Plugin
Plugin = PowershellRM
ScriptFile = #@#VirtualDesktop.ps1
UpdateDivider = -1

[Workspace_Total]
Measure= Plugin
Plugin = PowershellRM
Parent = VirtualDesktop
Line = Get-DesktopCount

[Workspace_Current]
Measure= Plugin
Plugin = PowershellRM
Parent = VirtualDesktop
Line = (Get-CurrentDesktop | Get-DesktopIndex) + 1

[WorkspaceAnchorPoint]
Measure=String
String = #Workspacemanager_Anchor#
IfMatch=Center|center|Middle|middle
IfMatchAction=!SetOption WorkspaceContainer X "(#Bar_OffsetX#+#*workspacemanager_x*#-[*WorkspaceContainer:W*]/2)"
IfMatch2=Right|right
IfMatchAction2=!SetOption WorkspaceContainer X "(#Bar_OffsetX#+#*workspacemanager_x*#-[*WorkspaceContainer:W*])"

[WorkspaceScript]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#Themes\#Theme#\Assets\script_Workspace.lua

[WorkspaceActionTimer]
Measure=Plugin
Plugin=Actiontimer
ActionList1=Repeat ScriptAnimation,16,1000
ScriptAnimation=!CommandMeasure WorkspaceScript "ChangeWorkspaceAnimation()"

[StyleWSNumber]
X=R
Shape  = Ellipse #Workspace_Number_Gap#,(#Bar_Height#/2),5 | StrokeWidth 0 | FillColor #Color_Scheme2#64
Shape2 = Rectangle 0,0,(#Workspace_Number_Gap#*2),#Bar_Height# | StrokeWidth 0 | FillColor 0,0,0,1
Group = WSNumber
Container = WorkspaceContainer
MiddleMouseUpAction = [!CommandMeasure VirtualDesktop "New-Desktop | Switch-Desktop"][!Update][!UpdateMeter WorkspaceContainer][!Redraw]

[Workspace1]
Meter=Shape
X=0
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure VirtualDesktop "Switch-Desktop 0"][!Update]
[Workspace2]
Meter=Shape
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure VirtualDesktop "Switch-Desktop 1"][!Update]
[Workspace3]
Meter=Shape
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure VirtualDesktop "Switch-Desktop 2"][!Update]
[Workspace4]
Meter=Shape
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure VirtualDesktop "Switch-Desktop 3"][!Update]
[Workspace5]
Meter=Shape
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure VirtualDesktop "Switch-Desktop 4"][!Update]
[Workspace6]
Meter=Shape
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure VirtualDesktop "Switch-Desktop 5"][!Update]
[Workspace7]
Meter=Shape
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure VirtualDesktop "Switch-Desktop 6"][!Update]
[Workspace8]
Meter=Shape
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure VirtualDesktop "Switch-Desktop 7"][!Update]
[Workspace9]
Meter=Shape
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure VirtualDesktop "Switch-Desktop 8"][!Update]
[Workspace10]
Meter=Shape
MeterStyle=StyleWSNumber
LeftMouseUpAction=[!CommandMeasure VirtualDesktop "Switch-Desktop 9"][!Update]

[WorkspaceCurrent]
Meter=Shape
X=#Workspace_Number_Gap#
Y=(#Bar_Height#/2)
Shape=Ellipse 0,0,5.5 | Extend Trait
Trait = StrokeWidth 0 | Fill Color #Color_Scheme2#
Container = WorkspaceContainer

[WorkspaceContainer]
Meter=Shape
X=(#Bar_OffsetX#+#workspacemanager_x#)
Y=#Bar_OffsetY#
DynamicVariables=1
