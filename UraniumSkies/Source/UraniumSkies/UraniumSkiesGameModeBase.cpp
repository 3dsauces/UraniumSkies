// Fill out your copyright notice in the Description page of Project Settings.

#include "UraniumSkies.h"
#include "CharacterBaseClass.h"
#include "UraniumSkiesGameModeBase.h"

AUraniumSkiesGameModeBase::AUraniumSkiesGameModeBase()
{
	DefaultPawnClass = ACharacterBaseClass::StaticClass();
}

