#pragma once
#include <cstdint>

namespace rage
{
	union scrValue
	{
		int Int;
		unsigned int Uns;
		float Float;
		LPCSTR String;
		scrValue* Reference;
		uint64_t Any;
		bool operator==(const scrValue& val) {
			return Int == val.Int;
		}
	};
}