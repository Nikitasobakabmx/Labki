#include <exception>
class except : std::exception
{
    private:
        char* string;
    public:
        except(char* str);
        const char* what() const noexcept override;
        ~except();
};
