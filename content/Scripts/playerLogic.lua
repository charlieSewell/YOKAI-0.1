
velocity = player.physics:getVelocity();
if(velocity.y < -10 and velocity.y < player.physics:getMaxVelocity()) then
    player.physics:setMaxVelocity(velocity.y);
end
if(player.onGround) then
    player.health = player.health + (player.physics:getMaxVelocity() * 2);
    player.physics:setMaxVelocity(0);
end