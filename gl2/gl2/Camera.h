#pragma once

#ifndef CAMERA_H_
#define CAMERA_H_

#endif // !CAMERA_H_

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp);
	Camera(glm::vec3 position, glm::vec3 worldUp, float pitch, float yaw);
	~Camera();

	//返回摄像机4维矩阵
	inline glm::mat4 getViewMatrix() { return glm::lookAt(position_, position_ + front_, up_); };
	//改变方向
	void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
	//移动
	inline void moveFront() { position_ += front_ * movementSpeed_; }
	inline void moveLast()  { position_ -= front_ * movementSpeed_; }
	inline void moveLeft()  { position_ += right_ * movementSpeed_; }
	inline void moveRight() { position_ -= right_ * movementSpeed_; }

private:
	//根据欧拉角计算前方向向量
	void updateCameraVectors();

private:
	//camera属性
	glm::vec3 position_;
	glm::vec3 front_;      
	glm::vec3 up_; 
	glm::vec3 right_;
	glm::vec3 worldUp_;
	//欧拉角
	float yaw_;
	float pitch_;
	//摄像机速度选项
	float movementSpeed_ = 0.005;
	float mouseSensitivity_ = 0.01;
	float zoom_;
};

