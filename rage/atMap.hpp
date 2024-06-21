#pragma once
#include <rage/atArray.hpp>

namespace rage
{
	/*template<class TKey, class TValue>
	class atMap
	{
	public:

	private:
		struct Entry
		{
			TKey key;
			TValue value;
			Entry* next;
		};

		Entry** Buckets;
		uint32_t NumBuckets;
		uint32_t padding;
		uint32_t NumEntries;
		int8_t field_C[3];
		bool IsResizable;
	};
	static_assert(sizeof(rage::atMap<std::uint32_t, std::uint32_t>) == 24, "");*/

	template<class TKey, class TValue>
	class atBinaryMap
	{
	public:
		std::uint16_t count() const
		{
			return Pairs.count();
		}

		bool sorted() const
		{
			return IsSorted;
		}

		TValue& operator[](TKey key) const
		{
			for (auto pair : Pairs)
				if (pair.Key == key)
					return pair.Value;

			return 0;
		}

	private:
		struct DataPair
		{
			TKey Key;
			TValue Value;
		};

		bool IsSorted;
		atArray<DataPair> Pairs;
	};
	static_assert(sizeof(rage::atBinaryMap<std::uint32_t, std::uint32_t>) == 24, "");
}