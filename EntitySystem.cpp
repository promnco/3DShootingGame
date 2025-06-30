#include "EntitySystem.h"


void EntitySystem::AddEntity(std::shared_ptr<Entity> entity)
{
    // �G���e�B�e�B���X�g�ɐV�����G���e�B�e�B��ǉ�
    m_entities.push_back(entity);
}

void EntitySystem::Update()
{
    // �G���e�B�e�B���X�g���̂��ׂẴG���e�B�e�B�ɑ΂��čX�V���������s
    for (auto& entity : m_entities)
    {
        if (entity->active)
        {
            // active �t���O�� true �̃G���e�B�e�B�̂ݍX�V
            entity->Update();
        }
    }
}

void EntitySystem::Draw()
{
    // �G���e�B�e�B���X�g���̂��ׂẴG���e�B�e�B�ɑ΂��ĕ`�揈�������s
    for (auto& entity : m_entities)
    {
        if (entity->active)
        {
            // active �t���O�� true �̃G���e�B�e�B�̂ݕ`��
            entity->Draw();
        }
    }
}