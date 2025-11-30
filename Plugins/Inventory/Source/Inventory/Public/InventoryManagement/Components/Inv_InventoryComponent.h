#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inv_InventoryComponent.generated.h"


class UInv_InventoryBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORY_API UInv_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInv_InventoryComponent();
	void ToggleInventoryMenu();

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY()
	TWeakObjectPtr<APlayerController> OwningController;
	
	void ConstructInventory();

	UPROPERTY()
	TObjectPtr<UInv_InventoryBase> InventoryMenu;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UInv_InventoryBase> InventoryMenuClass;

	bool bIsInventoryMenuOpen;
	void OpenInventoryMenu();
	void CloseInventoryMenu();
};
