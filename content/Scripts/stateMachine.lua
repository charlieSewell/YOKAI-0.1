objManager = ObjectManager:getInstance()

--States
wander		= 0
seek		= 1
attack		= 2
dead		= 3

function update(obj)
		
	stateMachine(obj)

end

function stateMachine(obj)
	--target = ObjectManager.GetPlayer();
	--targetPosition = target:getPosition();
	--target = ObjectManager.GetPlayer();
	--target:setPosition(650.0, 800.0, 600.0);
	if(obj.behaviours.state == wander)
	then
		obj.animator:setAnimation("ZombieWalk")
		obj.behaviours:wander();
		obj.behaviours:accelerate(0.015);
		
		--test = ObjectManager.distance(player:getPosition(), obj:getPosition())

		if(objManager:distance(player:getPosition(), obj:getPosition()) < 30)
		then
			obj.behaviours.state = seek
		end
	elseif(obj.behaviours.state == seek)
	then
		obj.animator:setAnimation("ZombieRun")
		obj.behaviours:seek(player:getPosition());
		obj.behaviours:accelerate(0.115);
		obj.behaviours.rotationSpeed = 0.05;

		if(objManager:distance(player:getPosition(), obj:getPosition()) < 5)
		then
			obj.behaviours.state = attack
		end
	elseif(obj.behaviours.state == attack)
	then
		obj.animator:setAnimation("ZombieBite")
		--obj.behaviours:seek(player:getPosition());
		--obj.behaviours:accelerate(0.0);
		obj.behaviours.rotationSpeed = 0.05;

		if(objManager:distance(player:getPosition(), obj:getPosition()) > 5)
		then
			obj.behaviours.state = seek
		end
	end
end