def is_bouncy(n):
    increasing = decreasing = False
    prev_digit = n % 10
    n //= 10
    while n > 0:
        current_digit = n % 10
        if current_digit < prev_digit:
            increasing = True
        if current_digit > prev_digit:
            decreasing = True
        if increasing and decreasing:
            return True
        prev_digit = current_digit
        n //= 10
    return False

def find_least_number_for_bouncy_ratio(target_ratio):
    bouncy_count = 0
    number = 0
    
    while True:
        number += 1
        if is_bouncy(number):
            bouncy_count += 1
        
        if (bouncy_count / number) >= target_ratio:
            return number

# 목표 비율: 99%
target_ratio = 0.99
result = find_least_number_for_bouncy_ratio(target_ratio)
print(f"The least number for which the proportion of bouncy numbers is exactly 99% is {result}.")
