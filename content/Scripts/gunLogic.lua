--if ((player.gun.ammo == 0) and (player.gun.reserveAmmo == 0))
--then
--	player.gun.gunAnimation.ticksPerSecond = 20;
--	player.gun.gunAnimation:setCurrentAnimation("idle");
--elseif (player.gun.ammo == 0)
--then
--	player.gun.gunAnimation.ticksPerSecond = 30;
--	player.gun.gunAnimation:setCurrentAnimation("emptyreload");
--	player.gun:reload;
--end

--player.gun.gunAnimation:checkAnimationFinished();

if(player.gun:getIsFiring())
then
    if (player.gun.ammo ~= 0)
    then
        if (player.gun.gunAnimation:getCurrentAnimation() == "idle")
        then
            player.gun.gunAnimation.ticksPerSecond = 30;
            player.gun.gunAnimation:setCurrentAnimation("fire");
            player.gun:decrementAmmo();
        elseif (player.gun.gunAnimation:getAnimationFinished())
        then
            player.gun.gunAnimation.ticksPerSecond = 30;
            player.gun.gunAnimation:setCurrentAnimation("fire");
            player.gun:decrementAmmo();
        end
    end
end
        
player.gun.gunAnimation:checkAnimationFinished();

if (player.gun.gunAnimation:getAnimationFinished())
then
	player.gun.gunAnimation.ticksPerSecond = 20;
	player.gun.gunAnimation:setCurrentAnimation("idle");
end