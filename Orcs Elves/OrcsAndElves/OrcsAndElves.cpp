#include <iostream>

#include "Decorators.h"

int main()
{
	//NPC's
	auto elfSoldierFarmer = NPC("ElfSoldierWarrior");
	auto orcFarmerShaman = NPC("OrcShamanFarmer");
	auto genericNPC = NPC("Generic NPC");
	auto joblessNPC = NPC("JoblessNPC");

	//Predefined Decorators
	auto farmerDecorator = FarmerDecorator();
	auto elfDecorator = ElfDecorator();
	auto orcDecorator = OrcDecorator();
	auto shamanDecorator = ShamanDecorator();
	auto soldierDecorator = SoldierDecorator();

	//Custom type | job
	auto genericDecoratorJob = GenericDecorator("Generic Job", true);
	auto genericDecorator = GenericDecorator("Generic Type", false);

	//Decorating NPC's
	elfDecorator.Decorate(elfSoldierFarmer);
	soldierDecorator.Decorate(elfSoldierFarmer);
	farmerDecorator.Decorate(elfSoldierFarmer);

	orcDecorator.Decorate(orcFarmerShaman);
	farmerDecorator.Decorate(orcFarmerShaman);
	shamanDecorator.Decorate(orcFarmerShaman);

	genericDecorator.Decorate(genericNPC);
	genericDecoratorJob.Decorate(genericNPC);

	genericDecorator.Decorate(joblessNPC);

	//Render NPC's
	genericNPC.Render();

	orcFarmerShaman.Render();

	elfSoldierFarmer.Render();

	joblessNPC.Render();
}