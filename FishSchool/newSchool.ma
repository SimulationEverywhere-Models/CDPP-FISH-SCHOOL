#include (newSchool.inc)

[top]
components : school

[school]
type : cell
dim : (10, 10, 3)  %top layer will contain angle of the leader

delay : transport
defaultDelayTime  : 100
border : wrapped 

%layer 1
neighbors : 						 	    				school(-3,0,0)
neighbors : 				school(-2,-2,0) school(-2,-1,0) school(-2,0,0) school(-2,1,0) school(-2,2,0) 
neighbors : 				school(-1,-2,0) school(-1,-1,0) school(-1,0,0) school(-1,1,0) school(-1,2,0) 
neighbors : school(0,-3,0)  school(0,-2,0)  school(0,-1,0)  school(0,0,0)  school(0,1,0)  school(0,2,0)  school(0,3,0)  
neighbors : 				school(1,-2,0)	school(1,-1,0)  school(1,0,0)  school(1,1,0)  school(1,2,0)  
neighbors : 				school(2,-2,0)  school(2,-1,0)  school(2,0,0)  school(2,1,0)  school(2,2,0)  
neighbors : 												school(3,0,0)

%layer 2
neighbors : 						 	   school(-1,0,1)
neighbors : 				school(0,-1,1) school(0,0,1) school(0,1,1)
neighbors : 							   school(1,0,1)

%giving layers access to one another 
neighbors : 								school(0,0,-1)
neighbors : 								school(0,0,-2)

%layer 3
neighbors : 							  school(-1,0,2)
neighbors : 				school(0,-1,2)				school(0,1,2)
neighbors : 							  school(1,0,2)

initialvalue : 0

%in order to test different scenarios, please comment out the code below and uncomment another initialCellsValue line

initialCellsValue : newSchool.val

%initialCellsValue : test1.val

%initialCellsValue : test2.val

%initialCellsValue : test3.val

%initialCellsValue : test4.val



localtransition : nothing
zone : layer1 { (0,0,0)..(9,9,0) }
zone : layer2 { (0,0,1)..(9,9,1) }
zone : layer3 { (0,0,2)..(9,9,2) }

%The priority of fish is 1) left 2) right 3) up 4) down

[layer1]
%Delay execution of layer 1 rules
rule : { (0,0,0) } 100 { time < 200 }

%keep position if attached
rule : { (0,0,0) } 100 { (0,0,0) = 5 and (#Macro(Attached)) }
rule : { (0,0,0) } 100 { (0,0,0) = 0 and ((#Macro(VerticalAttached)) or (#Macro(HorizontalAttached))) } 
rule : { (0,0,0) } 100 { (0,0,0) = 5 and (0,2,0) = 5 and (0,-2,0) != 5 and (#Macro(FarRightCellNotAttached))} %if you are the far left cell
rule : { (0,0,0) } 100 { (0,0,0) = 5 and (2,0,0) = 5 and (-2,0,0) != 5 and (#Macro(NoHorizontalMove)) and (#Macro(NoHorizontalMoveLowerFish)) and (#Macro(LowerFishNotAttached)) } %if you are the upper cell and no left or right move available
rule : { (0,0,0) } 100 { (0,0,0) = 5 and ((#Macro(UpperCellDontMove)) or (#Macro(LowerCellDontMove))) }

%Rules for fish separated by 1 cell
rule : { (0,1,0) } 100 { (0,1,0) = 5 and (0,-1,0) = 5 and (#Macro(RightCellNotAttached)) and ((0,1,2) != 1  or time <= 200) } % move left
rule : { (0,-1,0) } 100 { (0,-1,0) = 5 and (0,1,0) = 5 and (#Macro(RightCellAttached)) and ((0,-1,2) != 3  or time <= 200) } % move right

rule : { (1,0,0) } 100 { (-1,0,0) = 5 and (1,0,0) = 5 and (#Macro(NoHorizontalMoveLowerFish)) and ((1,0,2) != 4  or time <= 200) } %move up
rule : { (-1,0,0) } 100 { (1,0,0) = 5 and (-1,0,0) = 5 and ((#Macro(NoHorizontalMoveUpperFish)) and ((#Macro(DownCellAttached)) or (#Macro(HorizontalMoveLowerFish)))) and ((-1,0,2) != 2 or time <= 200) } %move down

%move randomly if alone
rule : { (0,1,0) } 100 { (0,1,1) = 3 and (0,1,0) = 5 and (#Macro(NoFishAroundLeft))} %move left
rule : { (1,0,0) } 100 { (1,0,1) = 2 and (1,0,0) = 5 and (#Macro(NoFishAroundUp))} %move up and collision avoidance
rule : { (0,-1,0) } 100 { (0,-1,1) = 1 and (0,-1,0) = 5 and (#Macro(NoFishAroundRight))} %move right and collision avoidance
rule : { (-1,0,0) } 100 { (-1,0,1) = 4 and (-1,0,0) = 5 and (#Macro(NoFishAroundDown))} %move down and collision avoidance

rule : 0 100 { t } %clear current cell 

[layer2]
%random direction generator
rule : {randInt(3)+1} 100 { t }

[layer3]
%orientation of the fish
rule : { (0,0,-1) } 100 { (0,0,-2) = 5  }
rule : 0 100 { t }

[nothing]
rule : { (0,0,0) } 100 { t }
