# include <iostream>
# include <string>

int main() {
	std::string weapon;
	std::cout << "Type a weapon: ";
	std::cin >> weapon;
	if (weapon == "knife") {
		std::cout << "*shank*" << std::endl;
	} else if (weapon == "pistol") {
		std::cout << "*pew pew*" << std::endl;
	} else if (weapon == "rpg") {
                std::cout << "*beeeeeewwwwwwww*" << std::endl << "*BOOOOMM*" << std::endl;
	} else if (weapon == "sniper") {
                std::cout << "*You hear the faint sound of a silencer in the distance*" << std::endl << "*And then Jasper's head explodes*" << std::endl;
	} else if (weapon == "katana") {
                std::cout << "And from that day on, there were two jaspers" << std::endl;
	} else if (weapon == "lead-pipe") {
                std::cout << "The lights go out..." << std::endl << "*PING*" << std::endl << "The lights come back on, and jasper is dead" << std::endl;
        } else if (weapon == "nuke") {
                std::cout << "All you hear are the radiation sirens coming from above... *BBBBBOOOOOOMMMMM* right on jasper..." << std::endl;
	} else {
		std::cout << "Please re-run the script and choose a weapon" << std::endl;
	}
	return 0;
}
