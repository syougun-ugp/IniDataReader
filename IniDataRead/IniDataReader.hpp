#pragma once
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/optional.hpp>
#include <string>

class IniDataReader
{
public:
	IniDataReader(const std::string& path):
		file_path(path)
	{
		boost::property_tree::read_ini(path, pt);
	}

	template<typename T>
	T Get(const std::string& path)
	{
		if (boost::optional<T> value = pt.get_optional<T>(path))
		{
			return value.get();
		}

		return 0;
	}
private:

	template<typename TARGET, typename DATA>
	TARGET Cast(const DATA& data)
	{
		std::stringstream string;
		TARGET target;
		string << data;
		string >> target;
		return target;
	}

	boost::property_tree::ptree pt;
	std::string file_path;
};

