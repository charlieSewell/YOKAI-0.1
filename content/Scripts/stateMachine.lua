objManager = ObjectManager:getInstance()

--States
dead		= 0
wander		= 1
seek		= 2
attack		= 3
hit			= 4

function update(obj)
		
	stateMachine(obj)
end

function stateMachine(obj)
	if(obj.hit == true and obj.behaviours.state ~= dead)
	then
		obj.animator:setAnimation("ZombieBite")
		obj.behaviours.acceleration = -0.015;
		obj.health = obj.health - 10;
		obj.hit = false
		obj.behaviours.state = seek;
	elseif(obj.health < 10)
	then
		obj.animator:setAnimation("ZombieCrawl")
		obj.obj.behaviours:accelerate(0.005);
		if(obj.health < 0)
		then
			obj.behaviours.state = dead
		end
	elseif(obj.behaviours.state == wander)
	then
		obj.animator:setAnimation("ZombieWalk");
		obj.behaviours:wander();
		obj.behaviours:accelerate(0.015);

		if(objManager:distance(player:getPosition(), obj:getPosition()) < 30 or obj.behaviours.active == true)
		then
			obj.behaviours.state = seek
		end

	elseif(obj.behaviours.state == seek)
	then
		obj.animator:setAnimation("ZombieRun")
		obj.behaviours:seek(player:getPosition());
		obj.behaviours:accelerate(0.115);
		obj.behaviours.rotationSpeed = 0.075;

		if(objManager:distance(player:getPosition(), obj:getPosition()) < 5)
		then
			obj.behaviours.state = attack
		end
	elseif(obj.behaviours.state == attack)
	then
		obj.animator:setAnimation("ZombieBite")
		obj.behaviours.rotationSpeed = 0.05;

		if(objManager:distance(player:getPosition(), obj:getPosition()) > 5)
		then
			obj.behaviours.state = seek
		end
	end
end