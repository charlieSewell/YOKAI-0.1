#include "Controller/Yokai.hpp"
#include "Model/SplashScreen.hpp"
int main()
{
	auto& engine = Yokai::getInstance();

    engine.Init();
    engine.Run();
	return 0;
}
