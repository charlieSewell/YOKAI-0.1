function update(obj)
		
	stateMachine(obj)

end

--States
wander		= 0
seek		= 1
attack		= 2
dead		= 3

function stateMachine(obj)
	--target = ObjectManager.GetPlayer();
	--targetPosition = target:getPosition();
	--target = ObjectManager.GetPlayer();
	--target:setPosition(650.0, 800.0, 600.0);
	if(obj.behaviours.state == wander)
	then
		obj.behaviours:wander();
		obj.behaviours:accelerate(0.015);
		
		test = ObjectManager.distance(player:getPosition(), obj:getPosition())

		if(test < 10)
		then
			obj.behaviours.state = seek
		end
	end

	if(obj.behaviours.state == seek)
	then
		obj.behaviours:seek(player:getPosition());
		obj.behaviours:accelerate(0.115);
		obj.behaviours.rotationSpeed = 0.05;
	end
end
