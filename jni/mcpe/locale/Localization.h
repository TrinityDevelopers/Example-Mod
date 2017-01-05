#pragma once

#include <string>

class ResourcePackManager;

class Localization {
public:
	Localization(const std::string&, ResourcePackManager&);
	void _appendTranslations(const std::string&);
	void _load(const std::string&);
	std::string getFullLanguageCode() const;
};