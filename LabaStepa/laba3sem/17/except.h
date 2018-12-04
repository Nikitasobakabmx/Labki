<<<<<<< HEAD
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
=======
class except
{
    public:
        char* string;
    except(char* str):string(str){};
};
>>>>>>> a21eea7f6e198389ea6cc655b5462626ec06f9de
