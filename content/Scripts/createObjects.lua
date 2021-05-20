terrFac = TerrainFactory:getInstance()
objManager = ObjectManager:getInstance()


--Creating Player Object
playerID = objManager:Create(Types.player(),"");
player = objManager:GetPlayer();
player:setPosition(650.0, 200.0, 600.0);
player:setCollider(4, 4, 4.0);
player.movement.movementSpeed = 3500;

playerPos = player:getPosition();

--Creating SkyBox
skyBoxID = objManager:Create(Types.static(),"content/Models/skybox1.fbx");
skyBox = objManager:GetObject(skyBoxID);
skyBox:setPosition(TerrainSettings.terrainSize/2, 0, TerrainSettings.terrainSize/2);
skyBox:setScale(0.05, 0.05, 0.05);

--Creating Rocks in random places
for i=0,200 do
        x = math.random(0,TerrainSettings.terrainSize);
        z = math.random(0,TerrainSettings.terrainSize);
        val = terrFac:getHeight(x,z)
        asset = objManager:Create(Types.static(),"content/Models/rock.fbx");
        gameObj = objManager:GetObject(asset);
        gameObj:setScale(0.02,0.02,0.02);
        gameObj:setPosition(x,val-2,z);
        gameObj:setCollider(3,4,3);

end

--Creating Zombies in random places
numZombies = 50;
spawnRange = 300;
for i=0, numZombies do
        x = math.random(playerPos.x - spawnRange, playerPos.x + spawnRange);
        z = math.random(playerPos.z - spawnRange, playerPos.z + spawnRange);
        val = terrFac:getHeight(x,z)
        asset = objManager:Create(Types.npc(),"content/Models/Zombie/ZombieSmooth.gltf");
        gameObj = objManager:GetObject(asset);
        gameObj:setScale(0.5,0.5,0.5);
        gameObj:setPosition(x,val,z);
        gameObj:setCollider(1,4,1);
end

--Creating Trees in random places
for i=0,200 do
        x = math.random(0,TerrainSettings.terrainSize);
        z = math.random(0,TerrainSettings.terrainSize);
        val = terrFac:getHeight(x,z)
        asset = objManager.Create(Types.static(),"content/Models/tree.fbx");
        gameObj = objManager.GetObject(asset);
        gameObj:setScale(0.01,0.01,0.01);
        gameObj:setPosition(x,val-1,z);
        gameObj:setCollider(1,20,1);
end
