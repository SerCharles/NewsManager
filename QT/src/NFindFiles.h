/*
filename: NFindFiles.h
description: find all files in the place
version: 1.0
date: 11/3/2018
*/

#ifndef NFINDFILES_H
#define NFINDFILES_H

#include <iostream>
#include <windows.h>

#include "NCharString.h"
#include "NChainLink.hpp"
#include "NCharStringLink.hpp"





extern NCharStringLink* g_FindAllFilesInput();
extern NCharStringLink* g_FindAllFilesOutput();
extern NCharStringLink* g_FindAllFilesWord();


#endif

