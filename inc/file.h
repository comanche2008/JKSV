#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include <switch.h>
#include <dirent.h>

#include "data.h"

namespace fs
{
	//Mounts usr's save data for open. Returns false it fails
	bool mountSave(data::user& usr, data::titledata& open);

	//Recursively copies 'from' to 'to'
	void copyDirToDir(const std::string& from, const std::string& to);

	//Same as above, but commits data to 'dev' after every file is closed
	void copyDirToDirCommit(const std::string& from, const std::string& to, const std::string& dev);

	//Recursively deletes 'path'
	void delDir(const std::string& path);

	//Just retrieves a listing for _path and stores it in item vector
	class dirList
	{
		public:
			dirList(const std::string& _path);
			void reassign(const std::string& _path);
			void rescan();

			std::string getItem(int index);
			bool isDir(int index);
			unsigned getCount();

		private:
			DIR *d;
			struct dirent *ent;
			std::string path;
			std::vector<std::string> item;
	};
}

#endif // FILE_H