// BulletPrototype.h
#pragma once
#include "IPrototype.h"
#include "DXLib.h"
#include <memory>

class BulletPrototype : public IPrototype {
public:
    BulletPrototype(VECTOR basePosition);
    std::shared_ptr<Entity> Clone() const override; // 戻り値の型を変更

private:
    VECTOR m_basePosition;
};

//#pragma once
//
//#include "IPrototype.h"
//#include "BulletEntity.h"
//#include <memory>
//
//class BulletPrototype : public IPrototype
//{
//public:
//    BulletPrototype(int modelHandle, VECTOR spawnOffset);
//
//    std::shared_ptr<Entity> Clone() const override;
//
//private:
//    int m_modelHandle;
//    VECTOR m_spawnOffset;
//};

