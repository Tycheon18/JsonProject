// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATestActor::ParsingJson()
{
	FString FileStr;
	FString FilePath = TEXT("test.json");
	FFileHelper::LoadFileToString(FileStr, *FilePath);

	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(FileStr);
	TSharedPtr<FJsonObject> JsonObj = MakeShareable(new FJsonObject());

	if (FJsonSerializer::Deserialize(JsonReader, JsonObj) && JsonObj.IsValid())
	{
		FString CharName;
		JsonObj->TryGetStringField(TEXT("Name"), CharName);

		int32 Level;
		JsonObj->TryGetNumberField(TEXT("Level"), Level);

		int32 Attack;
		JsonObj->TryGetNumberField(TEXT("Attack"), Attack);

		int32 Health;
		JsonObj->TryGetNumberField(TEXT("Health"), Health);
	}
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

