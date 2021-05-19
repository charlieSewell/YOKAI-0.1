#include "KeyframeAnimation.hpp"

KeyframeAnimation::KeyframeAnimation() 
{
    shader = std::make_unique<Shader>("content/Shaders/vertexShader.vert", "content/Shaders/fragmentShader.frag");
    shader->useShader();
    shader->setVec3("skyColor",glm::vec3(0.05,0.05,0.05));
    shader->setBool("isAnimated",false);
    shader->setVec3("lightColor",glm::vec3(1.0,1.0,1.0));
    shader->setVec3("lightPos",glm::vec3(500,200,500));
    totalTime = 0;
    ticksPerSecond = 30;
    animationFinished = true;
}

void KeyframeAnimation::readFile(std::string textPath) 
{
    std::ifstream file(textPath);
    std::string path;
    if (file) 
    {
        while (std::getline(file, path)) 
        {
            collectModel(path);
        }
    } 
    else 
    {
        std::cout << "Error opening file: " + textPath << std::endl;
    }
}

void KeyframeAnimation::collectModel(std::string modelPath) 
{
    Model model = loader.loadModel(modelPath);
    models.push_back(model);
}

void KeyframeAnimation::setAnimation(std::string name)
{
    currentAnimation = name;
}

std::string KeyframeAnimation::getCurrentAnimation()
{
    return currentAnimation;
}

void KeyframeAnimation::addAnimation(std::string animation, int firstFrame, int lastFrame) 
{
    if (firstFrame < 0) 
    {
        firstFrame = 1;
    }

    if (lastFrame > models.size()) 
    {
        lastFrame = models.size() - 1;
    }

    animations.emplace(animation, std::pair<int, int>(firstFrame, lastFrame));
}

void KeyframeAnimation::setCurrentFrame(double deltaTime) 
{
    totalTime += deltaTime;

    if (totalTime > ((animations.at(currentAnimation).second - animations.at(currentAnimation).first + 1) / ticksPerSecond))
    {
        totalTime = 0;
    }

    swapAnimationCheck(); 
    currentFrame = static_cast<int>(totalTime * ticksPerSecond);
    currentFrame += animations.at(currentAnimation).first - 1;
}

void KeyframeAnimation::swapAnimationCheck() 
{
    if (currentAnimation != tempAnimation) 
    {
        totalTime = 0;
    }

    tempAnimation = currentAnimation;
}

int KeyframeAnimation::getCurrentFrame() 
{
    return currentFrame;
}

int KeyframeAnimation::getEndFrame() 
{
    return animations.at(currentAnimation).second;
}

void KeyframeAnimation::draw() 
{
    glm::mat4 transform(1.0);
    transform = glm::translate(transform, glm::vec3(512, 25, 512));
    transform = glm::scale(transform, glm::vec3(0.03, 0.03, 0.03));

    shader->useShader();
    shader->setVec3("viewPos",GameObjectManager::getInstance().getPlayer()->getPosition());
    models[currentFrame].Draw(*shader, transform);
}

void KeyframeAnimation::setTPS(float tps) 
{
    ticksPerSecond = tps;
}

float KeyframeAnimation::getTPS() 
{
    return ticksPerSecond;
}

bool KeyframeAnimation::getAnimationFinished() 
{
    if (currentFrame == animations.at(currentAnimation).second - 1) 
    {
        animationFinished = true;
    } 
    else 
    {
        animationFinished = false;
    }

    return animationFinished;
}