#pragma once
#include "Binary_Search_Tree.h"
#include <fstream>
#include <string>
#include <map>

class Morse_Code_Tree : public Binary_Search_Tree<char>
{
private:
	std::map<char, std::string> morseCodes;
public:
	Morse_Code_Tree(std::string fileName)
	{
		this->root = new BTNode<char>(' ', NULL, NULL, "");
		std::ifstream fin(fileName);
		std::vector<std::string> codes;

		std::string line;

		while (std::getline(fin, line)) {
			codes.push_back(line);
		}

		while (!codes.empty()) {
			std::sort(codes.begin(), codes.end(), [] (std::string& left, std::string& right) { return left.length() < right.length(); });
			this->insert(root, codes[0][0], codes[0].substr(1));
			morseCodes[codes[0].substr(1)] = codes[0][0];
			codes.erase(codes.begin());
		}
	}

	virtual bool insert(BTNode<char>*& local_root, const char item, const std::string morseCode)
	{
		if (local_root == NULL) {
			local_root = new BTNode<char>(item, NULL, NULL, morseCode);
			return true;
		} else {
			if (BTNode<char>(item, NULL, NULL, morseCode) < *local_root)
				return insert(local_root->left, item, morseCode);
	 		else if (*local_root < BTNode<char>(item, NULL, NULL, morseCode))
				return insert(local_root->right, item, morseCode);
			else
				return false;
		}
	}

	const std::string find(BTNode<char>* local_root, const std::string target) const
	{
		if (local_root == NULL)
			return NULL;
		if (target < local_root->morseCode)
			return find(local_root->left, target);
		else if (local_root->morseCode < target)
			return find(local_root->right, target);
		else
			return local_root->morseCode;
	}
};