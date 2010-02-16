/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2003-2009 Erwin Coumans  http://bulletphysics.org

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef BT_SERIALIZER_H
#define BT_SERIALIZER_H

#include "btScalar.h" // has definitions like SIMD_FORCE_INLINE
#include "btStackAlloc.h"

class btChunk
{
public:
	int		m_chunkCode;
	int		m_length;
	void	*m_oldPtr;
	int		m_dna_nr;
	int		m_number;
};


///Allow to serialize data in a chunk format
class btSerializer
{
	public:

		virtual ~btSerializer() {}

		virtual	btChunk*	allocate(size_t size,int numElements) = 0;

};


#define BT_HEADER_LENGTH 12


class btDefaultSerializer
{
public:

	btAlignedObjectArray<char*>			mTypes;
	btAlignedObjectArray<short*>			mStructs;
	btAlignedObjectArray<short>			mTlens;
	btHashMap<btHashInt, int>			mStructReverse;
	btHashMap<btHashString,int>	mTypeLookup;

	btAlignedObjectArray<btChunk*>	m_chunkPtrs;

	int					m_totalSize;
	unsigned char*		m_buffer;
	int					m_bufferPointer;
	
	
	

	void*		m_dna;
	int					m_dnaLength;


		btDefaultSerializer(int totalSize)
			:m_totalSize(totalSize),
			m_bufferPointer(0)
//			m_dna(0),
//			m_dnaLength(0)
		{
			m_buffer = (unsigned char*)btAlignedAlloc(16,totalSize);
			m_bufferPointer += BT_HEADER_LENGTH;

			memcpy(m_buffer, "BULLET ", 7);
			int endian= 1;
			endian= ((char*)&endian)[0];

			if (endian)
			{
				m_buffer[7] = '_';
			} else
			{
				m_buffer[7] = '-';
			}
			if (sizeof(void*)==8)
			{
				m_buffer[8]='V';
			} else
			{
				m_buffer[8]='v';
			}

			m_buffer[9] = '2';
			m_buffer[10] = '7';
			m_buffer[11] = '5';

			

		}

		virtual ~btDefaultSerializer() 
		{
			btAlignedFree(m_buffer);
		}

		int getReverseType(const char *type) const
		{

			btHashString key(type);
			const int* valuePtr = mTypeLookup.find(key);
			if (valuePtr)
				return *valuePtr;
			
			return -1;
		}

		void	writeDNA()
		{
			unsigned char* dnaTarget = m_buffer+m_bufferPointer;
			memcpy(dnaTarget,m_dna,m_dnaLength);
			m_bufferPointer += m_dnaLength;
		}

		virtual	btChunk*	allocate(size_t size, int numElements)
		{

			unsigned char* ptr = m_buffer+m_bufferPointer;
			m_bufferPointer += size*numElements+sizeof(btChunk);

			unsigned char* data = ptr + sizeof(btChunk);
			
			btChunk* chunk = (btChunk*)ptr;
			chunk->m_chunkCode = 0;
			chunk->m_oldPtr = data;
			chunk->m_length = size;
			chunk->m_number = numElements;
			
			m_chunkPtrs.push_back(chunk);

			return chunk;
		}


		void initDNA(const char* bdna,int dnalen)
		{

			m_dna = btAlignedAlloc(dnalen,16);
			memcpy(m_dna,bdna,dnalen);
			m_dnaLength = dnalen;

			int *intPtr=0;short *shtPtr=0;
			char *cp = 0;int dataLen =0;long nr=0;
			intPtr = (int*)bdna;

			/*
				SDNA (4 bytes) (magic number)
				NAME (4 bytes)
				<nr> (4 bytes) amount of names (int)
				<string>
				<string>
			*/

			if (strncmp((const char*)bdna, "SDNA", 4)==0)
			{
				// skip ++ NAME
				intPtr++; intPtr++;
			}

			// Parse names
			
			dataLen = *intPtr;
			intPtr++;

			cp = (char*)intPtr;
			for (int i=0; i<dataLen; i++)
			{
				
				while (*cp)cp++;
				cp++;
			}
			{
				nr= (long)cp;
				long mask=3;
				nr= ((nr+3)&~3)-nr;
				while (nr--)
				{
					cp++;
				}
			}

			/*
				TYPE (4 bytes)
				<nr> amount of types (int)
				<string>
				<string>
			*/

			intPtr = (int*)cp;
			assert(strncmp(cp, "TYPE", 4)==0); intPtr++;

			dataLen = *intPtr;
			intPtr++;

			cp = (char*)intPtr;
			for (int i=0; i<dataLen; i++)
			{
				mTypes.push_back(cp);
				while (*cp)cp++;
				cp++;
			}

		{
				nr= (long)cp;
				long mask=3;
				nr= ((nr+3)&~3)-nr;
				while (nr--)
				{
					cp++;
				}
			}


			/*
				TLEN (4 bytes)
				<len> (short) the lengths of types
				<len>
			*/

			// Parse type lens
			intPtr = (int*)cp;
			assert(strncmp(cp, "TLEN", 4)==0); intPtr++;

			dataLen = (int)mTypes.size();

			shtPtr = (short*)intPtr;
			for (int i=0; i<dataLen; i++, shtPtr++)
			{
				mTlens.push_back(shtPtr[0]);
			}

			if (dataLen & 1) shtPtr++;

			/*
				STRC (4 bytes)
				<nr> amount of structs (int)
				<typenr>
				<nr_of_elems>
				<typenr>
				<namenr>
				<typenr>
				<namenr>
			*/

			intPtr = (int*)shtPtr;
			cp = (char*)intPtr;
			assert(strncmp(cp, "STRC", 4)==0); intPtr++;

			dataLen = *intPtr;
			intPtr++;


			shtPtr = (short*)intPtr;
			for (int i=0; i<dataLen; i++)
			{
				mStructs.push_back (shtPtr);
				shtPtr+= (2*shtPtr[1])+2;
			}

			// build reverse lookups
			for (int i=0; i<(int)mStructs.size(); i++)
			{
				short *strc = mStructs.at(i);
				mStructReverse.insert(strc[0], i);
				mTypeLookup.insert(btHashString(mTypes[strc[0]]),i);
			}
		}

};


#endif //BT_SERIALIZER_H

