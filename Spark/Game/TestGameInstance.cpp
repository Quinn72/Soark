#include "TestGameInstance.h"

#include <iostream>

#include "LevelNames.h"
#include "TestLevel.h"
#include "Spark/Level/LevelManager.h"


void TestGameInstance::BeginPlay()
{
	std::cout << "Begin Play! \n";
	if(LevelManager* levelmanager = GetLevelManager())
	{
		levelmanager->AddLevel(new TestLevel);
		levelmanager->OpenLevel(TEST_LEVEL);

	}
}

void TestGameInstance::EndPlay()
{
	std::cout << "End Play! \n";
}
