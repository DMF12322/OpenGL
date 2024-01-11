#include "Camera.h"


Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldup)
{
	Position = position;
	Worldup = worldup;
	Forward = glm::normalize(target - position); //normalize归一化处理
	Right = glm::normalize(glm::cross(Forward, Worldup));//cross叉乘
	Up = glm::normalize(glm::cross(Forward, Right));
}

Camera::Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldup)
{
	Position = position;
	Worldup = worldup;
	Pitch = pitch;
	Yaw = yaw;
	Forward.x = glm::cos(Pitch) * glm::sin(Yaw);
	Forward.y = glm::sin(Pitch);
	Forward.z = glm::cos(Pitch) * glm::cos(Yaw);
	Right = glm::normalize(glm::cross(Forward, Worldup));//cross叉乘
	Up = glm::normalize(glm::cross(Forward, Right));
}


Camera::~Camera()
{
}

glm::mat4 Camera::GetViewMatrix() {
	return  glm::lookAt(Position, Position + Forward, Worldup);//当前位置，摄像机位置，世界坐标向上的向量
}

void Camera::UpdateCameraVectors()
{
	Forward.x = glm::cos(Pitch) * glm::sin(Yaw);
	Forward.y = glm::sin(Pitch);
	Forward.z = glm::cos(Pitch) * glm::cos(Yaw);
	Right = glm::normalize(glm::cross(Forward, Worldup));//cross叉乘
	Up = glm::normalize(glm::cross(Forward, Right));
}


void Camera::ProcessMouseMovement(float deltaX, float deltaY)
{
	Pitch -= deltaY * SenseY;
	Yaw -= deltaX * SenseX;
	UpdateCameraVectors();
}

void Camera::UpdateCameraPos()
{
	Position += Forward * speedZ * 0.1f;
}
