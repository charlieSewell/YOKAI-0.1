terrFac = TerrainFactory:getInstance()



--Creating Player Object
playerID = ObjectManager.Create(Types.player(),"");
player = ObjectManager.GetObject(playerID);

player:setPosition(650.0, 200.0, 600.0);
player:setCollider(4, 4, 4.0);


--Creating SkyBox
skyBoxID = ObjectManager.Create(Types.static(),"content/Models/skybox1.fbx");
skyBox = ObjectManager.GetObject(skyBoxID);
skyBox:setPosition(TerrainSettings.terrainSize/2, 0, TerrainSettings.terrainSize/2);
skyBox:setScale(0.05, 0.05, 0.05);

--Creating Rocks in random places
for i=0,200 do
        x = math.random(0,TerrainSettings.terrainSize);
        z = math.random(0,TerrainSettings.terrainSize);
        val = terrFac:getHeight(x,z)
        asset = ObjectManager.Create(Types.static(),"content/Models/rock.fbx");
        gameObj = ObjectManager.GetObject(asset);
        gameObj:setScale(0.02,0.02,0.02);
        gameObj:setPosition(x,val-2,z);
        gameObj:setCollider(3,6,3);

end

--Creating Zombies in random places

--Creating Trees in random places
for i=0,200 do
        x = math.random(0,TerrainSettings.terrainSize);
        z = math.random(0,TerrainSettings.terrainSize);
        val = terrFac:getHeight(x,z)
        asset = ObjectManager.Create(Types.static(),"content/Models/tree.fbx");
        gameObj = ObjectManager.GetObject(asset);
        gameObj:setScale(0.01,0.01,0.01);
        gameObj:setPosition(x,val-1,z);
        gameObj:setCollider(1,20,1);

end
