#include "GArgument.h"

#include <helpers/logger.h>

#include <iostream>

std::vector<GArgument> GArgument::read_garguments(TokenStream &token_stream)
{
    std::vector<GArgument> arguments;
    TokenValue token = token_stream.next();

    if (token.token != GToken::LeftParenthesis)
    {
        Logger::log("GArguments expected left parenthesis got '" + token.value + "'",
                    LogLevel::Error, token_stream.get_filename(), token.line);
        exit(1);
    }

    while (!token_stream.empty())
    {
        if (token.token == GToken::RightParenthesis)
        {
            break;
        }
        
        if (arguments.size() > 0)
        {
            if (token.token != GToken::Comma)
            {
                Logger::log("GArguments expected ',' got '" + token.value + "'", LogLevel::Error,
                            token_stream.get_filename(), token.line);
                exit(1);
            }
            token = token_stream.next();
        }
        else
            token = token_stream.next();

        if (token.token == GToken::RightParenthesis)
        {
            break;
        }

        GArgument gArgument = {};
        
        if (token.token == GToken::Const)
        {
            token = token_stream.next();
            gArgument.isConst = true;
        }

        if (token.token != GToken::Identifier)
        {
            Logger::log("GArguments expected identifier for type, got '" + token.value + "'",
                        LogLevel::Error, token_stream.get_filename(), token.line);
            exit(1);
        }
        gArgument.raw_type = token.value;

        token = token_stream.next();
        if (token.token == GToken::Asterisk)
        {
            gArgument.variantType = GType::NodePathToRaw;
            gArgument.isPointer = true;
            token = token_stream.next();
        }
        else
        {
            gArgument.variantType = TypeStringToGType(gArgument.raw_type);
        }

        if (token.token != GToken::Identifier)
        {
            Logger::log("GArguments expected identifier after type, got '" + token.value + "'",
                        LogLevel::Error, token_stream.get_filename(), token.line);
            exit(1);
        }
        gArgument.name = token.value;

        token = token_stream.next();
        
        if (token.token == GToken::Equal)
        {
            token = token_stream.next();
            if (token.token == GToken::Comma && token.token == GToken::RightParenthesis)
            {
                Logger::log("GArguments expected value after =, got '" + token.value + "'",
                        LogLevel::Error, token_stream.get_filename(), token.line);
                exit(1);
            }
            
            gArgument.value = token.value;
            
            token = token_stream.next();
        }
        
        arguments.push_back(gArgument);
    }

    return arguments;
}