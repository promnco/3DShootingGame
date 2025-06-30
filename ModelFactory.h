#pragma once
#include <DxLib.h>
#include <string>            // std::string ���g�p���邽�߂̃w�b�_�[�t�@�C��
#include <unordered_map>     // std::unordered_map ���g�p���邽�߂̃w�b�_�[�t�@�C��
#include <tchar.h>           // _T �}�N�����g�p���邽�߂̃w�b�_�[�t�@�C��

// ���f���̓ǂݍ��݂ƃL���b�V�����Ǘ�����N���X
// ���f�����i������j���L�[�Ƃ��āA���f���̃n���h���iID�j��Ԃ�
// �V���O���g���p�^�[�����g�p���āA�A�v���P�[�V�����S�̂ň�ӂ̃C���X�^���X���
class ModelFactory
{
private:
    // ���f�������L�[�A���f���n���h����l�Ƃ��Ċi�[����n�b�V���}�b�v
    std::unordered_map<std::string, int> m_models;

    // �R���X�g���N�^�ƃf�X�g���N�^�̓v���C�x�[�g�ɂ��邱�ƂŁA�O������C���X�^���X���쐬�ł��Ȃ��悤�ɂ���
    // �V���O���g���C���X�^���X���擾���邽�߂̐ÓI���\�b�h���

    // �R���X�g���N�^
    ModelFactory() = default;
	// �f�X�g���N�^
    ~ModelFactory();

    // �R�s�[�R���X�g���N�^�Ƒ�����Z�q���폜���āA�C���X�^���X�̃R�s�[��h��
    ModelFactory(const ModelFactory&) = delete;
    ModelFactory& operator=(const ModelFactory&) = delete;

public:
    // �V���O���g���p�^�[�����g�p���āA�C���X�^���X�ւ̃A�N�Z�X���
    // �V���O���g���p�^�[�����g�p���Ă��闝�R�́A
	// ���f���Ƃ������\�[�X�͒ʏ�A�A�v���P�[�V�����S�̂ň�ӂł���A
	// �����̃C���X�^���X���쐬����K�v���Ȃ�����
    static ModelFactory& Instance();

    // ���f���𖼑O�Ŏ擾����
    int GetModel(const std::string& name);

    // ���ׂẴ��f�����������
    void Clear();
};
