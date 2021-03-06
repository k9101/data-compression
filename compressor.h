#ifndef __COMPRESSOR_H__
#define __COMPRESSOR_H__

#include <iostream>
#include <string>

using namespace std;

class Encode
{
    public:
        Encode() {};
        ~Encode() {};


        /*  Compress:
            ----------------------------------------------------
            Compress the source text into result.
            This function is responsible for allocating result.
            The caller is responsible for freeing result.
            Compress returns the length of the result. 
            ---------------------------------------------------- */
        unsigned int Compress( const string &source, unsigned char *& result );

    
        /*  Decompress:
            ----------------------------------------------------
            Decompress codedText with the given length into a
            string.  Returns the decoded text as a string.
            Assumes codedText is not null, length > 0.
            ---------------------------------------------------- */
        string Decompress( unsigned char * codedText, unsigned int length );

    
    private:

        /*  SetBit:
            ----------------------------------------------------
            Set the k-th bit of the unsigned char (data) to 1.
            Assumes data is initially 0.
            Examples:
            SetBit( 0, data ) --> data = 0000 0001
            SetBit( 1, data ) --> data = 0000 0010
            SetBit( 2, data ) --> data = 0000 0100
            ---------------------------------------------------- */
        void SetBit( unsigned int k, unsigned char * data )
        {
            (* data) |= ( 1 << k );
        } 
        
};

#endif