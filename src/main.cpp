#include "Controller/Yokai.hpp"
#include "Model/ObjectLoading/ModelLoader.hpp"
int main()
{
	auto& engine = Yokai::getInstance();
	engine.Init();
    engine.Run();
	return 0;
}
