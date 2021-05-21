uiManager = UIManager:getInstance();

ammoOne = uiManager:add("ammoOne", "content/Textures/3.png");
uiManager:setUpPanel(ammoOne, 1700, 1750, 800, 900);

ammoTwo = uiManager:add("ammoTwo", "content/Textures/0.png");
uiManager:setUpPanel(ammoTwo, 1750, 1800, 800, 900);

reserveOne = uiManager:add("reserveOne", "content/Textures/1.png");
uiManager:setUpPanel(reserveOne, 1750, 1800, 900, 1000);

reserveTwo = uiManager:add("reserveTwo", "content/Textures/5.png");
uiManager:setUpPanel(reserveTwo, 1800, 1850, 900, 1000);

reserveThree = uiManager:add("reserveThree", "content/Textures/0.png");
uiManager:setUpPanel(reserveThree, 1850, 1900, 900, 1000);

healthBar = uiManager:add("health", "content/Textures/health.jpg");
uiManager:setUpPanel(healthBar, 50, 700, 950, 1000);

shieldBar = uiManager:add("shields", "content/Textures/shield.png");
uiManager:setUpPanel(shieldBar, 50, 700, 875, 925);

--helpMenu = uiManager:add("helpMenu", "content/Textures/help_menu.png");
--uiManager:setUpPanel(helpMenu, 200, 1500, 200, 900);