#ifndef HEADER_CONFIG_FILE
#define HEADER_CONFIG_FILE

class ConfigFile
{



	ConfigFile();
public:


	static ConfigFile Create(char* path);
	static ConfigFile Open(char* path);
	static bool Exists(char* path);


	void AddEntry(const char * name, const char* data);
	

	char* GetValue(char * name);

	char*& operator[](char* name);

	void Save();
	void SaveAs(char* path);
	void Dispose();
};

#endif // !HEADER_CONFIG_FILE
