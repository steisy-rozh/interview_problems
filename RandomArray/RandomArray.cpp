// RandomArray.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include <vector>
#include <utility>
#include <unordered_set>


namespace random_array
{
	template<typename TInput>
	class solution {
	private:
		size_t inline get_random_index(size_t size) const
		{
			return std::rand() % size;
		}
	public:
		std::vector<TInput> create_random_array(const std::vector<TInput>& source, const size_t& length) const
		{
			std::vector<TInput> output;
			output.reserve(length);

			if (length <= source.size())
			{
				std::vector<TInput> v_shallow_copy_source(source);
				size_t size = source.size();
				size_t l = length;

				do
				{
					size_t random_index = this->get_random_index(size--);
					TInput random_number = v_shallow_copy_source.at(random_index);
					output.push_back(random_number);
					std::swap(v_shallow_copy_source[random_index], v_shallow_copy_source[size]);
				} while (--l > 0);
			}
			else
			{
				std::unordered_set<TInput> s_unique_copy_source(source.begin(), source.end());

				size_t count = length;
				do 
				{
					size_t random_index = this->get_random_index(s_unique_copy_source.size());
					TInput random_number = *std::next(s_unique_copy_source.begin(), random_index);
					output.push_back(random_number);
				} while (--count > 0);
			}

			return output;
		}
	};
}

