#include "stdafx.h"
#include "Item.h"
#include <sstream>

//=================================================================
//
//  Class: Item
//
//=================================================================

Item::Item(string paraItemNumber, string paraQuan, string paraItemName , double paraWeight){
	itemNumber = paraItemNumber;
	quantity = paraQuan;
	itemName = paraItemName;
//	local = paraLocal;
	weight = paraWeight;
}
Item::Item(string paraItemNumber, string paraQuan, string paraItemName, Location paraLocal, double paraWeight){
	itemNumber = paraItemNumber;
	quantity = paraQuan;
	itemName = paraItemName;
	local = paraLocal;
	weight = paraWeight;
}
ostream& operator<<(ostream& co, const Item paraItem)
{
    co << "//=== Printing Item ========================================\n"
		<< "Item Name: " << paraItem.itemName << '\n'
		<< "Item Quantity: " << paraItem.quantity << '\n'
		<< "Item weight: " << paraItem.weight << '\n'
		<< "Item Localtion: " << paraItem.local << '\n';
	return co;
}