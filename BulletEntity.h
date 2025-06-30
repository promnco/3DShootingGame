#pragma once

#include "Entity.h"
#include "TransformComponent.h"
#include <memory>

// �e�G���e�B�e�B�F���̂ŕ`�悳���
class BulletEntity : public Entity
{
public:
    BulletEntity();

    void Update() override;
    void Draw() override;

    std::shared_ptr<TransformComponent> transform;
};

//#pragma once
//
//#include "Entity.h"
//#include "TransformComponent.h"
//#include <memory>
//
//// �e�G���e�B�e�B�i�v���C���[�E�G���p�j
//class BulletEntity : public Entity
//{
//public:
//    BulletEntity(int modelHandle);
//
//    std::shared_ptr<TransformComponent> transform;
//
//    void Update() override;
//
//private:
//    int m_modelHandle; // ���f���̕`��p�n���h��
//};
