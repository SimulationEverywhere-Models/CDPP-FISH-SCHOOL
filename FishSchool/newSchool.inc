%Macro evaluating if any of the surrounding cells are attached to a group of fish
#BeginMacro(Attached)
((0,1,0)=5) or ((0,-1,0)=5) or ((1,0,0)=5) or ((-1,0,0)=5) 
#EndMacro

%Macro evaluating to see if the right cell is not attached
#BeginMacro(FarRightCellNotAttached)
((0,2,0) = 5) and ((1,2,0) != 5) and ((-1,2,0) != 5) and ((0,3,0) != 5)
#EndMacro

%Macro evaluating if the fish below can make a horizontal move
#BeginMacro(HorizontalMoveLowerFish)
((1,-2,0) = 5) or ((1,2,0) = 5)
#EndMacro

%Macro evaluating if no horizontal move is possible
#BeginMacro(NoHorizontalMove)
((0,-2,0) != 5) and ((0,2,0) != 5)
#EndMacro

%Macro evaluating if no horizontal move is possible for its lower cell
#BeginMacro(NoHorizontalMoveLowerFish)
((2,-2,0) != 5)and ((2,2,0) != 5)
#EndMacro

%Macro evaluating if the lower fish is not attached
#BeginMacro(LowerFishNotAttached)
((2,1,0) != 5) and ((2,-1,0) != 5) and ((3,0,0) != 5)
#EndMacro



%Macro evaluating if no horizontal move is possible for its upper cell
#BeginMacro(NoHorizontalMoveUpperFish)
((-2,-2,0) != 5) and ((-2,2,0) != 5)
#EndMacro

%Macro evaluating if there is no fish around so that it can move left
#BeginMacro(NoFishAroundLeft)
((2,1,0) != 5) and ((-2,1,0) != 5) and ((0,-1,0) != 5) and ((0,3,0) != 5) and ((1,1,0) != 5) and ((-1,1,0) != 5) and ((0,2,0) != 5)
#EndMacro

%Macro evaluating if there is no fish around so that it can move up
#BeginMacro(NoFishAroundUp)
((1,-2,0) != 5) and ((1,2,0) != 5) and ((-1,0,0) != 5) and ((3,0,0) != 5) and ((1,-1,0) != 5) and ((1,1,0) != 5) and ((2,0,0) != 5)
#EndMacro

%Macro evaluating if there is no fish around so that it can move right
#BeginMacro(NoFishAroundRight)
((-2,-1,0) != 5) and ((2,-1,0) != 5) and ((0,1,0) != 5) and ((0,-3,0) != 5) and ((-1,-1,0) != 5) and ((1,-1,0) != 5) and ((0,-2,0) != 5)
#EndMacro

%Macro evaluating if there is no fish around so that it can move down
#BeginMacro(NoFishAroundDown)
((-1,2,0) != 5) and ((-1,-2,0) != 5) and ((1,0,0) != 5) and ((-3,0,0) != 5) and ((-1,1,0) != 5) and ((-1,-1,0) != 5) and ((-2,0,0) != 5)
#EndMacro

%Macro evaluating if its right cell is not attached and can move
#BeginMacro(RightCellNotAttached)
((0,1,0) = 5) and ((1,1,0) != 5) and ((-1,1,0) != 5) and ((0,2,0) != 5)
#EndMacro

%Macro evaluating if its right cell is attached and can not move
#BeginMacro(RightCellAttached)
((-1,1,0) = 5) or ((1,1,0) = 5) or ((0,2,0) = 5)  
#EndMacro

%Macro checking to see if its lower cell is already in a school
#BeginMacro(DownCellAttached)
((1,1,0) = 5) or ((1,-1,0) = 5) or ((2,0,0) = 5)  
#EndMacro

%Macro avoiding collision if a fish ties to go left and a fish tries to go down - priority is given to horizontal moving fish
#BeginMacro(UpperCellDontMove)
((1,0,0) = 5) and (((1,1,0) = 5) or ((1,-1,0) = 5))
#EndMacro

%Macro avoiding collision if a fish ties to go left and a fish tries to go up - priority is given to horizontal moving fish
#BeginMacro(LowerCellDontMove)
((-2,0,0) = 5) and ((-1,1,0) = 5) and ((-1,-1,0) = 5)
#EndMacro

%Macro checking to see if the fish in the upper row are not in a fish school already
#BeginMacro(UpperRowNotAttached)
((((-1,1,0) = 5) and (((-2,1,0) = 5) or ((0,1,0) = 5) or (-1,2,0) = 5))) or ((((-1,-1,0) = 5) and (((-2,-1,0) = 5) or ((0,-1,0) = 5) or (-1,-2,0) = 5)))
#EndMacro

%Macro checking to see if the fish can move vertically or if they are already in a school
#BeginMacro(VerticalAttached)
((((-1,0,0) = 5) and (((-1,1,0) = 5) or ((-1,-1,0) = 5) or ((-2,0,0) = 5))) and (((1,0,0) = 5) and (((1,1,0) = 5) or ((1,-1,0) = 5) or ((2,0,0) = 5)))) 
#EndMacro

%Macro checking to see if the fish can move horizontally or if they are already in a school
#BeginMacro(HorizontalAttached)
((((0,-1,0) = 5) and (((1,-1,0) = 5) or ((-1,-1,0) = 5) or ((0,-2,0) = 5))) and (((0,1,0) = 5) and (((1,1,0) = 5) or ((-1,1,0) = 5) or ((0,2,0) = 5))))
#EndMacro
