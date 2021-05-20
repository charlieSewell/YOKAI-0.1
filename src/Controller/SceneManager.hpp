
#include <iostream>
#include <map>
//#include "Controller/LuaManager.hpp"
//#include "Controller/LuaTypes.hpp"
#include "Controller/Layer.hpp"

class SceneManager 
{
  public:

    static SceneManager &getInstance();

    void init();
    int addScene(std::shared_ptr<Layer> &scene);
    std::shared_ptr<Layer> getScene(int id);
    void update();
    void draw();

  private:

    SceneManager();

    std::map<int, std::shared_ptr<Layer>> scenes;
    int sceneCount;
    int sceneID;
};
