def digit_sum(n):
    return sum(int(digit) for digit in str(n))

def find_digit_power_numbers(limit):
    results = []
    for base in range(2, 100):  # Reasonable base limit
        power = 2
        while True:
            num = base ** power
            if num < 10:
                power += 1
                continue
            if digit_sum(num) == base:
                results.append(num)
            if num > 10 ** 30:  # Avoid very large numbers
                break
            power += 1
    return sorted(results)

# Find the 30th number in the sequence
sequence = find_digit_power_numbers(30)
a_30 = sequence[29]  # Index 29 because Python is zero-indexed
print(f"The 30th term (a_30) is: {a_30}")

