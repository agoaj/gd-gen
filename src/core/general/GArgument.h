#pragma once

#include <core/general/GType.h>
#include <lexer/lexer.h>

#include <queue>
#include <string>
#include <vector>
#include <format>

struct GArgument
{
    GType variantType = GType::Invalid;
    std::string raw_type;
    std::string name;
    std::string value;
    
    bool isPointer = false;
    bool isConst = false;
    
    //retures raw_type with const/ptr info
    std::string get_full_type() const { return std::format("{} {}{}", 
        isConst? "const" : "", raw_type, isPointer ? "*" : ""); } 

    static std::vector<GArgument> read_garguments(TokenStream &token_stream);
};