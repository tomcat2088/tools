#ifndef __VAR_LIST__H__
#define __VAR_LIST__H__

#include <map>
#include <string>

static std::map<std::string, double> var_list;

void set_var(std::string name,double val)
{
	var_list[name] = val;
}

double get_var(std::string name)
{
	return var_list[name];
}

#endif