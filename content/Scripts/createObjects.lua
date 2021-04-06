terrFac = TerrainFactory:getInstance()
for i=0,30 do
        x = math.random(0,TerrainSettings.terrainSize);
        z = math.random(0,TerrainSettings.terrainSize);
        val = terrFac:getHeight(x,z)
        asset = ObjectManager.Create(Types.static(),"content/Models/rock.fbx");
        gameObj = ObjectManager.GetObject(asset);
        gameObj:setScale(0.02,0.02,0.02);
        gameObj:setPosition(x,val-2,z);
        gameObj:setCollider(6,6,15);
end
for i=0,30 do
        x = math.random(0,TerrainSettings.terrainSize);
        z = math.random(0,TerrainSettings.terrainSize);
        val = terrFac:getHeight(x,z)
        asset = ObjectManager.Create(Types.static(),"content/Models/zombie.fbx");
        gameObj = ObjectManager.GetObject(asset);
        gameObj:setScale(0.003,0.003,0.003);
        gameObj:setCollider(4,1,25);
        gameObj:setPosition(x,val,z);
end
for i=0,30 do
        x = math.random(0,TerrainSettings.terrainSize);
        z = math.random(0,TerrainSettings.terrainSize);
        val = terrFac:getHeight(x,z)
        asset = ObjectManager.Create(Types.static(),"content/Models/tree.fbx");
        gameObj = ObjectManager.GetObject(asset);
        gameObj:setScale(0.01,0.01,0.01);
        gameObj:setCollider(1,1,50);
        gameObj:setPosition(x,val,z);
end
