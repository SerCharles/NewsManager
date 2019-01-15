/*
filename: NFindFiles.h
description: find all files in the place
version: 1.0
date: 11/3/2018
*/


#include <iostream>
#include <windows.h>

#include "NCharString.h"
#include "NChainLink.hpp"
#include "NCharStringLink.hpp"
#include "NFindFiles.h"


NCharStringLink* g_FindAllFilesInput()
{
    HANDLE hFile;
    LPCTSTR lpFileName = L".\\input\\*.html"; //ָ������Ŀ¼���ļ����ͣ�������d�̵���Ƶ�ļ�������"D:\\*.mp3"
    WIN32_FIND_DATA pNextInfo;  //�����õ����ļ���Ϣ��������pNextInfo��;


    NCharStringLink* all_files = new NCharStringLink();
    char c[30] = "input/";
    NCharString* file_model = new NCharString(c, 6);
    hFile = FindFirstFile(lpFileName, &pNextInfo);//��ע���� &pNextInfo , ���� pNextInfo;
    if (hFile == INVALID_HANDLE_VALUE)
    {
        return NULL;
    }
    {
        char file_name[100]={0};
        WideCharToMultiByte(CP_ACP, 0,
                            pNextInfo.cFileName, -1, file_name, 100, NULL, NULL);
        NCharString* answer = file_model->m_Duplicate();
        NCharString* new_name = new NCharString(file_name, strlen(file_name));
        answer->m_PushBackString(new_name);
        delete(new_name);
        all_files->m_PushBack(answer);
    }
    //printf("%s\n", pNextInfo.cFileName);
    while (FindNextFile(hFile, &pNextInfo))
    {
        if (pNextInfo.cFileName[0] == '.')//����.��..
        {
            continue;
        }
        char file_name[100]={0};
        WideCharToMultiByte(CP_ACP, 0,
                            pNextInfo.cFileName, -1, file_name, 100, NULL, NULL);
        NCharString* answer = file_model->m_Duplicate();
        NCharString* new_name = new NCharString(file_name, strlen(file_name));
        answer->m_PushBackString(new_name);
        delete(new_name);
        all_files->m_PushBack(answer);
        //printf("%s\n", pNextInfo.cFileName);
    }

    return all_files;
}

NCharStringLink* g_FindAllFilesOutput()
{
    HANDLE hFile;
    LPCTSTR lpFileName = L".\\output\\*.info"; //ָ������Ŀ¼���ļ����ͣ�������d�̵���Ƶ�ļ�������"D:\\*.mp3"
    WIN32_FIND_DATA pNextInfo;  //�����õ����ļ���Ϣ��������pNextInfo��;


    NCharStringLink* all_files = new NCharStringLink();
    char c[30] = "output/";
    NCharString* file_model = new NCharString(c, 7);
    hFile = FindFirstFile(lpFileName, &pNextInfo);//��ע���� &pNextInfo , ���� pNextInfo;
    if (hFile == INVALID_HANDLE_VALUE)
    {
        return NULL;
    }

    {
        char file_name[100]={0};
        WideCharToMultiByte(CP_ACP, 0,
                            pNextInfo.cFileName, -1, file_name, 100, NULL, NULL);
        NCharString* answer = file_model->m_Duplicate();
        NCharString* new_name = new NCharString(file_name, strlen(file_name));
        answer->m_PushBackString(new_name);
        delete(new_name);
        all_files->m_PushBack(answer);
    }
    //printf("%s\n", pNextInfo.cFileName);
    while (FindNextFile(hFile, &pNextInfo))
    {
        if (pNextInfo.cFileName[0] == '.')//����.��..
        {
            continue;
        }
        char file_name[100]={0};
        WideCharToMultiByte(CP_ACP, 0,
                            pNextInfo.cFileName, -1, file_name, 100, NULL, NULL);
        NCharString* answer = file_model->m_Duplicate();
        NCharString* new_name = new NCharString(file_name, strlen(file_name));
        answer->m_PushBackString(new_name);
        delete(new_name);
        all_files->m_PushBack(answer);
        //printf("%s\n", pNextInfo.cFileName);
    }

    return all_files;
}

NCharStringLink* g_FindAllFilesWord()
{
    HANDLE hFile;
    LPCTSTR lpFileName = L".\\output\\*.txt"; //ָ������Ŀ¼���ļ����ͣ�������d�̵���Ƶ�ļ�������"D:\\*.mp3"
    WIN32_FIND_DATA pNextInfo;  //�����õ����ļ���Ϣ��������pNextInfo��;


    NCharStringLink* all_files = new NCharStringLink();
    char c[30] = "output/";
    NCharString* file_model = new NCharString(c, 7);
    hFile = FindFirstFile(lpFileName, &pNextInfo);//��ע���� &pNextInfo , ���� pNextInfo;
    if (hFile == INVALID_HANDLE_VALUE)
    {
        return NULL;
    }
    {
        char file_name[100]={0};
        WideCharToMultiByte(CP_ACP, 0,
                            pNextInfo.cFileName, -1, file_name, 100, NULL, NULL);
        NCharString* answer = file_model->m_Duplicate();
        NCharString* new_name = new NCharString(file_name, strlen(file_name));
        answer->m_PushBackString(new_name);
        delete(new_name);
        all_files->m_PushBack(answer);
    }
    //printf("%s\n", pNextInfo.cFileName);
    while (FindNextFile(hFile, &pNextInfo))
    {
        if (pNextInfo.cFileName[0] == '.')//����.��..
        {
            continue;
        }
        char file_name[100]={0};
        WideCharToMultiByte(CP_ACP, 0,
                            pNextInfo.cFileName, -1, file_name, 100, NULL, NULL);
        NCharString* answer = file_model->m_Duplicate();
        NCharString* new_name = new NCharString(file_name, strlen(file_name));
        answer->m_PushBackString(new_name);
        delete(new_name);
        all_files->m_PushBack(answer);
        //printf("%s\n", pNextInfo.cFileName);
    }

    return all_files;
}
