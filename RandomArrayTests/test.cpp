#include "pch.h"
#include "utility.h"
#include "../RandomArray/RandomArray.cpp"

namespace random_array {
	TEST(array_length, m_gt_n) 
	{
		random_array::solution<long long> solution;

		std::vector<long long> source({ 1, 2, 3, 4, 5, 6 });
		const unsigned int length = 100;

		std::vector<long long> actual = solution.create_random_array(source, length);

		EXPECT_EQ(actual.size(), length);
	}

	TEST(array_length, m_le_n)
	{
		random_array::solution<unsigned short> solution;

		const size_t size = 100;
		std::vector<unsigned short> source;
		source.reserve(size);

		for (unsigned int i = 0; i < size; ++i)
		{
			source.push_back(i);
		}

		const unsigned int length = 35;

		std::vector<unsigned short> actual = solution.create_random_array(source, length);

		EXPECT_EQ(actual.size(), length);
	}

	TEST(randomness, m_gt_n)
	{
		random_array::solution<unsigned short> solution;

		std::vector<unsigned short> source({ 1, 2, 3, 4, 5, 6 });
		const unsigned int length = 100;

		std::vector<unsigned short> actual = solution.create_random_array(source, length);

		tests_utility::randomness<unsigned short> random_test;

		double p_value = random_test.person_chi_squared_value(actual);

		EXPECT_GT(p_value, random_test.chi_square_threshold);
	}

	TEST(randomness, m_le_n)
	{
		random_array::solution<unsigned short> solution;

		const size_t size = 100;
		std::vector<unsigned short> source;
		source.reserve(size);

		for (unsigned int i = 0; i < size; ++i)
		{
			source.push_back(i);
		}

		const unsigned int length = 35;

		std::vector<unsigned short> actual = solution.create_random_array(source, length);

		tests_utility::randomness<unsigned short> random_test;

		double p_value = random_test.person_chi_squared_value(actual);

		EXPECT_GT(p_value, random_test.chi_square_threshold);
	}
}
