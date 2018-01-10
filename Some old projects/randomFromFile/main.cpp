#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main()
{
    std::cout << "Program Starting..." << std::endl;

    std::ifstream file("input.txt");
    std::string line;
    std::vector<std::string> lines;

    while(std::getline(file,line)){
        //std::cout << line << std::endl;
        lines.push_back(line);
    }
	
	int numOfReturns = 7;
	int listSize = lines.size();
	srand(time(NULL));
	int randomNum = 0;
	
	for(int i=0; i<numOfReturns; i++){
		randomNum = rand() % listSize;
		std::cout << lines[randomNum] << std::endl;
	}

	/* For printing file contents (testing purposes)
    for (unsigned n=0; n < lines.size(); ++n) {
        std::cout << lines.at(n) << " ";
    }
	*/

    std::cout << "Program Finished..." << std::endl;
    return 0;
}
