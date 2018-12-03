#include <iostream>
#include <string>
#include <optional>
#include <algorithm>

const int MULTIPLY = 37;

//either optional uint or optional nullopt / this is a copy 			this is not 
std::optional<uint64_t> to_hash(std::string String_to_hash, const std::string_view letters){

	uint64_t result = 7;
	char to_find;
	size_t index_of_letters, i = 0;
	while (i < String_to_hash.length()) { 
		to_find = String_to_hash[i];
		index_of_letters = letters.find(to_find);
		if (index_of_letters == letters.npos) {
			return std::nullopt;
		}
		result = result * MULTIPLY + index_of_letters;
		i += 1;
	}
	return result;
}



std::string reverse_hash(uint64_t Code_to_hash, const char *letters){ // what happens in case of error
	int find_index;
	std::string result;

	while ( Code_to_hash  > 37 ) {
			find_index = Code_to_hash%37;
		if (find_index == 26) 
			result = result + "";
		if ( find_index > 26) 
			find_index = find_index%26;
		char hash_char = letters[find_index];
		result = result + hash_char;
		Code_to_hash = (Code_to_hash - find_index) / 37;
	}
	std::reverse(begin(result), end(result));
	return result;
}


//  amount of arguments  / pointer to array with all arguments
int main (int argc, char *argv[]) {
	if ( argc < 2) {
		std::cout << "Enter at least 1 Argument" << std::endl;
	}
	const char letters[] = "abcdefghijklmnopqrstuvwxyz ";

	std::cout << "Do you want to hash or reverse hash?" << std::endl;
	std::cout << "Type 'h' to hash or 'r' to reverse hash" << std::endl;
	char h = getchar();
	if (h == 'h') {
		if (auto hash = to_hash(argv[1], letters)) {  
				std::cout << "Your hash is: " << *hash << std::endl;
		return 1;
		}
		
		else {
			std::cout << "Your hash is invalid" << std::endl;
		return 0;
		}	
	}

	if (h == 'r') {  
		uint64_t argv_type_cast = (uint64_t) argv[1];
		std::cout << "Youre reversed hash is: " << reverse_hash(argv_type_cast, letters) << std::endl;
		return 1;
	}
	else {
		std::cout << "Wrong Input" << std::endl;
		return 0;
	}
}




// zero is false / 1 is true




// beginne mit der main ( high level ) und baue die grundstruktur auf
// die funktions signatur ist der vertrag mit dem user
// baue sie so auf dass man sie sofort versteht
// die mainfunktion sollte so aufgebaut sein, dass man die argumente ueber die kommando zeile 
//uebergeben kann
// teste die eingaben if (h) {  ( 0!= h )
    
//                          }
// deklariere jede Funktion so typ name (signatur)
// deklariere hier den rueckgabe typ
// 
//
//
// deklariere hier schonmal das return
// Konstanten sollten je nach scope kuerzer oder laenger sein Wenn der scop gross ist benutze laengere konstantennamen


// deklariere keine globalen variablen sondern schreibe sie in die int main(int argc, char const *argv[])
// verwende kein namespace std mehr damit du verstehst von wo welche funtkionen kommen
// lerne mit der tastatur umzuspringen
// bennen variablen so dass man deren funktion versteht