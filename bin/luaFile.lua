
function init()
	print("INIT")
	SubscribeEvent("KeyDown")
end

local r, g, b = 1,1,1
function update(delta)
	local x, y = GetMousePos()

	if (IsMousePressed("left")) then
		r = r - 10*delta
	elseif (IsMousePressed("right")) then
		r = r + 10*delta
	elseif (IsMousePressed("middle")) then
		print(1.0/delta)
	end

	if(IsKeyPressed("Left")) then
		MoveCamera(0,0,-delta*10)
	end
	if(IsKeyPressed("Right")) then
		MoveCamera(0,0,delta*10)
	end
	if(IsKeyPressed("Up")) then
		MoveCamera(0, delta*10, 0)
	end
	if(IsKeyPressed("Down")) then
		MoveCamera(0, -delta*10, 0)
	end

	if(IsKeyPressed("B")) then
		SubscribeEvent("KeyDown")
	end
	if(HasComponent("MeshComponent")) then
		local comp = GetComponent("MeshComponent")
		SetComponentValue(comp, "color", r, g, b)
	end
	if(HasComponent("MeshComponent") and IsKeyPressed("L")) then
		local comp = GetComponent("MeshComponent")

		SetComponentValue(comp, "color", 1, 1, 1)


	end

end

function events(eventName, ...)
	if(eventName == "KeyDown") then
		local keyName, keyRepeat = ...

		if(keyName == "H" and not keyRepeat) then
			print("UNSUBSCRIBE")
			UnsubscribeEvent("KeyDown")
		elseif(keyName == "R" and not keyRepeat) then
			RemoveComponent("LuaComponent")
		end
	end
end
