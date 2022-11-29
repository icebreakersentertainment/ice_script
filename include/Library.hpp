#ifndef ICE_SCRIPT_LIBRARY_HPP
#define ICE_SCRIPT_LIBRARY_HPP

#include <string>

#include "Context.hpp"

#include "exceptions/FileNotFoundException.hpp"

namespace ice_script
{

class Path
{
public:
    operator std::string() const
    {
        return path_;
    }
    
private:
    std::string path_;    
};

template <typename FunctionType>
class Function
{
public:

private:
    FunctionType function_;
};

class Library
{
public:
    Library(Context context) : context_(std::move(context))
    {}
    
    void add(const std::string& path)
    {
        if (!context_.fileSystem()->exists(path))
        {
            throw FileNotFoundException( std::string("Unable to mount file '") + path + "' - file does not exist.");
        }
    }
    
    void compile()
    {
        
    }
    
    void recompile()
    {
        
    }
    
    template <typename FunctionType>
    Function<FunctionType> findFunction(const std::string& name)
    {
        void* ptr = nullptr;
        
        return {reinterpret_cast<FunctionType>(ptr)};
    }
    
private:
    Context context_;
};

}

#endif /* ICE_SCRIPT_LIBRARY_HPP */
