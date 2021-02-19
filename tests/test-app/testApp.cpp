#include <iostream>
#include <SMLib/Video.h>

using namespace sml::video;

int main(int argc, char* argv[])
{
	const MultiDisplay* Inst = MultiDisplay::GetMultiDisplays();

	//const Display primaryDisp = Inst->GetDisplayRef(0);
	std::cout << Inst << std::endl;
	std::cin.get();
	const MultiDisplay* Inst2 = MultiDisplay::GetMultiDisplays();
	std::cout << Inst2 << std::endl;
	std::cin.get();
	return 0;
}