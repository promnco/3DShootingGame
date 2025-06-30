#include "ModelFactory.h"
#include <tchar.h>

// �V���O���g���p�^�[�����g�p���āAModelFactory �N���X�̃C���X�^���X�ɃA�N�Z�X����
ModelFactory& ModelFactory::Instance()
{
    // static �ϐ� instance ���g�p���āA�B��̃C���X�^���X�𐶐��i�ŏ��̌Ăяo�����̂݁j
    static ModelFactory instance;
    return instance;
}

// �w�肳�ꂽ���O�̃��f�����擾����
int ModelFactory::GetModel(const std::string& name)
{
    // ���f���������łɃL���b�V������Ă��邩�m�F
    auto it = m_models.find(name);
    if (it != m_models.end())
    {
        // �L���b�V������Ă���ꍇ�́A���̃n���h���iID�j��Ԃ�
        return it->second;
    }

    // �L���b�V������Ă��Ȃ��ꍇ�A���f�������[�h���ăL���b�V���ɒǉ�
    // std::string �� std::wstring �ɕϊ����� TCHAR* �ɑΉ�������
    std::wstring wname(name.begin(), name.end());
    // ���f����ǂݍ��݁A�n���h���iID�j���擾
    int handle = MV1LoadModel(wname.c_str());
    // ���f�����Ƃ��̃n���h�����L���b�V���ɕۑ�
    m_models[name] = handle;
    return handle;
}

// ���ׂẴL���b�V�����ꂽ���f�������
void ModelFactory::Clear()
{
    // models �̊e�G���g���i���f�����ƃ��f���n���h���j�ɑ΂���
    for (const auto& pair : m_models)
    {
        // �e���f���̉��
        MV1DeleteModel(pair.second);
    }
    // �L���b�V�����N���A
    m_models.clear();
}

// �f�X�g���N�^
ModelFactory::~ModelFactory()
{
    Clear();
}