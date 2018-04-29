 ///
 /// @file    Dictionary_unordered_unordered_map.cc
 /// @author  WildFiretobee(Dangerous@gmail.com)
 /// @date    2018-04-24 21:45:56
 ///

#include <string.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <time.h>

using std::cout;
using std::endl;
using std::unordered_map;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

class Dictionary
{
public:
	Dictionary()
	{	}

	void read(const string & filename)
	{
		ifstream ifs(filename);
		if(!ifs)
		{
			cout << "ifstream open error!" << endl;
			return;
		}

		string line;
		int cnt = 0;
		while(getline(ifs, line)) 
		{
			istringstream iss(line);
			string word;
	
			while(iss >> word)
			{
				if(isWord(word)){
					++cnt;
					processWord(word);
				}
			}
		}
		ifs.close();
		cout << cnt <<" words read over!" << endl;
	}

	void store(const string & filename)
	{
		ofstream ofs(filename);
		if(!ofs){
			cout << "ofstream open error!" << endl;
			return;
		}
		for(auto & record : _dict)
		{
			ofs << record.first << " " << record.second << "\n";
		}

		ofs.close();
	}
private:
	bool isWord(const string & word)
	{
		for(size_t idx = 0; idx != word.size(); ++idx)	
		{
			if(isdigit(word[idx]))
				return false;
		}
		return true;
	}

	void processWord(const string & word)
	{
		++_dict[word];
	}
private:
	unordered_map<string,int> _dict;
};
 
int main(void)
{
	Dictionary dictionary;
	time_t now,last;
	now = time(NULL);
	last = now;
	dictionary.read("The_Holy_Bible.txt");
	dictionary.store("dictionary.dat");
	last = time(NULL);
	cout << "总共花时为：" << (last-now)*pow(10,3) << "毫秒" << endl;
	return 0;
}
