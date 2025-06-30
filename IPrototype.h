#pragma once
#include <memory>

class Entity;

// �v���g�^�C�v�̃C���^�[�t�F�[�X
class IPrototype
{
public:
    virtual ~IPrototype() = default;

    // �G���e�B�e�B�̃N���[����Ԃ�
    virtual std::shared_ptr<Entity> Clone() const = 0;
};
