#pragma once

#include <vector>
#include <numeric>
#include <cmath>

namespace tests_utility {
	template<typename TSource>
	class randomness {
	public:
		const double chi_square_threshold = 8.0;
		double person_chi_squared_value(const std::vector<TSource>& source) const
		{
			const double expected_value = 1.0;

			std::vector<double> diff(source.size());

			auto p_value_func = [expected_value](TSource input)
			{
				return (std::pow(static_cast<double>(input) - expected_value, 2.0) / expected_value);
			};

			std::transform(source.begin(), source.end(), diff.begin(), p_value_func);
			double p_value = std::accumulate(diff.begin(), diff.end(), 0.0);

			return p_value;
		}
	};
}