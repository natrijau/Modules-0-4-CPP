#include <iostream>
#include <fstream>
#include <string>
/*
	GESTION DE FICHIERS EN CPP

		La directive #include <fstream> en C++ est utilisée pour inclure la bibliothèque standard fstream, 
		qui fournit des fonctionnalités pour les opérations de fichier. 
		Cette bibliothèque contient des classes et des fonctions pour lire et écrire des fichiers.
		Voici un aperçu des principales classes et fonctions fournies par fstream :

	/EXEMPLE D UTILISATION/
	    / Ouvrir un fichier en mode lecture
			std::ifstream inputFile("input.txt");
			if (!inputFile) {
				std::cerr << "Impossible d'ouvrir le fichier d'entrée!" << std::endl;
				return 1;
			}

		/ Lire le contenu du fichier:
			std::string line;
			while (std::getline(inputFile, line)) {
				std::cout << line << std::endl;
			}
			inputFile.close();

		/ Ouvrir un fichier en mode écriture
			std::ofstream outputFile("output.txt");
			if (!outputFile) {
				std::cerr << "Impossible d'ouvrir le fichier de sortie!" << std::endl;
				return 1;
			}

		/ Écrire dans le fichier
		outputFile << "Bonjour, monde!" << std::endl;
		outputFile << "Ceci est un exemple de texte." << std::endl;
		outputFile.close();
*/



int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Nombre d'arguments invalide !" << std::endl;
		return (1);
	}

    std::string fileName = av[1];
    std::string fileNameReplace = fileName  + ".replace";
    std::string s1 = av[2];
    std::string s2 = av[3];


	//Open file a copier
	std::ifstream inputFile(av[1]);
	if (!inputFile) {
		std::cerr << "Impossible d'ouvrir le fichier d'entrée!" << std::endl;
		return (1);
	}

	// new file avec le contenu du file a copier
	std::ofstream outputFile(fileNameReplace.c_str());
	if (!outputFile) {
		std::cerr << "Impossible d'ouvrir le fichier de sortie!" << std::endl;
		return (1);
	}

	if (s1 == s2)
	{
		outputFile << inputFile.rdbuf();
		inputFile.close();
		outputFile.close();
		std::cout << "Two same strings. Copy all file" << std::endl;
		return (0);
	}
	
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t	i = 0 ;
		
		i = line.find(s1, i);
		while (i <= line.length() )
		{
			line.erase(i, s1.length());
			line.insert(i, s2);
			i += s2.length();
			i = line.find(s1, i);
		}	
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (0);
}
