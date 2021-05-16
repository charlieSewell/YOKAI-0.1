#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>

class Transform
{
public:
	Transform();
	Transform(glm::vec3 scale, glm::quat rotation,glm::vec3 position);
	Transform(const Transform &other);

	void translate(glm::vec3 translation);
	void translate(float x, float y, float z);
	void translatePostMultiply(glm::vec3 translation);
	void translatePostMultiply(float x, float y, float z);
	void rotate(float angle, glm::vec3 upVector);
	void scale(glm::vec3 scale);
	void scale(float x, float y, float z);
	void scale(float scale);

	glm::vec3 getScale();
	glm::quat getRotation();
	glm::vec3 getPosition();
	glm::mat4 getMatrix();

	void setScale(glm::vec3 scale);
	void setScale(float x, float y, float z);
	void setScale(float scale);

	void setRotation(glm::quat rotation);

	void setPosition(glm::vec3 position);
	void setPosition(float x, float y, float z);

	Transform& operator=(const Transform &other);

private:
	glm::mat4 m_transform;

	glm::vec3 m_scale;
	glm::quat m_rotation;
	glm::vec3 m_position;
	glm::vec3 m_skew;
	glm::vec4 m_perspective;

	void decompose();
	void recompose();
};