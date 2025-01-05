import math

# Function to calculate binomial coefficient
def binomial_coefficient(n, k):
    return math.comb(n, k)

# Calculate increasing numbers (binomial coefficient: (k+9) choose 9)
increasing_numbers = binomial_coefficient(100 + 9, 9)

# Calculate decreasing numbers (binomial coefficient: (k+10) choose 10) - 1
decreasing_numbers = binomial_coefficient(100 + 10, 10) - 1

# Calculate duplicated numbers (all digits the same)
duplicated_numbers = 10 * 100

# Subtract 1 for adjustment
non_bouncy_numbers = increasing_numbers + decreasing_numbers - duplicated_numbers - 1
non_bouncy_numbers
