#pragma once
#include<exception>
class except : public std::exception
{
	private:
	    const char* string;
	public:
	  	except(const char* str)
	  	{
	   		string = str;
	   	}
	   	const char* what() const noexcept
	   	{
	   		return string;
	   	}
};
